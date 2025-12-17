#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i <= tc; i++){ 
        int n;
        scanf("%d", &n); 

        int matrix1[n][n], matrix2[n][n], matrix3[n][n];
        int result[n][n]; 

 
        for(int r = 0; r < n; r++){
            for(int j = 0; j < n; j++){
                scanf("%d", &matrix1[r][j]);
            }
        }
        getchar();
        for(int r = 0; r < n; r++){
            for(int j = 0; j < n; j++){
                scanf("%d", &matrix2[r][j]);
            }
        }
        getchar();
        for(int r = 0; r < n; r++){
            for(int j = 0; j < n; j++){
                scanf("%d", &matrix3[r][j]);
            }
        }
        getchar();


        int matrix_result[n][n];
        for(int r = 0; r < n; r++){
            for(int j = 0; j < n; j++){
                matrix_result[r][j] = 0; 
                for(int k = 0; k < n; k++){
                    matrix_result[r][j] += matrix1[r][k] * matrix2[k][j];
                }
            }
        }
        for(int r = 0; r < n; r++){
            for(int j = 0; j < n; j++){
                result[r][j] = 0; 
                for(int k = 0; k < n; k++){
                    result[r][j] += matrix_result[r][k] * matrix3[k][j];
                }
            }
        }


        printf("Case #%d:\n", i);
        for(int r = 0; r < n; r++){
            for(int j = 0; j < n; j++){
                printf("%d", result[r][j]);
                if(j < n - 1){
                    printf(" "); 
                }
            }
            printf("\n");
        }
    }

    return 0;
}
