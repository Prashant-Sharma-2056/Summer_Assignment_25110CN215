#include <stdio.h>

int main(){
    int num;
    printf("Enter the number to find the sum of natural number before that: \n");
    scanf("%d", &num);

    int sum = 0;
    for (int i = 1; i <= num; i++){
        sum += i;
    }

    printf("The sum of first %d numbers is %d", num, sum);

    return 0;
}