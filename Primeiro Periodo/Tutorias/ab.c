/*Faça um algoritmo que leia dois valores inteiros A e B, se os valores forem iguais deverá se
*somar os dois, caso contrário multiplique A por B. Ao final de qualquer um dos cálculos
*deve-se atribuir o resultado para uma variável C e mostrar seu conteúdo na tela.
*/

#include <stdio.h>

int main (){

    int A, B;
    printf ("Valor de A:"); scanf ("%d", &A);
    printf ("Valor de B: "); scanf ("%d", &B);

    if (A == B){
        int C = A + B;
        printf ("C = %d\n", C);
    }
    else {
        int C = A * B;
        printf ("C = %d\n", C);
    }
    return 0;
    
}