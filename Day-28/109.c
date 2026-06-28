// WAP to create Library Management System
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to store Book details
struct Book {
    int id;
    char title[100];
    char author[50];
    int is_issued;
};

struct Book library[MAX_BOOKS];
int book_count = 0;

// 1. Function to add a book to the library
void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\nError: Library inventory capacity full!\n");
        return;
    }

    struct Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);

    // Enforce Unique Book ID constraints
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == b.id) {
            printf("Error: Book ID %d already exists!\n", b.id);
            return;
        }
    }

    printf("Enter Book Title (No spaces): ");
    scanf("%s", b.title);
    
    printf("Enter Author Name (No spaces): ");
    scanf("%s", b.author);
    
    b.is_issued = 0;

    library[book_count] = b;
    book_count++;
    printf("\nBook added successfully!\n");
}

// 2. Function to display all library assets
void displayBooks() {
    if (book_count == 0) {
        printf("\nNo books found in the library database.\n");
        return;
    }

    printf("\n----------------------------------------------------------------------------\n");
    printf("%-10s %-30s %-25s %-10s\n", "Book ID", "Title", "Author", "Status");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-30s %-25s %-10s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               (library[i].is_issued == 1) ? "Issued" : "Available");
    }
    printf("----------------------------------------------------------------------------\n");
}

// 3. Function to look up a book by title
void searchBook() {
    if (book_count == 0) {
        printf("\nLibrary database is empty.\n");
        return;
    }

    char target_title[100];
    int found = 0;
    printf("\nEnter Book Title to search: ");
    scanf("%s", target_title);

    for (int i = 0; i < book_count; i++) {
        // Simple exact match check
        if (strcmp(library[i].title, target_title) == 0) {
            printf("\n--- Book Found ---\n");
            printf("ID:     %d\n", library[i].id);
            printf("Title:  %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Status: %s\n", (library[i].is_issued == 1) ? "Issued" : "Available");
            found = 1;
        }
    }
    if (!found) {
        printf("No book found with the title \"%s\".\n", target_title);
    }
}

// 4. Function to issue a book
void issueBook() {
    if (book_count == 0) {
        printf("\nLibrary database is empty.\n");
        return;
    }

    int target_id;
    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &target_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == target_id) {
            if (library[i].is_issued == 1) {
                printf("Transaction Failed: This book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1; // Mark as issued
                printf("Success: Book \"%s\" has been successfully issued.\n", library[i].title);
            }
            return;
        }
    }
    printf("Error: Book ID %d not found.\n", target_id);
}

// 5. Function to return an issued book
void returnBook() {
    if (book_count == 0) {
        printf("\nLibrary database is empty.\n");
        return;
    }

    int target_id;
    printf("\nEnter Book ID to Return: ");
    scanf("%d", &target_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == target_id) {
            if (library[i].is_issued == 0) {
                printf("Transaction Failed: This book is already sitting in the library shelf.\n");
            } else {
                library[i].is_issued = 0; // Mark as available
                printf("Success: Book \"%s\" returned safely to the library.\n", library[i].title);
            }
            return;
        }
    }
    printf("Error: Book ID %d not found.\n", target_id);
}

int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("      LIBRARY MANAGEMENT SYSTEM      \n");
        printf("=====================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("\nExiting Library System. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Select an option between 1 and 6.\n");
        }
    }
    return 0;
}


