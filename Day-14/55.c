// WAP to find second largest element
#include <stdio.h>

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int largest = arr[0], secondLargest = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > secondLargest){
            secondLargest = arr[i];
        } else {
            if (n != 1) secondLargest = arr[1];
        }
    }

    printf("Second Largest Number: %d", secondLargest);

    return 0;
}