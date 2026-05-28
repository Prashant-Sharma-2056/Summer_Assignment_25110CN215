// Write a program to Recursive Fibonacci
#include <stdio.h>

int fibonacci(int number){
    if (number == 1) return 0;
    else if (number == 2) return 1;
    else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }

}

int main(){
    int n;
    printf("Enter the nth term for which you want to find fibonacci term: \n");
    scanf("%d", &n);

    printf("%dth Fibonacci term is %d", n, fibonacci(n));

    return 0;
}