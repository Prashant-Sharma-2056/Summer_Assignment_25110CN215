// Write a program to Write function for Fibonacci.
#include <stdio.h>

int fibonacci(int n){
    int a0 = 0, a1 = 1, a_n;
    if (n == 1) return a0;
    else if (n == 2) return a1;
    else {
        for (int i = 3; i <= n; i++){
            a_n = a0 + a1;
            a0 = a1;
            a1 = a_n;
        }

        return a_n;
    }
}

int main(){
    int n;
    printf("Which term of the fibonacci series you want to find: \n");
    scanf("%d", &n);

    printf("%dth term of fibonacci series is %d", n, fibonacci(n));

    return 0;
}