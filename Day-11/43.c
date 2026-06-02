// Write to program to write a function to check prime
#include <stdio.h>

int isPrime(int number){
    for (int i = 2; i < number; i++){
        if (number % i == 0){
            return 0;
        }
    }
    
    return 1;
}

int main(){
    int num;
    printf("Enter the number to check for Prime: \n");
    scanf("%d", &num);

    if (isPrime(num)) printf("number is PRIME");
    else printf("number is NOT prime");

    return 0;
}