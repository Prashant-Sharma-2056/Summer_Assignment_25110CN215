// Write a program to check wheather a number is Prime.
#include <stdio.h>

int checkPrime(int number){
    int status = 1;

    for (int i = 2; i < number; i++){
        if (number % i == 0){
            status = 0;
            break;
        }
    }

    return status;
}

int main(){
    int num;
    printf("Enter the number: \n");
    scanf("%d", &num);

    if (checkPrime(num) == 1) printf("number is PRIME");
    else printf("number is NOT prime");

    return 0;
}