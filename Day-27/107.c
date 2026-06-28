// WAP to Create Salary Management System
#include <stdio.h>

#define MAX_EMPLOYEES 50

// Structure to hold comprehensive salary profiles
struct SalarySlip {
    int emp_id;
    char name[50];
    double basic_salary;
    double hra;
    double da;
    double pf;
    double gross_salary;
    double net_salary;
};

// Global database variables
struct SalarySlip system_db[MAX_EMPLOYEES];
int total_records = 0;


// Function to calculate allowances and add an employee record
void generateSalarySlip() {
    if (total_records >= MAX_EMPLOYEES) {
        printf("\nPayroll limits reached. Cannot process more entries.\n");
        return;
    }

    struct SalarySlip emp;

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.emp_id);

    // Ensure ID unique lookup constraints
    for (int i = 0; i < total_records; i++) {
        if (system_db[i].emp_id == emp.emp_id) {
            printf("Error: Transaction failed. ID %d already possesses an active ledger.\n", emp.emp_id);
            return;
        }
    }

    printf("Enter Employee Name (No spaces): ");
    scanf("%s", emp.name);

    printf("Enter Monthly Basic Salary ($): ");
    if (scanf("%lf", &emp.basic_salary) != 1 || emp.basic_salary <= 0) {
        printf("Error: Invalid Base Compensation Value.\n");
        while (getchar() != '\n');
        return;
    }

    // Mathematical Breakdown of Allowances and Deductions
    emp.hra = 0.20 * emp.basic_salary; // 20% HRA
    emp.da = 0.50 * emp.basic_salary;  // 50% DA
    emp.pf = 0.12 * emp.basic_salary;  // 12% PF Deduction

    // Gross = Basic + HRA + DA
    emp.gross_salary = emp.basic_salary + emp.hra + emp.da;
    
    // Net = Gross - PF
    emp.net_salary = emp.gross_salary - emp.pf;

    // Commit ledger block to database storage array
    system_db[total_records] = emp;
    total_records++;

    printf("\nSuccess: Financial structures compiled for %s!\n", emp.name);
}

// Function to print all records in a ledger grid format
void displayPayroll() {
    if (total_records == 0) {
        printf("\nPayroll ledger empty. No items to display.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("%-8s %-15s %-12s %-10s %-10s %-10s %-12s %-12s\n", 
           "ID", "Name", "Basic", "HRA", "DA", "PF (-)", "Gross", "Net Pay");
    printf("--------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < total_records; i++) {
        printf("%-8d %-15s %-12.2f %-10.2f %-10.2f %-10.2f %-12.2f %-12.2f\n",
               system_db[i].emp_id, system_db[i].name, system_db[i].basic_salary,
               system_db[i].hra, system_db[i].da, system_db[i].pf,
               system_db[i].gross_salary, system_db[i].net_salary);
    }
    printf("--------------------------------------------------------------------------------------------------\n");
}

// Function to pull up a distinct individual pay slip card
void queryByEmployee() {
    if (total_records == 0) {
        printf("\nNo structural records compiled yet.\n");
        return;
    }

    int target_id;
    printf("\nEnter Employee ID to look up: ");
    scanf("%d", &target_id);

    for (int i = 0; i < total_records; i++) {
        if (system_db[i].emp_id == target_id) {
            printf("\n=========================================\n");
            printf("          OFFICIAL SALARY SLIP           \n");
            printf("=========================================\n");
            printf("Employee ID   : %d\n", system_db[i].emp_id);
            printf("Employee Name : %s\n", system_db[i].name);
            printf("-----------------------------------------\n");
            printf("Earnings:\n");
            printf("  Basic Salary: $%.2f\n", system_db[i].basic_salary);
            printf("  HRA Allowance: $%.2f\n", system_db[i].hra);
            printf("  DA Allowance : $%.2f\n", system_db[i].da);
            printf("  GROSS SALARY : $%.2f\n", system_db[i].gross_salary);
            printf("-----------------------------------------\n");
            printf("Deductions:\n");
            printf("  Provident Fund (PF): $%.2f\n", system_db[i].pf);
            printf("-----------------------------------------\n");
            printf("  NET TAKE-HOME PAY  : $%.2f\n", system_db[i].net_salary);
            printf("=========================================\n");
            return;
        }
    }
    printf("Record Search Error: Employee ID %d not found.\n", target_id);
}

int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("       SALARY MANAGEMENT SYSTEM      \n");
        printf("=====================================\n");
        printf("1. Generate New Employee Salary Slip\n");
        printf("2. Display Consolidated Payroll Ledger\n");
        printf("3. Search & Print Individual Pay Slip\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection! Input integer value.\n");
            while (getchar() != '\n'); // Flush input buffer
            continue;
        }

        switch (choice) {
            case 1: generateSalarySlip(); break;
            case 2: displayPayroll(); break;
            case 3: queryByEmployee(); break;
            case 4: printf("\nClosing Financial Portal. Goodbye!\n"); return 0;
            default: printf("Invalid option. Please pick a menu item between 1 and 4.\n");
        }
    }
    return 0;
}


