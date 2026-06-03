// Write a program to Write function for perfect number.
#include <stdio.h>

int isPerfectNumber(int number){
    int sum = 0;

    for (int i = 1; i < number; i++){
        if (number % i == 0){
            sum += i;
        }
    }

    if (number == sum) return 1;
    else return 0;
}

int main(){
    int num;
    printf("Enter the number to check for Perfect Number: \n");
    scanf("%d", &num);

    if (isPerfectNumber(num)) printf("%d is a PERFECT number", num);
    else printf("%d is NOT a perfect number", num);

    return 0;
}
