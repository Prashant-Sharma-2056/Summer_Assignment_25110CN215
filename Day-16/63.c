// WAP to find pair with given sum
#include <stdio.h>

void pairSum(int arr[], int size, int givenSum){
    int num1, num2;
    for (int i = 0; i < size; i++){
        for (int j = i; j < size; j++){
            if (arr[j] == givenSum - arr[i]){
                num1 = arr[i];
                num2 = arr[j];
                // printf("BREAK\n");
                goto result;
            }
        }
        // printf("OUTER RUNNING\n");
    }

    result:
    printf("num1 = %d, num2 = %d\n", num1, num2);
}

int main(){
    int arr[100], n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int sum;
    printf("Enter the sum to find it's pair:\n");
    scanf("%d", &sum);

    pairSum(arr, n, sum);

    return 0;
}