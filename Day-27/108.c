// WAP to Create Marksheet Generation System
#include <stdio.h>

#define MAX_STUDENTS 50

// Structure to store subject marks and calculations
struct Marksheet {
    int roll_no;
    char name[50];
    float marks[5]; // Array for 5 subjects
    float total;
    float percentage;
    char grade;
};

// Global Array Database and Counter
struct Marksheet database[MAX_STUDENTS];
int student_count = 0;


// Helper function to return Grade based on percentage bounds
char calculateGrade(float pct) {
    if (pct >= 90) return 'A';
    else if (pct >= 80) return 'B';
    else if (pct >= 70) return 'C';
    else if (pct >= 60) return 'D';
    else if (pct >= 40) return 'E';
    else return 'F'; // Fail condition
}

// 1. Function to accept raw marks and run processing loops
void generateMarksheet() {
    if (student_count >= MAX_STUDENTS) {
        printf("\nError: System database capacity reached.\n");
        return;
    }

    struct Marksheet stu;
    stu.total = 0; // Clear accumulator

    printf("\nEnter Student Roll Number: ");
    scanf("%d", &stu.roll_no);

    // Roll number uniqueness check
    for (int i = 0; i < student_count; i++) {
        if (database[i].roll_no == stu.roll_no) {
            printf("Error: A marksheet for Roll Number %d already exists!\n", stu.roll_no);
            return;
        }
    }

    printf("Enter Student Name (No spaces): ");
    scanf("%s", stu.name);

    printf("\nEnter marks out of 100 for 5 core subjects:\n");
    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("  Subject %d marks: ", i + 1);
            if (scanf("%f", &stu.marks[i]) == 1 && stu.marks[i] >= 0 && stu.marks[i] <= 100) {
                stu.total += stu.marks[i];
                break; // Valid input received, advance loop
            }
            printf("  Invalid input! Marks must be a number between 0 and 100.\n");
            while (getchar() != '\n'); // Purge erroneous string stream
        }
    }

    // Processing academic arithmetic metrics
    stu.percentage = stu.total / 5.0;
    stu.grade = calculateGrade(stu.percentage);

    // Save current block into permanent indexing space
    database[student_count] = stu;
    student_count++;

    printf("\nSuccess: Marksheet successfully compiled for %s!\n", stu.name);
}

// 2. Function to print all compiled ledger records briefly
void displayAllMarksheets() {
    if (student_count == 0) {
        printf("\nNo records found in database.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------\n");
    printf("%-10s %-20s %-12s %-12s %-8s\n", "Roll No", "Name", "Total Marks", "Percentage", "Grade");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-20s %-12.1f %-11.2f%% %-8c\n", 
               database[i].roll_no, database[i].name, database[i].total, database[i].percentage, database[i].grade);
    }
    printf("-----------------------------------------------------------------\n");
}

// 3. Function to query and print a highly polished individual report card
void searchMarksheet() {
    if (student_count == 0) {
        printf("\nDatabase empty.\n");
        return;
    }

    int target_roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &target_roll);

    for (int i = 0; i < student_count; i++) {
        if (database[i].roll_no == target_roll) {
            printf("\n=========================================\n");
            printf("          ACADEMIC REPORT CARD           \n");
            printf("=========================================\n");
            printf("Roll Number  : %d\n", database[i].roll_no);
            printf("Student Name : %s\n", database[i].name);
            printf("-----------------------------------------\n");
            printf("SUBJECT WISE SCORE (Out of 100):\n");
            for (int j = 0; j < 5; j++) {
                printf("  Subject %d   : %.1f\n", j + 1, database[i].marks[j]);
            }
            printf("-----------------------------------------\n");
            printf("Aggregated Marks Summary:\n");
            printf("  TOTAL MARKS : %.1f / 500.0\n", database[i].total);
            printf("  PERCENTAGE  : %.2f%%\n", database[i].percentage);
            printf("  FINAL GRADE : %c\n", database[i].grade);
            printf("  STATUS      : %s\n", (database[i].grade == 'F') ? "FAIL (Retake Required)" : "PASSED");
            printf("=========================================\n");
            return;
        }
    }
    printf("Search Error: No marksheet found for Roll Number %d.\n", target_roll);
}

int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("     MARKSHEET GENERATION SYSTEM     \n");
        printf("=====================================\n");
        printf("1. Generate New Student Marksheet\n");
        printf("2. Display All Student Marksheets\n");
        printf("3. Search & Print Individual Marksheet\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection! Please input an integer.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1: generateMarksheet(); break;
            case 2: displayAllMarksheets(); break;
            case 3: searchMarksheet(); break;
            case 4: printf("\nClosing Marksheet Portal. Goodbye!\n"); return 0;
            default: printf("Invalid option. Please pick between 1 and 4.\n");
        }
    }
    return 0;
}


