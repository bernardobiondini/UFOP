/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdlib.h>
#include <stdio.h>


double** transposta(double **A, int x, int y){
    double **matriz ;
    matriz = malloc(y * sizeof(double *));
    for (int i = 0; i < y; i++){
        matriz[i] = malloc(x * sizeof(double));
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            matriz[i][j] = A[j][i];
        }
    }
    return matriz;
}
double** criaMatriz(int x, int y){   
    double **matriz;
    matriz = malloc(x * sizeof(double *));
    for (int i = 0; i < x; i++){
        matriz[i] = malloc(y * sizeof(double));
    }
    return matriz;
}
 
void liberaMatriz(double **matriz, int x){
    for (int i = 0; i < x; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
int main(){
    double **M, **T;
    int m, n;
    
    printf("Digite os indices m e n da matriz: "); scanf("%d %d", &m, &n);

    M = criaMatriz(m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite o valor %d x %d da matriz: ", i+1, j+1);
            scanf("%lf", &M[i][j]);
        }
        
    }
        
    T = transposta(M, m, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.2lf ", T[i][j]);
        }
        printf("\n");
    }

    liberaMatriz(M, m);
    liberaMatriz(T, n);

    return 0;
}