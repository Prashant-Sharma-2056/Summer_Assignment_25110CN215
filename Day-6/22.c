// Write a program to convert binary to decimal
#include <stdio.h>

int power(int base, int power){
    int exp = 1;

    for (int i = 0; i < power; i++){
        exp *= base;
    }

    return exp;
}

int binaryToDecimal(int binary){
    int decimal = 0, digit;

    for (int i = 0; binary > 0; i++){
        digit = binary % 10;
        binary /= 10;
        decimal += digit * power(2, i);
    }

    return decimal;
}

int main(){
    int num;
    printf("Enter the binary number to convert into decimal: \n");
    scanf("%d", &num);

    printf("Decimal Number: %d", binaryToDecimal(num));

    return 0;
}