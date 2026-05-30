// Write a program to print Repeated Character Pattern
#include <stdio.h>

int main(){
    int n;
    printf("Enter the value of n: \n");
    scanf("%d", &n);

    for (int i = 65; i < n + 65; i++){
        for (int j = 0; j <= i - 65; j++){
            printf("%c ", i);
        }
        printf("\n");
    }

    return 0;
}