// Write a program to find largest and smallest element.
#include <stdio.h>

int main(){
    int arr[100], n;
    printf("Enter the number of elements (less than 100) of array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int smallest = arr[0], largest = arr[0];

    for (int i = 0; i < n; i++) if (arr[i] < smallest) smallest = arr[i];

    for (int i = 0; i < n; i++) if (arr[i] > largest) largest = arr[i];

    printf("Smallest Element: %d\n", smallest);
    printf("Largest Element: %d\n", largest);

    return 0;
}