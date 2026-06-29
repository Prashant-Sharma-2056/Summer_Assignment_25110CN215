// WAP to Create Menu-Driven Calculator
#include <stdio.h>

void add(){
    float num1, num2;
    printf("Enter the first number:\n");
    scanf("%f", &num1);
    printf("Enter the second number\n");
    scanf("%f", &num2);

    printf("%f + %f = %f\n", num1, num2, (num1 + num2));
}

void subtract(){
    float num1, num2;
    printf("Enter the first number:\n");
    scanf("%f", &num1);
    printf("Enter the second number\n");
    scanf("%f", &num2);

    printf("%f - %f = %f\n", num1, num2, num1 - num2);
}

void multiply(){
    float num1, num2;
    printf("Enter the first number:\n");
    scanf("%f", &num1);
    printf("Enter the second number\n");
    scanf("%f", &num2);

    printf("%f x %f = %f\n", num1, num2, num1 * num2);
}

void divide(){
    float num1, num2;
    printf("Enter the first number:\n");
    scanf("%f", &num1);
    printf("Enter the second number\n");
    scanf("%f", &num2);

    printf("%f / %f = %f\n", num1, num2, num1 / num2);
}

void percentage(){
    float number, percent;
    printf("Enter the number: \n");
    scanf("%f", &number);
    printf("Enter the percent: \n");
    scanf("%f", &percent);

    printf("%f \% of %f is %f\n", percent, number, number * (percent / 100));
}


int main(){
    int choice;
    
    while(1){
        printf("=== Welcome to the Calculator ===\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Percentage\n");
        printf("6. Exit\n");
        printf("Enter your choice 1-6\n");
        if (scanf("%d", &choice) != 1){
            printf("Invalid Input! Enter your choice 1-6\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice){
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: percentage(); break;
            case 6: printf("\n=== Exiting the Calculator ===\nCreated By Prashant\n"); return 0;
            default: printf("Invalid Choice. Select an option between 1-6\n");
        }
    }

    return 0;
}