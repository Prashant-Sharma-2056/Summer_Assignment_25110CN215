// Write a program to Reursive Reverse Number
#include <stdio.h>

int reverseNumber(int number){
    if (number > 9){
        int num = number;
        int rev = num % 10;
        while ((num / 10) > 0){
            rev *= 10;
            num /= 10;
        }
        return rev + reverseNumber(number / 10);
    } else {
        return number;
    }
}

int main(){
    int num;
    printf("Enter the number to reverse: \n");
    scanf("%d", &num);

    printf("Reversed number: %d", reverseNumber(num));

    return 0;
}
