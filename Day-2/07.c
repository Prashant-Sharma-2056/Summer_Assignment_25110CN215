// Write a Program to find product of digits.
#include <stdio.h>

int main(){
    int num;
    printf("Enter the number to find product of digits: \n");
    scanf("%d", &num);

    int digit, product = 1;
    while (num  > 0){
        digit = num % 10;
        product *= digit;
        num /= 10;
    }

    printf("The product of digits is %d", product);

    return 0;
}