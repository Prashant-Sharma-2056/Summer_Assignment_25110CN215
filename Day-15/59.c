// WAP to rotate array right
#include <stdio.h>

void rotateArrayRight(int arr[], int size){
    int x = arr[size - 1];

    for (int i = size - 1; i > 0; i--){
        arr[i] = arr[i - 1];
    }

    arr[0] = x;
}

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    rotateArrayRight(arr, n);
    printf("Array rotated to right by element\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}