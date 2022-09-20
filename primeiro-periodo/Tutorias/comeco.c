#include <stdio.h>
#define z 100

int main(){
    int vet[z][z];
    int N, x;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++){
        scanf("%d", &vet[i][0]);
    }
    for (int j = 1; j <= N; j++){
        vet[0][j] = vet[j][0];
    }
    // a partir desse for os valores da linha 0 e coluna 0 serao iguais aos valores que o usuario digitar

    for (int i = 1; i<=N; i++){
        for (int j = 1; j <= N; j++){
            vet[i][j] = vet[0][j] + vet[i][0];
        }
    }
    printf("Digite o valor de X: "); scanf("%d", &x);
    
    for (int i = 1; i<=N; i++){
        for (int j = 1; j <= N; j++){
            if (vet[i][j] == x){
                printf("%d %d\n", vet[i][0], vet[0][j]);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;

}