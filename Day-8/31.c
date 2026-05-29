// Write a program to print Character Triangle
#include <stdio.h>

int main(){
    int n;
    printf("Enter the value of n: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        for (int j = 65; j <= i + 65; j++){
            printf("%c ", j);
        }

        printf("\n");
    }

    return 0;
}