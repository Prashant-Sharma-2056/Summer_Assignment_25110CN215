// Write a program to find Fibonacci Series
#include <stdio.h>

int main(){
    int n;
    printf("How many number to terms of fibonacci series you want to generate:\n");
    scanf("%d", &n);

    int a0 = 0, a1 = 1, a_n;
    printf("%d ", a0);
    printf("%d ", a1);
    for (int i = 3; i <= n; i++){
        a_n = a0 + a1;
        printf("%d ", a_n);
        a0 = a1;
        a1 = a_n;
    }

    return 0;
}