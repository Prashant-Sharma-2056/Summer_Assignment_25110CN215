// Write to program to find x^n without pow()
#include <stdio.h>

int power(int base, int power){
    int exp = 1;

    for (int i = 0; i < power; i++){
        exp *= base;
    }

    return exp;
}

int main(){
    int x, n;
    printf("Enter the base and power to calculate x^n: \n");
    scanf("%d %d", &x, &n);

    printf("%d^%d = %d", x, n, power(x, n));

    return 0;
}