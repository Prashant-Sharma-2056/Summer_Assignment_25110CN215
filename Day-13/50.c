// Write a program to Find sum and average of array.
#include <stdio.h>

int sumOfArray(int arr[], int size){
    int sum = 0;

    for (int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum;
}

int main(){
    int arr[100], n;
    printf("Enter the number of elements (less than 100) of array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Sum of the elements of given array is %d", sumOfArray(arr, n));
    

    return 0;
}