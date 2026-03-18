#include <stdio.h>

int main() {
    int m, n, i, j;
    
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    int sum = 0;
    
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for(i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }
    
    printf("%d", sum);
    
    return 0;
}