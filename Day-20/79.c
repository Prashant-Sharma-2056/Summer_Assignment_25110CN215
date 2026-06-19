// WAP to find row-wise sum
#include <stdio.h>

int main(){
    int matrix[10][10], m, n;

    printf("Enter the dimensions for first matrix (m,n): \n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of first matrix: \n");
    for (int i=0; i < m; i++) for (int j=0; j < n; j++) scanf("%d", &matrix[i][j]);
    
    int sum=0;
    printf("ROW-WISE SUM:\n");
    for (int i=0; i < m; i++){
        sum=0;
        for (int j=0; j < n; j++){
            sum += matrix[i][j];
        }
        printf("%d \n", sum);
    }


    return 0;
}