// WAP to remove duplicates from array
#include <stdio.h>

void removeDuplicates(int arr[], int size){
    int newSize = size;
    for (int i = 0; i < size; i++){
        for (int j = i; j < newSize; j++){
            if ((arr[i] == arr[j]) && (i != j)){
                newSize--;
                for (int k = i; k < newSize; k++) arr[k] = arr[k+1];
                j=i;
                // printf("newSize: %d", newSize);
                // for (int l = 0; l < newSize; l++) printf("%d ", arr[l]);
            }
        }
    }
    printf("newSize: %d", newSize);
    for (int l = 0; l < newSize; l++) printf("%d ", arr[l]);

    /*
    1 2 2 2 3
    i=0,j=0,k=0
    i=1:
        j=1,j=2 -> k=1,2,3 -> 1 2 2 3 | 3
        j=1,j=2 -> k=1,2 -> 1 2 3 | 3 3
        j=1,j=2
    i=2:
        j=2...


    1 2 2 3 2
    i=0
    i=1:
        j=1,j=2 -> k=1,2,3 -> 1 2 3 2...
    */

}

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    removeDuplicates(arr, n);

    return 0;
}