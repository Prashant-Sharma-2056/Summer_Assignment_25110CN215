// Write a program to Find sum of digits of a number.
#include <stdio.h>

int main(){
    int num;
    printf("Enter an integer to get the sum of digits: \n");
    scanf("%d", &num);

    int sum = 0;
    while (num > 0){
        sum += num % 10;
        num /= 10;
    }

    printf("Sum of digits of given integer is %d", sum);

    return 0;
}