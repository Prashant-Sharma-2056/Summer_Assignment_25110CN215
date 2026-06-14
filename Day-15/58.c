// WAP to rotate array left
#include <stdio.h>

void rotateArrayLeft(int arr[], int size){
    int x = arr[0];

    for (int i = 0; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }

    arr[size - 1] = x;
}

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    rotateArrayLeft(arr, n);
    printf("Array rotated to left by element\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}