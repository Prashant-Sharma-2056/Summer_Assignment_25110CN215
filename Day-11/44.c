// Write a program to Write function to find factorial.
#include <stdio.h>

int findFactorial(int number){
    int factorial = 1;

    for (int i = 1; i <= number; i++) factorial *= i;

    return factorial;
}

int main(){
    int num;
    printf("Enter the number to find it's factorial: \n");
    scanf("%d", &num);

    printf("Factorial of %d is %d", num, findFactorial(num));

    return 0;
}