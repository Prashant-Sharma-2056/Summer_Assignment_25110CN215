// Write a program to convert decimal to binary
#include <stdio.h>

int power(int base, int power){
    int exp = 1;

    for (int i = 0; i < power; i++){
        exp *= base;
    }

    return exp;
}

int decimalToBinary(int decimal){
    int binary = 0, bit, i = 0;
    while (decimal > 0){
        bit = decimal % 2;
        decimal /= 2;
        binary += bit * power(10, i);
        i++;
    }

    return binary;
}

int main(){
    int num;
    printf("Enter the decimal number to convert into binary: \n");
    scanf("%d", &num);

    printf("Binary number: %d", decimalToBinary(num));

    return 0;
}