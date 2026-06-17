// WAP to Selection Sort
#include <stdio.h>

void selectionSort(int arr[], int size){
    int smallest, count=0, x;
    
    for (int i=0; i < size; i++){
        smallest = arr[i];
        for (int j=i; j < size; j++){
            if (arr[j] < smallest){
                smallest = arr[j];
                x = arr[j];
                arr[j] = arr[i];
                arr[i] = x;    
            }
        }
    }
}

int main(){
    int arr[100], size;
    printf("Enter the size of array (<=100): \n");
    scanf("%d", &size);
    printf("Enter the elements of the array: \n");
    for (int i=0; i < size; i++) scanf("%d", &arr[i]);

    selectionSort(arr, size);
    printf("Sorted Array: \n");
    for (int i=0; i < size; i++) printf("%d ", arr[i]);

    return 0;
}