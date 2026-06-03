// Write a program to Write function for palindrome.
#include <stdio.h>

int isPalindrome(int number){
    int digit, reversed = 0, num = number;
    while (number > 0){
        digit = number % 10;
        number /= 10;
        reversed  = reversed * 10 + digit;
    }

    if (num == reversed) return 1;
    else return 0;
}

int main(){
    int num;
    printf("Enter the number to check for palindrome: \n");
    scanf("%d", &num);

    if (isPalindrome(num)) printf("%d is a PALINDROME\n", num);
    else printf("%d is NOT a palindrome", num);



    return 0;
}