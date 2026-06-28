// WAP to Create Bank Account System
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int account_number;
    char name[50];
    double balance;
};

struct Account bank_db[MAX_ACCOUNTS];
int account_count = 0;


// 1. Function to create a new bank account
void createAccount() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("\nError: Bank database capacity full!\n");
        return;
    }

    struct Account acc;
    printf("\nEnter New Account Number: ");
    scanf("%d", &acc.account_number);

    // Enforce Unique Account Number constraints
    for (int i = 0; i < account_count; i++) {
        if (bank_db[i].account_number == acc.account_number) {
            printf("Error: Account Number %d already exists!\n", acc.account_number);
            return;
        }
    }

    printf("Enter Account Holder Name (No spaces): ");
    scanf("%s", acc.name);
    
    printf("Enter Initial Deposit Amount ($): ");
    if (scanf("%lf", &acc.balance) != 1 || acc.balance < 0) {
        printf("Invalid initial amount. Account creation failed.\n");
        while (getchar() != '\n');
        return;
    }

    // Commit to system array
    bank_db[account_count] = acc;
    account_count++;
    printf("\nAccount created successfully for %s!\n", acc.name);
}

// 2. Function to deposit money into an account
void depositMoney() {
    if (account_count == 0) {
        printf("\nDatabase is empty. No accounts found.\n");
        return;
    }

    int target_acc;
    double amount;
    printf("\nEnter Account Number for Deposit: ");
    scanf("%d", &target_acc);

    for (int i = 0; i < account_count; i++) {
        if (bank_db[i].account_number == target_acc) {
            printf("Current Balance: $%.2f\n", bank_db[i].balance);
            printf("Enter Amount to Deposit: $");
            if (scanf("%lf", &amount) != 1 || amount <= 0) {
                printf("Invalid amount. Transaction cancelled.\n");
                while (getchar() != '\n');
            } else {
                bank_db[i].balance += amount;
                printf("\n$%.2f deposited successfully.\n", amount);
                printf("Updated Balance: $%.2f\n", bank_db[i].balance);
            }
            return;
        }
    }
    printf("Error: Account Number %d not found.\n", target_acc);
}

// 3. Function to withdraw money from an account
void withdrawMoney() {
    if (account_count == 0) {
        printf("\nDatabase is empty. No accounts found.\n");
        return;
    }

    int target_acc;
    double amount;
    printf("\nEnter Account Number for Withdrawal: ");
    scanf("%d", &target_acc);

    for (int i = 0; i < account_count; i++) {
        if (bank_db[i].account_number == target_acc) {
            printf("Current Balance: $%.2f\n", bank_db[i].balance);
            printf("Enter Amount to Withdraw: $");
            if (scanf("%lf", &amount) != 1 || amount <= 0) {
                printf("Invalid amount. Transaction cancelled.\n");
                while (getchar() != '\n');
            } else if (amount > bank_db[i].balance) {
                printf("Transaction Failed: Insufficient funds!\n");
            } else {
                bank_db[i].balance -= amount;
                printf("\n$%.2f withdrawn successfully.\n", amount);
                printf("Updated Balance: $%.2f\n", bank_db[i].balance);
            }
            return;
        }
    }
    printf("Error: Account Number %d not found.\n", target_acc);
}

// 4. Function to display distinct account information
void displayAccount() {
    if (account_count == 0) {
        printf("\nDatabase is empty. No accounts found.\n");
        return;
    }

    int target_acc;
    printf("\nEnter Account Number to check details: ");
    scanf("%d", &target_acc);

    for (int i = 0; i < account_count; i++) {
        if (bank_db[i].account_number == target_acc) {
            printf("\n--- Account Information ---\n");
            printf("Account Number: %d\n", bank_db[i].account_number);
            printf("Holder Name   : %s\n", bank_db[i].name);
            printf("Current Balance: $%.2f\n", bank_db[i].balance);
            return;
        }
    }
    printf("Error: Account Number %d not found.\n", target_acc);
}

int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("       BANK MANAGEMENT SYSTEM        \n");
        printf("=====================================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccount(); break;
            case 5: printf("\nThank you for banking with us. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Select an option between 1 and 5.\n");
        }
    }
    return 0;
}
