// WAP to find duplicates in array
#include <stdio.h>

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int duplicateEntry[100], count, duplicateSize = 0;
    for (int i = 0; i < n; i++){
        count = 0;
        for (int j = i; j < n; j++){
            if (arr[i] == arr[j]) count++;
        }

        if (count > 1){
            duplicateSize++;
            duplicateEntry[duplicateSize-1] = i;
        }

        printf("Count[%d]: %d, arraySize: %d\n", i, count, duplicateSize);
    }

    if (duplicateSize == 0) printf("No duplicate entries present");
    else {
        printf("Duplicate entries found at following indices: \n");
        for (int i = 0; i < duplicateSize; i++){
            printf("%d ", duplicateEntry[i]);
        }
    }

    return 0;
}