// Write a Program to check whether a number is palindrome.
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
    printf("Enter the number to check for palindrome: \n");
    scanf("%d", &num);

    if (num == reverseNum(num)) printf("%d is a PALINDROME\n", num);
    else printf("%d is NOT a palindrome", num);

    return 0;
}