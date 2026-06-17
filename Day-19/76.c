// WAP to find Diagonal Sum
#include <stdio.h>

int main(){
    int matrix[10][10], m, n;

    printf("Enter the dimensions for first matrix (m,n): \n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of first matrix: \n");
    for (int i=0; i < m; i++) for (int j=0; j < n; j++) scanf("%d", &matrix[i][j]);
    
    if (m == n){
        int sum=0;

        for (int i=0; i < n; i++){
            for (int j=0; j < m; j++){
                if (i == j) sum += matrix[i][j];
            }
        }
        printf("Sum of diagonal elements is: %d", sum);
    } else printf("Can't find sum of diagonal elements of a non-square matrix");



    return 0;
}