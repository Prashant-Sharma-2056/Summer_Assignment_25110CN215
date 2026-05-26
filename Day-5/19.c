// Write a program to print factors of a number
#include <stdio.h>

int main(){
    int num;
    printf("Enter the number to print it's factors: \n");
    scanf("%d", &num);

    printf("Factors of %d are: \n", num);
    for (int i = 1; i <= num; i++){
        if (num % i == 0){
            printf("%d\n", i);
        }
    }

    return 0;
}