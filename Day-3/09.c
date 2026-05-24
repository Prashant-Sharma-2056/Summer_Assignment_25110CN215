// Write a program to check wheather a number is Prime.
#include <stdio.h>

int main(){
    int num;
    printf("Enter the number: \n");
    scanf("%d", &num);

    int status = 1;
    for (int i = 2; i < num; i++){
        if (num % i == 0){
            status = 0;
            break;
        }
    }

    if (status) printf("number is PRIME");
    else printf("number is NOT prime");

    return 0;
}