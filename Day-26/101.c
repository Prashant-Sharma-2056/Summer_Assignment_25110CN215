// WAP to Create number guessing game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, attempts = 0;

    // Seed the random number generator using the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("=== Welcome to the Number Guessing Game! ===\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");


    do {
        printf("Enter your guess: ");
        
        // Read user input and handle basic non-integer errors
        if (scanf("%d", &guess) != 1) {
            printf("Please enter a valid integer.\n");
            // Clear the input buffer to prevent an infinite loop
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (guess > secret_number) {
            printf("Too high! Try again.\n\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n\n");
        } else {
            printf("\nCongratulations! You guessed it right!\n");
            printf("The secret number was %d.\n", secret_number);
            printf("It took you %d attempts.\n", attempts);
        }

    } while (guess != secret_number);

    return 0;
}