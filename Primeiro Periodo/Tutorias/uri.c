#include <stdio.h>

typedef struct {
    float M[12][12];
    char O;
} Operacao;

int main(){
    
    Operacao op;

    scanf("%c", &op.O);

    
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            scanf("%f", &op.M[i][j]);
        }
    }
    
    float soma = 0.0;
    int cont = 0;
    

    for (int i = 0; i < 12; i++){
        for (int j = i + 1; j < 12; j++){
            soma += op.M[i][j];
            cont++;
        }
    }

    if (op.O == 'S'){
        printf("%.1f\n", soma);
    }
    else if (op.O == 'M'){
        printf("%.1f\n", soma/cont);
    }
    
    
    return 0;
}