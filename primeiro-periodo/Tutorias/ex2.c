#include <stdio.h>
#define x 50


int main(){
    int mat[x][x], aux[x][x];
    int M,N;

    printf("Digite os valore de M e N: "); scanf("%d", &M); scanf("%d", &N);

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            scanf ("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            aux[i][j] = mat[j][i];
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }

    return 0;
}