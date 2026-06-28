// WAP to Create Student Record Management System
#include <stdio.h>

#define MAX_STUDENTS 100

// Structure to store student details
struct Student {
    int roll_no;
    char name[50];
    float marks;
};

// Global array and counter to track records
struct Student records[MAX_STUDENTS];
int student_count = 0;


// Function to add a new student record
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("\nDatabase Full! Cannot add more records.\n");
        return;
    }

    struct Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);

    // Check if the roll number already exists
    for (int i = 0; i < student_count; i++) {
        if (records[i].roll_no == s.roll_no) {
            printf("Error: A student with Roll Number %d already exists!\n", s.roll_no);
            return;
        }
    }

    printf("Enter Name (No spaces): ");
    scanf("%s", s.name);
    
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    // Save to database array
    records[student_count] = s;
    student_count++;
    printf("Record added successfully!\n");
}

// Function to display all student records
void displayAll() {
    if (student_count == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("-------------------------------------------------\n");
    
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-25s %-10.2f\n", records[i].roll_no, records[i].name, records[i].marks);
    }
    printf("-------------------------------------------------\n");
}

// Function to search for a student by roll number
void searchStudent() {
    if (student_count == 0) {
        printf("\nDatabase empty. Nothing to search.\n");
        return;
    }

    int target_roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &target_roll);

    for (int i = 0; i < student_count; i++) {
        if (records[i].roll_no == target_roll) {
            printf("\nRecord Found!\n");
            printf("Roll Number: %d\n", records[i].roll_no);
            printf("Name:        %s\n", records[i].name);
            printf("Marks:       %.2f\n", records[i].marks);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", target_roll);
}


int main() {
    int choice;

    while (1) {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll No.\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: printf("\nExiting system. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}
