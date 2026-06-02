// Write to program to write a function to find sum of two numbers
#include <stdio.h>

int addTwoNums(int number1, int number2){
    return number1 + number2;
}

int main(){
    int num1, num2;
    printf("Enter the numbers to find their sum: \n");
    scanf("%d %d", &num1, &num2);

    printf("The sum of %d and %d is %d", num1, num2, addTwoNums(num1, num2));

    return 0;
}