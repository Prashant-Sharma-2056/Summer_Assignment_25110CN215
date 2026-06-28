// WAP to Create Contact Management System
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact phonebook[MAX_CONTACTS];
int contact_count = 0;


// 1. Function to add a contact to the phonebook
void addContact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("\nError: Phonebook capacity full!\n");
        return;
    }

    struct Contact c;
    printf("\nEnter Contact Name (No spaces): ");
    scanf("%s", c.name);

    // Prevent duplicate name entries
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(phonebook[i].name, c.name) == 0) {
            printf("Error: A contact named \"%s\" already exists!\n", c.name);
            return;
        }
    }

    printf("Enter Phone Number: ");
    scanf("%s", c.phone);
    
    printf("Enter Email Address: ");
    scanf("%s", c.email);

    // Commit to phonebook storage array
    phonebook[contact_count] = c;
    contact_count++;
    printf("\nContact saved successfully!\n");
}

// 2. Function to print all contacts in a structural layout
void displayContacts() {
    if (contact_count == 0) {
        printf("\nPhonebook is empty. No records to display.\n");
        return;
    }

    printf("\n----------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-30s\n", "Name", "Phone Number", "Email Address");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%-20s %-20s %-30s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
    }
    printf("----------------------------------------------------------------------------\n");
}

// 3. Function to find a contact by name mapping
void searchContact() {
    if (contact_count == 0) {
        printf("\nPhonebook is empty.\n");
        return;
    }

    char target_name[50];
    printf("\nEnter Name to search: ");
    scanf("%s", target_name);

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(phonebook[i].name, target_name) == 0) {
            printf("\n--- Contact Found ---\n");
            printf("Name  : %s\n", phonebook[i].name);
            printf("Phone : %s\n", phonebook[i].phone);
            printf("Email : %s\n", phonebook[i].email);
            return;
        }
    }
    printf("Contact record for \"%s\" not found.\n", target_name);
}

// 4. Function to delete a contact via leftward array shifting
void deleteContact() {
    if (contact_count == 0) {
        printf("\nPhonebook is empty. Nothing to delete.\n");
        return;
    }

    char target_name[50];
    printf("\nEnter Name of the contact to delete: ");
    scanf("%s", target_name);

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(phonebook[i].name, target_name) == 0) {
            // Shift remaining records up to overwrite the deleted slot
            for (int j = i; j < contact_count - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            contact_count--; // Shrink the phonebook size tracking counter
            printf("\nContact \"%s\" deleted successfully!\n", target_name);
            return;
        }
    }
    printf("Error: Contact \"%s\" not found.\n", target_name);
}


int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("      CONTACT MANAGEMENT SYSTEM      \n");
        printf("=====================================\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete a Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("\nExiting Phonebook System. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Select an option between 1 and 5.\n");
        }
    }
    return 0;
}
