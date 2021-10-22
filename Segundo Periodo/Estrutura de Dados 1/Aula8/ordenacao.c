#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
    vetor = (int*) malloc(n * sizeof(int));
    if(vetor == NULL) exit(0);
    return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
    vetor = NULL;
    return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
    int i, j, k, tamA, tamB, esq, dir, b = 1;
    *movimentos = 0;
    while (b < n) {
        esq = 0;
        while ( esq + b < n) {
            dir = esq + 2 * b ;
            if ( dir > n) 
                dir = n;
            dir--;
            tamA = (esq + b- 1) - esq + 1;
            tamB = dir - (esq + b- 1);
            
            int *v1 = (int *) malloc (sizeof(int) * tamA);
            int *v2 = (int *) malloc (sizeof(int) * tamB);
            
            for (i = 0; i < tamA ; i ++) 
                v1[i] = vetor[i + esq];
            for (i = 0; i < tamB ; i ++) 
                v2[i] = vetor[i + (esq + b- 1) + 1];
            
            for (i = 0, j = 0 , k = esq ; k <= dir ; k ++) {
                if (i == tamA){ 
                    vetor[k] = v2[j++];
                }
                else if (j == tamB) {
                    vetor[k] = v1[i++];
                }
                else if ( v1[i] < v2[j]){
                    vetor[k] = v1[i++];
                }
                else{
                    vetor[k] = v2[j++];
                    *movimentos += tamA - i;
                }
            }
            free (v1) ; free (v2);
            esq = esq + 2 * b ;
        }
        b *= 2;
    }
}
