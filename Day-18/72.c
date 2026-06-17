// WAP to sort array in descending order
#include <stdio.h>

void descendingSort(int arr[], int size){
    int x;
    for (int i=0; i < size - 1; i++){
        for (int j=0; j < size - 1 - i; j++){
            if (arr[j] < arr[j+1]){
                x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = x;
            }
        }
    }
}

int main(){
    int arr[100], size, element;
    printf("Enter the size of array (<=100): \n");
    scanf("%d", &size);
    printf("Enter the elements of the array: \n");
    for (int i=0; i < size; i++) scanf("%d", &arr[i]);

    descendingSort(arr, size);
    printf("Descending Sorted Array: \n");
    for (int i=0; i < size; i++) printf("%d ", arr[i]);

    return 0;
}