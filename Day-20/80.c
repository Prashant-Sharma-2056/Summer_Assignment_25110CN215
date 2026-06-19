// WAP to find column-wise sum
#include <stdio.h>

int main(){
    int matrix[10][10], m, n;

    printf("Enter the dimensions for first matrix (m,n): \n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of first matrix: \n");
    for (int i=0; i < m; i++) for (int j=0; j < n; j++) scanf("%d", &matrix[i][j]);
    
    int sum=0;
    printf("COLUMN-WISE SUM:\n");
    for (int i=0; i < n; i++){
        sum=0;
        for (int j=0; j < m; j++){
            sum += matrix[j][i];
        }
        printf("%d ", sum);
    }
    
    return 0;
}