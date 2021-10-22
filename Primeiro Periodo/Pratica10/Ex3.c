/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <stdlib.h>

void liberaMatriz(double **matriz, int linha){
    for (int i = 0; i < linha; i++)
        free(matriz[i]);
    free(matriz);
}

int main(){
    int m, n;
    printf("Digite o numero de linhas e de colunas da matriz: "); scanf("%d %d", &m, &n);

    double **A = malloc(m * sizeof(double*));
    double **B = malloc(m * sizeof(double*));
    double **C = malloc(m * sizeof(double*));

    for(int i = 0; i < n; i++){
        A[i] = malloc(n * sizeof(double));
        B[i] = malloc(n * sizeof(double));
        C[i] = malloc(n * sizeof(double));
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Digite os valores da linha %d e da coluna %d da matriz A: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Digite os valores da linha %d e da coluna %d da matriz B: ", i, j);
            scanf("%lf", &B[i][j]);
        }
    }
    
    printf("Matriz C = ");
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
            printf("%.2lf  ", C[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    liberaMatriz(A, m);
    liberaMatriz(B, m);
    liberaMatriz(C, m);

    return 0;
}