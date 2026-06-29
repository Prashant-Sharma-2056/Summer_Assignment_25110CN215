// WAP to Create mini employee management system
#include <stdio.h>

#define MAX_EMPLOYEES 100

// Structure to store Employee details
struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

// Global Array Database and Counter
struct Employee employees[MAX_EMPLOYEES];
int emp_count = 0;


// 1. Function to add an employee record
void addEmployee() {
    if (emp_count >= MAX_EMPLOYEES) {
        printf("\nError: System database capacity full!\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    // Enforce Unique ID constraints
    for (int i = 0; i < emp_count; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID %d already exists!\n", emp.id);
            return;
        }
    }

    printf("Enter Name (No spaces): ");
    scanf("%s", emp.name);
    
    printf("Enter Department: ");
    scanf("%s", emp.department);
    
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Commit to persistent session array
    employees[emp_count] = emp;
    emp_count++;
    printf("\nRecord created successfully!\n");
}

// 2. Function to display all corporate assets
void displayAll() {
    if (emp_count == 0) {
        printf("\nNo database records found.\n");
        return;
    }

    printf("\n----------------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-15s\n", "ID", "Name", "Department", "Salary");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < emp_count; i++) {
        printf("%-10d %-20s %-20s $%-14.2f\n", 
               employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
    printf("----------------------------------------------------------------------\n");
}

// 3. Function to query database using linear search
void searchEmployee() {
    if (emp_count == 0) {
        printf("\nDatabase is empty.\n");
        return;
    }

    int target_id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &target_id);

    for (int i = 0; i < emp_count; i++) {
        if (employees[i].id == target_id) {
            printf("\n--- Record Found ---\n");
            printf("ID:         %d\n", employees[i].id);
            printf("Name:       %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Salary:     $%.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", target_id);
}

// 4. Function to overwrite dynamic variables
void updateEmployee() {
    if (emp_count == 0) {
        printf("\nDatabase is empty.\n");
        return;
    }

    int target_id;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &target_id);

    for (int i = 0; i < emp_count; i++) {
        if (employees[i].id == target_id) {
            printf("\nCurrent details: Name: %s | Dept: %s | Salary: %.2f\n", 
                   employees[i].name, employees[i].department, employees[i].salary);
            
            printf("\nEnter New Department: ");
            scanf("%s", employees[i].department);
            printf("Enter New Salary: ");
            scanf("%f", &employees[i].salary);
            
            printf("\nEmployee record updated successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", target_id);
}

// 5. Function to delete a record using structural shifting
void deleteEmployee() {
    if (emp_count == 0) {
        printf("\nDatabase empty. Nothing to delete.\n");
        return;
    }

    int target_id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &target_id);

    for (int i = 0; i < emp_count; i++) {
        if (employees[i].id == target_id) {
            // Shift remaining records to fill the void
            for (int j = i; j < emp_count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            emp_count--; // Collapse active index size
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", target_id);
}


int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("     EMPLOYEE MANAGEMENT SYSTEM      \n");
        printf("=====================================\n");
        printf("1. Add New Employee\n");
        printf("2. Display All Records\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee Details\n");
        printf("5. Delete Employee Record\n");
        printf("6. Exit System\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("\nExiting system. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Select an option between 1 and 6.\n");
        }
    }
    return 0;
}
