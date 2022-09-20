#include <stdio.h>
#include <stdlib.h>

int main(){
    char caractere;
    int digito;
    int numeros = 11, multiplicando = 11;
    double resultado = 0;

    while(numeros > 0){
        scanf("%c", &caractere);
        digito = (int)caractere - 48;
        __fpurge(stdin);        //printf("%d\n", digito);

        resultado += multiplicando * caractere;
        numeros--;
        multiplicando--;
    }

    printf("resultado: %.0lf\n", resultado);

    return 0;
}