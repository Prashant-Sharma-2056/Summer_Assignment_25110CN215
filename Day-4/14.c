// Write a program to find nth term of fibonacci series
#include <stdio.h>

int main(){
    int n;
    printf("Which term of the fibonacci series you want to find: \n");
    scanf("%d", &n);

    int a0 = 0, a1 = 1, a_n;
    if (n == 1) a_n = a0;
    else if (n == 2) a_n = a1;
    else {
        for (int i = 3; i <= n; i++){
            a_n = a0 + a1;
            a0 = a1;
            a1 = a_n;
        }
    }

    printf("%dth term of fibonacci series is %d", n, a_n);

    return 0;
}