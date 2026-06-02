// Write to program to write a function to find maximum.
#include <stdio.h>

int findMax(int number1, int number2){
    if (number1 > number2) return number1;
    else return number2;
}

int main(){
    int num1, num2;
    printf("Enter the numbers to find maximum: \n");
    scanf("%d %d", &num1, &num2);

    printf("Max of given two numbers is %d", findMax(num1, num2));

    return 0;
}