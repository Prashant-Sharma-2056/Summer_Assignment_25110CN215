// Write a program to Input and display array.
#include <stdio.h>

int main(){
    int size, arr[1000];
    printf("Enter the size of array not greater than 1000: \n");
    scanf("%d", &size);

    printf("Enter the %d elements of the array: \n", size);
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Printing the array:\n");
    for (int i = 0; i < size; i++)  printf("%d ", arr[i]);

    return 0;
}