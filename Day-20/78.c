// WAP to check symmetric matrix
#include <stdio.h>

int main(){
    int matrix[10][10], m, n;

    printf("Enter the dimensions for first matrix (m,n): \n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of first matrix: \n");
    for (int i=0; i < m; i++) for (int j=0; j < n; j++) scanf("%d", &matrix[i][j]);
    
    if (m == n){
        int transpose[10][10], mt = n, nt = m, flag = 1;
        for (int i=0; i < mt; i++){
            for (int j=0; j < nt; j++) transpose[i][j] = matrix[j][i];
        }
    
        for (int i=0; i < m; i++) for (int j=0; j < n; j++) {
            if (matrix[i][j] != transpose[i][j]) flag = 0;
        }

        if (flag) printf("Matrix is SYMMETRIC");
        else printf("Matrix is NOT Symmetric");

    } else printf("A non-square matrix is not a symmetric matrix");

    return 0;
}