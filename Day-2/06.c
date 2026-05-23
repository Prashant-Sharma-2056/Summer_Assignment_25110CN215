// Write a Program to Reverse a number.
#include <stdio.h>

int reverseNum(int num){
    int digit, reversed = 0;
    while (num > 0){
        digit = num % 10;
        num /= 10;
        reversed  = reversed * 10 + digit;
    }

    return reversed;
}

int main(){
    int num;
    printf("Enter the number to be reversed: \n");
    scanf("%d", &num);

    int reversed = reverseNum(num);

    printf("Reversed number is: %d", reversed);

    return 0;
}