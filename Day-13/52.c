// Write a program to count even and odd elements
#include <stdio.h>

int main(){
    int arr[100], n;
    printf("Enter the number of elements (less than 100) of array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int odd_count = 0, even_count = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] % 2 == 0) even_count++;
        else odd_count++;
    }

    printf("There are %d odd elements and %d even elements", odd_count, even_count);

    return 0;
}