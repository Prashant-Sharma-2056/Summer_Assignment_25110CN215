#include <stdio.h>

int main(){
    int number;
    printf("Enter the number to find the factorial: \n");
    scanf("%d", &number);

    int factorial = 1;
    for (int i=1; i <= number; i++){
        factorial *= i;
    }

    printf("The factorial of %d is %d", number, factorial);

    return 0;
}