// WAP to create quiz application
#include <stdio.h>

// To convert lowercase choices of user into uppercase
char toUpper(char letter){
    if (letter <= 122 && letter >= 97) letter -= 32;

    return letter;
}

// Structure to hold question data
struct Question {
    char question_text[200];
    char options[4][50];
    char correct_answer;
};

int main() {
    int score = 0;
    char user_answer;
    int total_questions = 3;

    // Initialize an array of questions
    struct Question quiz[3] = {
        {
            "Which programming language is known as the 'mother of all languages'?",
            {"A. Python", "B. C", "C. Java", "D. C++"},
            'B'
        },
        {
            "What is the size of an 'int' data type in C (typically on a 64-bit system)?",
            {"A. 2 Bytes", "B. 4 Bytes", "C. 8 Bytes", "D. 1 Byte"},
            'B'
        },
        {
            "Which keyword is used to prevent a variable from being modified in C?",
            {"A. static", "B. volatile", "C. register", "D. const"},
            'D'
        }
    };

    printf("=== Welcome to the C Programming Quiz! ===\n");
    printf("Instructions: Type the letter (A, B, C, or D) of your answer.\n\n");

    // Loop through each question
    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question_text);
        
        // Print the 4 options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Input validation loop
        while (1) {
            printf("Your Answer: ");
            scanf(" %c", &user_answer);
            
            // Convert lowercase input to uppercase
            user_answer = toUpper(user_answer);

            if (user_answer >= 'A' && user_answer <= 'D') {
                break;
            }
            printf("Invalid choice! Please enter A, B, C, or D.\n");
        }

        // Check if the answer is correct
        if (user_answer == quiz[i].correct_answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c.\n\n", quiz[i].correct_answer);
        }
    }

    // Display Final Score
    printf("=== Quiz Completed! ===\n");
    printf("Your Final Score: %d out of %d\n", score, total_questions);
    
    // Performance feedback
    if (score == total_questions) {
        printf("Perfect score! You are a C Expert.\n");
    } else if (score >= total_questions / 2) {
        printf("Good job! You passed.\n");
    } else {
        printf("Better luck next time! Keep practicing.\n");
    }

    return 0;
}