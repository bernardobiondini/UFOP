/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#define x 10


void mat(int A[x][x], int B[x][x], int m, int p, int q, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            printf("Digite o valor de linha %d coluna %d da matriz A: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < q; i++){
        for (int j = 0; j < n; j++){
            printf("Digite o valor de linha %d coluna %d da matriz B: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
}

void mult(int A[x][x], int B[x][x], int C[x][x], int m, int p, int q, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = A[i][j] * B[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int A[x][x], B[x][x], C[x][x];

    int p, q, m, n;

    printf("Digite os valores de m, p, q, n: ");
    scanf("%d", &m);
    scanf("%d", &p);
    scanf("%d", &q);
    scanf("%d", &n);

    while (p != q){
        printf("Digite os valores de m, p, q, n: ");
        scanf("%d", &m);
        scanf("%d", &p);
        scanf("%d", &q);
        scanf("%d", &n);
    }

    
    mat(A, B, m, p, q, n);

    mult(A, B, C, m, p, q, n);

    return 0;
}

