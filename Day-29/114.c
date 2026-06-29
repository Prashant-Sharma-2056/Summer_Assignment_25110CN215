// WAP to Create Menu-Driven Array Operations System
#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void insertElement() {
    if (size >= MAX_SIZE) {
        printf("\nError: Array Overflow! Cannot insert more elements.\n");
        return;
    }

    int element, position;
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    
    printf("Enter the position (1 to %d): ", size + 1);
    scanf("%d", &position);

    if (position < 1 || position > size + 1) {
        printf("Invalid position! Insertion failed.\n");
        return;
    }

    int index = position - 1;

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = element;
    size++;
    printf("Element inserted successfully!\n");
}

void deleteElement() {
    if (size == 0) {
        printf("\nError: Array Underflow! No elements to delete.\n");
        return;
    }

    int position;
    printf("\nEnter the position of element to delete (1 to %d): ", size);
    scanf("%d", &position);

    if (position < 1 || position > size) {
        printf("Invalid position! Deletion failed.\n");
        return;
    }

    int index = position - 1;
    int deleted_value = arr[index];

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    printf("Element %d deleted successfully from position %d!\n", deleted_value, position);
}

void searchElement() {
    if (size == 0) {
        printf("\nArray is empty. Nothing to search.\n");
        return;
    }

    int target, found = 0;
    printf("\nEnter the element to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at position %d (Index %d).\n", target, i + 1, i);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}

void displayArray() {
    if (size == 0) {
        printf("\nArray is completely empty: [ ]\n");
        return;
    }

    printf("\nCurrent Array Elements: \nIndex:    ");
    for (int i = 0; i < size; i++) {
        printf("%-5d", i);
    }
    printf("\nElement:  ");
    for (int i = 0; i < size; i++) {
        printf("%-5d", arr[i]);
    }
    printf("\nTotal elements active: %d / %d\n", size, MAX_SIZE);
}


int main() {
    int choice;

    while (1) {
        printf("\n        ARRAY OPERATIONS SYSTEM      \n");
        printf("1. Insert Element\n");
        printf("2. Delete Element by Position\n");
        printf("3. Search Element (Linear Search)\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): \n");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid integer choice.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: insertElement(); break;
            case 2: deleteElement(); break;
            case 3: searchElement(); break;
            case 4: displayArray(); break;
            case 5: printf("\nExiting System\n"); return 0;
            default: printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}

