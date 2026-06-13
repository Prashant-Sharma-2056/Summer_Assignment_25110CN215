// WAP to Linear Search
#include <stdio.h>

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int x, index = -1;
    printf("Enter the number to search for in the array: \n");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) if (arr[i] == x) index = i;

    if (index != -1) printf("%d found in array at index %d", x, index);
    else printf("%d is not present in the given array", x);

    return 0;
}