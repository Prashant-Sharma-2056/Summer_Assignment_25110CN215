// WAP to reverse array
#include <stdio.h>

void reverseArray(int arr[], int size){
    int x;
    for (int i = 0; i < size/2; i++){
        x = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = x;
    }
}

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    reverseArray(arr, n);
    for (int i = 0; i < n; i++) printf("arr[%d]: %d\n", i, arr[i]);

    return 0;
}

/*

1 2 3 4 -> 
1 2 3 4 5 -> 0/4, 1/3, 

*/