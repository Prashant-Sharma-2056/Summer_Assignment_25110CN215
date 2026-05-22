#include <stdio.h>

int main(){
    int num;
    printf("Enter an integer number to count number of digits: \n");
    scanf("%d", &num);

    int digits = 0;
    while (num > 0){
        digits++;
        num /= 10;
    }

    printf("There are %d digits in the given integer", digits);

    return 0;
}