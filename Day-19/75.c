// WAP to Transpose Matrix
#include <stdio.h>

int main(){
    int matrix[10][10], m, n;

    printf("Enter the dimensions for first matrix (m,n): \n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of first matrix: \n");
    for (int i=0; i < m; i++) for (int j=0; j < n; j++) scanf("%d", &matrix[i][j]);
    
    printf("TRANSPOSED MATRIX:\n");
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }


    return 0;
}