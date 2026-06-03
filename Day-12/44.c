// Write a program to Write function for Armstrong.
#include <stdio.h>

int isArmstrong(int number){
    int armstrong = 0, num = number, power;
    int digits = 0;

    if (number == 0) return 1;

    while (number > 0){
        digits++;
        number /= 10;
    }

    number = num;

    int digit;
    while (num > 0){
        power = 1;
        digit = num % 10;
        num /= 10;

        for (int i = 0; i < digits; i++){
            power *= digit;
        }

        armstrong += power;
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