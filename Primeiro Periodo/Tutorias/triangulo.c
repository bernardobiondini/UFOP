/*Os lados de qualquer triângulo respeitam a seguinte restrição: A soma dos comprimentos de
*quaisquer dois lados de um triângulo é superior ao comprimento do terceiro lado.
*Escreva um algoritmo que receba o comprimento dos três segmentos de reta e imprima na
*tela se a restrição foi respeitada ou não.
*/

#include <stdio.h>

int main (){
    
    int A, B, C;
    printf ("Digite os lados do triangulo:\n");
    printf ("A: "); scanf ("%d", &A);
    printf ("B: "); scanf ("%d", &B);
    printf ("C: "); scanf ("%d", &C);

    if ((A < B + C) && (B < A + C) && (C < B + A)){
        printf ("Respeita a restricao\n");
    }
    else {
        printf ("Nao respeita a restricao\n");
    }
    return 0;
    
}