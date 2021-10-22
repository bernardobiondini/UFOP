#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem){
    scanf("%d", ordem);
}

//manter como especificado
double **alocaMatriz(double **M, int ordem){
    M = (double **) malloc(ordem * sizeof(double *));
    if(M == NULL){
    printf("Memoria insuficiente.\n");
    exit(1);
    }
    for (int i = 0; i < ordem; i++)
    {
        M[i] = (double *) malloc(ordem * sizeof(double));
        if(M[i] == NULL){
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    return M;
}

//manter como especificado
double **desalocaMatriz(double **M, int ordem){
    for (int i = 0; i < ordem; i++)
    {
        free(M[i]);
    }
    free(M);
    *M = NULL;
    return M;
}

//manter como especificado
void lerOperacao(char *operacao){
    scanf(" %c", operacao);
}

void lerMatriz(double **M, int ordem){
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            scanf("%lf", &M[i][j]);
        }
        
    }
    
}

double somaMatriz(double **M, int ordem){
    double resultado = 0.0;
    for (int i = 0; i < (ordem/2 - 1); i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if( (j > i) && ((i + j) < ordem-1) )
            {
                resultado += M[i][j];
            }
        }
    }
    return resultado;
}

double media(double resultado, int ordem){
    resultado = resultado/(ordem * ordem / 4 - ordem/2);
    return resultado;
}

void printResultado(double resultado){
    printf("%.1lf\n", resultado);
}
