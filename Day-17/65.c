// WAP to merge arrays
#include <stdio.h>

void mergeArray(int arr1[], int size1, int arr2[], int size2){
    int arr[200], size = size1 + size2, x=0, y=0;

    for (int i=0; i < size; i++){
        // printf("arr1[%d]: %d, arr2[%d]: %d\n", x, arr1[x], y, arr2[y]);

        if (x < size1 && y < size2){
            if (arr1[x] < arr2[y]){
                arr[i] = arr1[x];
                x++;
            } else {
                arr[i] = arr2[y];
                y++;
            }
        } else if (x == size1) {
            arr[i] = arr2[y];
            y++;
        } else if (y == size2) {
            arr[i] = arr1[x];
            x++;
        }

        // printf("arr[%d]: %d\n", i, arr[i]);
    }

    printf("Merged Array:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
}

int main(){
    int arr1[100], size1, arr2[100], size2;

    printf("Enter the size of first array:\n");
    scanf("%d", &size1);
    printf("Enter the elements for first array:\n");
    for (int i=0; i < size1; i++) scanf("%d", &arr1[i]);

    printf("Enter the size of second array:\n");
    scanf("%d", &size2);
    printf("Enter the elements for second array:\n");
    for (int i=0; i < size2; i++) scanf("%d", &arr2[i]);

    int mergedArray[200], mergedSize = size1 + size2;
    mergeArray(arr1, size1, arr2, size2);

    return 0;
}