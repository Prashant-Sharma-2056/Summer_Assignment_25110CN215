// Write a program to print largest prime factor
#include <stdio.h>

int isPrime(int number){
    int status = 1;

    for (int i = 2; i < number; i++){
        if (number % i == 0){
            status = 0;
            break;
        }
    }

    return status;
}

int largestPrimeFactor(int number){
    for (int i = number; i >= 2; i--){
        if (number % i == 0){
            if (isPrime(i)){
                return i;
            }
        }
    }
}

int main(){
    int num;
    printf("Enter the number for which you want to find largest prime factor: \n");
    scanf("%d", &num);

    printf("Largest Prime Facator of %d is %d", num, largestPrimeFactor(num));

    return 0;
}