// WAP to find missing numbers in array.
#include <stdio.h>

int isMissing(int arr[], int size, int missingNUM){
    int missing = -1;

    for (int i = 0; i < size; i++){
        if (arr[i] == missingNUM){
            missing = i;
            break;
        }
    }

    return missing;
}

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]); 
    
    int missingNum;
    printf("Enter the number which could be missing: \n");
    scanf("%d", &missingNum);

    if (isMissing(arr, n, missingNum) == -1) printf("%d is MISSING\n", missingNum);
    else printf("%d is NOT missing");

    return 0;
}