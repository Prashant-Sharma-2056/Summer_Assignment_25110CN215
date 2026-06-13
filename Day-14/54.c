// WAP to find frequency of an element
#include <stdio.h>

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int element, count = 0;
    printf("Enter the number to find it's frequency: \n");
    scanf("%d", &element);

    for (int i = 0; i < n; i++) if (arr[i] == element) count++;

    printf("%d is found '%d' times in the given array", element, count);

    return 0;
}