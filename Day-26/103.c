// WAP to Create ATM Simulation
#include <stdio.h>

int main() {
    double balance = 5000.00; 
    int choice;
    double amount;

    printf("=== Welcome to the Automated Teller Machine (ATM) ===\n");

    while (1) {
        printf("\n--- ATM Main Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
        }

        switch (choice) {
            case 1:
                // Check Balance
                printf("\nYour current balance is: $%.2f\n", balance);
                break;

            case 2:
                // Deposit Money
                printf("\nEnter the amount to deposit: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount. Deposit failed.\n");
                    while (getchar() != '\n');
                } else {
                    balance += amount;
                    printf("$%.2f successfully deposited.\n", amount);
                    printf("New balance: $%.2f\n", balance);
                }
                break;

            case 3:
                // Withdraw Money
                printf("\nEnter the amount to withdraw: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount. Withdrawal failed.\n");
                    while (getchar() != '\n');
                } else if (amount > balance) {
                    printf("Insufficient funds! Your current balance is $%.2f\n", balance);
                } else {
                    balance -= amount;
                    printf("$%.2f successfully withdrawn.\n", amount);
                    printf("Remaining balance: $%.2f\n", balance);
                }
                break;

            case 4:
                // Exit
                printf("\nThank you for using our ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please pick an option from 1 to 4.\n");
        }
    }

    return 0;
}