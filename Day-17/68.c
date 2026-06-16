// WAP to find common elements
#include <stdio.h>

void commonElem(int arr1[], int size1, int arr2[], int size2){
    int arr[100], size=0;

    for (int i=0; i < size1; i++){
        for (int j=0; j < size2; j++){
            if (arr1[i] == arr2[j]){
                arr[size] = arr1[i];
                size++;
            }
        }
    }

    printf("Common Elements are: \n");
    for (int i=0; i < size; i++) printf("%d ", arr[i]);
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

    commonElem(arr1, size1, arr2, size2);

    return 0;
}