// WAP to Create menu-driven string operations system.
#include <stdio.h>

#define MAX_SIZE 100


// 1. Custom function to find string length
int getStringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// 2. Custom function to copy a string
void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// 3. Custom function to join strings together
void concatenateStrings(char dest[], char src[]) {
    int dest_len = getStringLength(dest);
    int i = 0;
    
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}

// 4. Custom function to compare strings by ASCII tracking
int compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return 0;
}

// 5. Custom function to reverse a string in-place using two-pointer swaps
void reverseString(char str[]) {
    int start = 0;
    int end = getStringLength(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
}


int main() {
    int choice;
    char str1[MAX_SIZE], str2[MAX_SIZE];

    while (1) {
        printf("\n=== STRING OPERATIONS SYSTEM ===\n");
        printf("1. Find Length of a String\n");
        printf("2. Copy String\n");
        printf("3. Concatenate (Join) Two Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Reverse a String\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        // Consume the trailing newline character left by scanf
        getchar(); 

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                scanf(" %[^\n]", str1); // Reads string with spaces
                printf("Length of the string: %d characters\n", getStringLength(str1));
                break;

            case 2:
                printf("\nEnter the source string to copy: ");
                scanf(" %[^\n]", str1);
                copyString(str2, str1);
                printf("Copied Destination String: %s\n", str2);
                break;

            case 3:
                printf("\nEnter the first string (Destination): ");
                scanf(" %[^\n]", str1);
                printf("Enter the second string to append: ");
                scanf(" %[^\n]", str2);
                concatenateStrings(str1, str2);
                printf("Combined String result: %s\n", str1);
                break;

            case 4:
                printf("\nEnter first string: ");
                scanf(" %[^\n]", str1);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                int res = compareStrings(str1, str2);
                if (res == 0) printf("Result: Strings are perfectly identical.\n");
                else if (res > 0) printf("Result: First string is larger (lexicographically).\n");
                else printf("Result: Second string is larger (lexicographically).\n");
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                scanf(" %[^\n]", str1);
                reverseString(str1);
                printf("Reversed String: %s\n", str1);
                break;

            case 6:
                printf("\nExiting System. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please pick an option between 1 and 6.\n");
        }
    }
    return 0;
}
