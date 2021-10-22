/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 
*/

#include <stdlib.h>
#include <stdio.h>

int verificaQuadro(int **matriz, int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < n; l++){
                for(int c = 0; c < n; c++){
                    if(matriz[i][j] == matriz[l][c] && l != i && c != j) return 0;
                }
            }
        }
    }
    
    int *somaLinha = malloc(n * sizeof(int));
    int *somaColuna = malloc(n * sizeof(int));
    int somaDiagonal = 0, somaDiagonal2 = 0;
    
    for (int i = 0; i < n; i++){
        somaLinha[i] = 0;
        somaColuna[i] = 0;
        for(int j = 0; j < n; j++){
            somaLinha[i] += matriz[i][j]; 
            somaColuna[i] += matriz[j][i];
        }
    }

    int contLinha = 0, contColuna = 0;
    for (int i = 0; i < n; i++){
        if(somaLinha[0] == somaLinha[i]) contLinha++;
        if(somaColuna[0] == somaColuna[i]) contColuna++;
    }
    if ((contLinha == n) && (contColuna == n)){
        int k = n - 1;
        for(int i = 0; i < n; i++){
            somaDiagonal += matriz[i][i];
            somaDiagonal2 += matriz[i][k];
            k--;
        }
        if((somaDiagonal2 == somaDiagonal) && (somaDiagonal == somaLinha[0])) {
            free(somaLinha);
            free(somaColuna);
            return 1;
        }
        else {
            free(somaLinha);
            free(somaColuna);
            return 0;
        }
    }
    free(somaLinha);
    free(somaColuna);

    return 0;
}
void liberaMatriz(int **matriz, int x){
    for (int i = 0; i < x; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int main(){
    int n;
    printf("Digite o valor de n: "); scanf("%d", &n);
    int **matriz = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++){
        matriz[i] = malloc(n * sizeof(int));
    }
    printf("Digite os valores da matriz n x n:\n");
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    int res = verificaQuadro(matriz, n);
    if(res){
        printf("Essa matriz eh um quadrado magico!\n");
    }
    else printf("Essa matriz nao eh um quadrado magico!\n");

    liberaMatriz(matriz, n);

    return 0;
}