// Write a program to count set bits in a number;
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
    printf("Enter the DECIMAL number to count the set bits: \n");
    scanf("%d", &num);

    num = decimalToBinary(num);
    int count = 0, bit;
    while (num > 0){
        bit = num % 10;
        if (bit == 1) count++;
        num /= 10;
    }

    printf("%d bits are set in the given number", count);

    return 0;
}