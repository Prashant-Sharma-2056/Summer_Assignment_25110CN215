// WAP to move zeroes to end
#include <stdio.h>

void moveZeroesToEnd(int arr[], int size){
    int count = 0, x;
    for (int i = 0; i < size - count; i++){
        if (arr[i] == 0){
            // printf("Zero found!\n");
            x = arr[i];
            arr[i] = arr[size - count - 1];
            arr[size - count - 1] = x;
            count++;
        }
    }
}

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    moveZeroesToEnd(arr, n);
    printf("Array: \n");

    for (int i = 0; i < n; i++) printf("arr[%d]: %d\n", i, arr[i]);


    return 0;
}