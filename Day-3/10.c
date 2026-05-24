// Write a Program to print prime number in a range.
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
    int start, end;
    printf("Set the range to print prime number by entering the starting and ending number (Eg: 10, 100): \n");
    scanf("%d %d", &start, &end);

    printf("Prime numbers between %d and %d are: \n", start, end);
    for (int i = start; i <= end; i++){
        if (checkPrime(i) == 1) printf("%d\n", i);
    }

    return 0;
}