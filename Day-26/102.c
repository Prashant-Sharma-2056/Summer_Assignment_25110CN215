// WAP to create Voting Eligiblity System
#include <stdio.h>

int main() {
    int age;
    const int VOTING_AGE = 18;

    printf("=== Voting Eligibility Checker ===\n\n");
    printf("Please enter your age: ");

    // Check if the input is a valid integer
    if (scanf("%d", &age) != 1) {
        printf("Error: Invalid input. Please enter a number.\n");
        return 1;
    }

    if (age < 0) {
        printf("Error: This age is physically impossible. Please enter a valid age.\n");
    } 
    
    else if (age >= VOTING_AGE) {
        printf("\nResult: You are ELIGIBLE to vote!\n");
    } 
    else {
        printf("\nResult: You are NOT eligible to vote yet.\n");
        printf("You need to wait %d more year(s) to cast your vote.\n", VOTING_AGE - age);
    }

    return 0;
}