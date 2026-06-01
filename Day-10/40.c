// Write a program to print character pyramid
#include <stdio.h>

int main(){
    int n;
    printf("Enter the value of n: \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        for (int j = 0; j < n - i; j++){
            printf("  ");
        }

        for (int j = 1; j <= i; j++){
            printf("%c ", j + 64);
        }

        for (int j = i - 1; j >= 1; j--){
            printf("%c ", j + 64);
        }
        printf("\n");
    }

    return 0;
}