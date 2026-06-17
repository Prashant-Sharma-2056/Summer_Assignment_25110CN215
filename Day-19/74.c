// WAP to Subtract Matrices
#include <stdio.h>

int main(){
    int matrix1[10][10], matrix2[10][10], m1, n1, m2, n2;

    printf("Enter the dimensions for first matrix (m,n): \n");
    scanf("%d %d", &m1, &n1);
    printf("Enter the elements of first matrix: \n");
    for (int i=0; i < m1; i++) for (int j=0; j < n1; j++) scanf("%d", &matrix1[i][j]);
    
    printf("Enter the dimensions for second matrix (m,n): \n");
    scanf("%d %d", &m2, &n2);
    printf("Enter the elements of second matrix: \n");
    for (int i=0; i < m2; i++) for (int j=0; j < n2; j++) scanf("%d", &matrix2[i][j]);

    if (m1 == m2 && n1 == n2){
        printf("Resultant Matrix after subtracting matrix2 from matrix1 (matrix1 - matrix2): \n");

        for (int i=0; i < m1; i++){
            for (int j=0; j < n1; j++){
                printf("%d ", matrix1[i][j] - matrix2[i][j]);
            }
        printf("\n");
    }
    } else printf("Can't subtract two matrices of different dimenstions\n");  


    return 0;
}