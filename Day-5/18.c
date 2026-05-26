// Write a program to check Strong number
#include <stdio.h>

int factorial(int number){
    int factorial = 1;

    for (int i = 1; i <= number; i++){
        factorial *= i;
    }

    return factorial;
}

int isStrongNumber(int number){
    int sum = 0, num = number;

    int digit;
    while (num > 0){
        digit = num % 10;
        num /= 10;
        sum += factorial(digit);
    }

    if (sum == number) return 1;
    else return 0;
}

int main(){
    int num;
    printf("Enter the number to check for strong number: \n");
    scanf("%d", &num);

    if (isStrongNumber(num)) printf("%d is a STRONG number", num);
    else printf("%d is NOT a strong number", num);

    return 0;
}