#include "matriz.h"
#include<stdio.h>

void lerOperacao(char *operacao){
    scanf("%c", operacao);
}

void lerMatriz(double M[][12]){
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            scanf("%lf", &M[i][j]);
        }
    }
    
}

double somaMatriz(double M[][12]){
    double resultado;
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 12; j++){
            if( (j > i) && ((i + j) < 11) ){
                resultado += M[i][j];
            }
        }
    }

    return resultado;
}

double media(double resultado){
    double resMedia;
    resMedia = resultado/30;

    return resMedia;
}

void printResultado(double resultado){
    printf("%.1lf\n", resultado);
}
