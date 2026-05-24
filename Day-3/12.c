// Write a program to find LCM of two numbers.
#include <stdio.h>

int main(){
    int num1, num2;
    printf("Enter two number to find their LCM: \n");
    scanf("%d %d", &num1, &num2);

    int lcm = 1;    

    // Swapping numbers if num1 > num2
    if (num1 > num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }


    for (int i = 1; i <= num2; i++){
        if (num2 % i == 0){
            if (num1 % i == 0){
                lcm *= i;
                num1 /= i;
                num2 /= i;
                i = 1;
            } else {
                lcm *= i;
                num2 /= i;
                i = 1;
            }
        }
        
        if (num1 % i == 0){
            if (num2 % i == 0){
                lcm *= i;
                num1 /= i;
                num2 /= i;
                i = 1;
            } else {
                lcm *= i;
                num1 /= i;
                i = 1;
            }
        }
        // printf("i = %d, lcm = %d, num1 = %d, num2 = %d\n", i, lcm, num1, num2);
    }

    printf("LCM of given numbers is %d", lcm);

    return 0;
}