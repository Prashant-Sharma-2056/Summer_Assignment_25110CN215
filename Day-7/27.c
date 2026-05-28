// Write a program to Recursive sum of digits
#include <stdio.h>

int recursiveDigits(int number){
    if (number > 9){
        return (number % 10) + recursiveDigits(number / 10);
    } else {
        return number;
    }
}

int main(){
    int num;
    printf("Enter the number for which you want to find sum of digits: \n");
    scanf("%d", &num);

    printf("Sum of digits of number %d is %d", num, recursiveDigits(num));

    return 0;
}
