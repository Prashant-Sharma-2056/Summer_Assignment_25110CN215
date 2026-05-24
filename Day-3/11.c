// Write a program to find GCD of two numbers;
#include <stdio.h>

int main(){
    int num1, num2;
    printf("Enter the two numbers to find their GCD: \n");
    scanf("%d %d", &num1, &num2);

    // Swapping numbers if num1 > num2
    if (num1 > num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }


    int gcd;
    for (int i = num1;  i >= 1; i--){
        if (num1 % i == 0){
            if (num2 % i ==0){
                gcd = i;
                break;    
            }
        }
    }

    printf("GCD of %d and %d is %d", num1, num2, gcd);

    return 0;
}