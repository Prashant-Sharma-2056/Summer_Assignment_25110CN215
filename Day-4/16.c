// Write a program to print Armstrong numbers in a range.
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
    int start, end;
    printf("Enter the starting and ending number of the range: \n");
    scanf("%d %d", &start, &end);

    printf("Printing Armstrong numbers between %d and %d", start, end);
    for (int i = start; i <= end; i++){
        if (isArmstrong(i)) printf("%d\n", i);
    }

    return 0;
}