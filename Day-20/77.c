// WAP to Multiply Matrices
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


    int results[10][10], m=m1, n=n2, sum;

    if (m2 == n1){
        for (int i=0; i < m; i++){
            for (int j=0; j < n; j++){
                sum = 0;
                for (int k=0; k < m2; k++) sum += matrix1[i][k] * matrix2[k][j];
                results[i][j] = sum;
            }
        }

        printf("Resultant Matrix after multiplying the given matrices: \n");

        for (int i=0; i < m; i++){
            for (int j=0; j < n; j++){
                printf("%d ", results[i][j]);
            }
            printf("\n");
        }

    } else printf("Can't multiply matrices with given dimensions\n");

    return 0;
}