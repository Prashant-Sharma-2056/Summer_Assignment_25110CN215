// Write a program to check Armstrong number
#include <stdio.h>

int power(int base, int power){
    int exp = 1;

    for (int i = 0; i < power; i++){
        exp *= base;
    }

    return exp;
}

int numberOfDigits(int number){
    int digits = 0;

    if (number == 0) return 1;

    while (number > 0){
        digits++;
        number /= 10;
    }
    
    return digits;
}

int isArmstrong(int number){
    int armstrong = 0, num = number;

    int digit;
    while (num > 0){
        digit = num % 10;
        num /= 10;
        armstrong += power(digit, numberOfDigits(number));
    }

    if (armstrong == number) return 1;
    else return 0;
}

int main(){
    int num;
    printf("Enter the number to check for Armstrong number:\n");
    scanf("%d", &num);

    if (isArmstrong(num)) printf("%d is an ARMSTRONG number", num);
    else printf("%d is NOT an armstrong number", num);

    return 0;
}