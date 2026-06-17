// WAP to bubble sort
#include <stdio.h>

void bubbleSort(int arr[], int size){
    int x;
    for (int i=0; i < size - 1; i++){
        for (int j=0; j < size - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = x;
            }
        }
    }

    /*
    2 3 5 4 1
    2 3 4 1 5:i=0
    2 3 1 4 5:i=1
    2 1 3 4 5:i=2
    2 1 3 4 5:i=3
    */
}

int main(){
    int arr[100], size;
    printf("Enter the size of array (<=100): \n");
    scanf("%d", &size);
    printf("Enter the elements of the array: \n");
    for (int i=0; i < size; i++) scanf("%d", &arr[i]);

    bubbleSort(arr, size);
    printf("Sorted Array: \n");
    for (int i=0; i < size; i++) printf("%d ", arr[i]);

    return 0;
}