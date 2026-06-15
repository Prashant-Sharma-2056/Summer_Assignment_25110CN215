// WAP to find maximum frequency element
#include <stdio.h>

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);


    int count = 0, maxCount = 0, maxFrequencyElement;

    for (int i = 0; i < n; i++){
        count = 0;
        
        for (int j = i; j < n; j++){
            if (arr[j] == arr[i]){
                count++;
            }
        }

        if (count > maxCount){
            maxCount = count;
            maxFrequencyElement = arr[i];
        }

    }

    printf("%d is the maximum frequency element having %d instances", maxFrequencyElement, maxCount);

    return 0;
}