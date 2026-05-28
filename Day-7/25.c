// Write a program to Recusrive Factorial
#include <stdio.h>

int factorial(int number){
    if (number == 1 || number == 0) return 1;
    else {
        return number * factorial(number-1);
    }    
}

int main(){
    int num;
    printf("Enter the number to find factorial: \n");
    scanf("%d", &num);

    printf("Factorial of %d is %d", num, factorial(num));

    return 0;
}