/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdlib.h>
#include <stdio.h>

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q){
    
    if(m == p){
        
        *R = malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++){
            (*R)[i] = malloc(q * sizeof(int));
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < q; j++){
                (*R)[i][j] = 0;
                for (int z = 0; z < p; z++)
                {
                    (*R)[i][j] += A[i][z] * B[z][j];
                }
            }
        }
        return 1;
    }
    else return 0;
}
int** criaMatriz(int x, int y){
    int **matriz ;
    matriz = malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++){
        matriz[i] = malloc(y * sizeof(int));
    }
    return matriz;
}
void liberaMatriz(int **matriz, int x){
    for (int i = 0; i < x; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
int main(){
    int **R;
    int n, m, p, q;

    printf("Digite os indices da matriz A: "); scanf("%d", &n); scanf("%d", &m);

    int **A = criaMatriz(n, m);
    printf("Digite os dados da matriz A:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os indices da matriz B: "); scanf("%d", &p); scanf("%d", &q);
    
    int **B = criaMatriz(p, q);
    printf("Digite os dados da matriz B:\n");
    for (int i = 0; i < p; i++){
        for (int j = 0; j < q; j++){
            scanf("%d", &B[i][j]);
        }
    }
    int res = multiplicaMatrizes(&R, A, n, m, B, p, q);

    if (res){
        printf("Resultado de A x B:\n");
        for (int i = 0; i < n; i++){
            for (int j = 0; j < q; j++){
                printf("%d ", R[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Nao eh possivel multiplicar as matrizes!\n");
    }

    liberaMatriz(A, n);
    liberaMatriz(B, p);
    liberaMatriz(R, p);

    return 0;
}