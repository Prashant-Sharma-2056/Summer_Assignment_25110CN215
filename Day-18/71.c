// WAP to Binary Search
#include <stdio.h>

int binarySearch(int arr[], int size, int search){
    int index = -1, mid = size / 2, lowerLimit = 0, upperLimit = size-1;

    while (lowerLimit < upperLimit){
        if (search == arr[mid]) {
            index = mid;
            break;
        }
        else if (search > arr[mid]) {
            lowerLimit = mid + 1;
            mid = (lowerLimit + upperLimit) / 2;
        }
        else if (search < arr[mid]) {
            upperLimit = mid - 1;
            mid = (lowerLimit + upperLimit) / 2;
        }
    }

    return index;

    /*
    3 4 5 8 9 45 69 70 75: size=9
    search:71

    ll=0,ul=8,mid=4
    ll=5,ul=8,mid=6
    ll=7,ul=8,mid=7
    ll=8,ul=8,mid=8
    ll=8,ul=7,mid=7
    */
}

int main(){
    int arr[100], size, element;
    printf("Enter the size of array (<=100): \n");
    scanf("%d", &size);
    printf("Enter the elements of the array: \n");
    for (int i=0; i < size; i++) scanf("%d", &arr[i]);

    printf("Enter the element to search for in the array: \n");
    scanf("%d", &element);

    int binarySearchIndex = binarySearch(arr, size, element);
    if (binarySearchIndex == -1) printf("%d is NOT present\n", element);
    else printf("%d FOUND at index %d", element, binarySearchIndex);

    return 0;
}