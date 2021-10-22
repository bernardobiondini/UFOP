/* Programa que le o peso e a altura e informa o IMC relativo
*Bernardo Cavanellas Biondini 
* 20. 1. 4112
* Turma 43 */

#include <stdio.h>
#include <math.h>

int main (){

    double peso, altura;
    printf ("Digite seu peso: "); scanf ("%lf", &peso);
    printf ("Digite sua altura: "); scanf ("%lf", &altura);

    double imc = (peso/ pow(altura, 2));
    
    if (imc < 18.5)
        printf ("Abaixo do peso\n");
    else if ((imc >= 18.5) && (imc < 25))
        printf ("Peso normal\n");
    else if ((imc >= 25) && (imc < 30))   
        printf ("Acima do peso\n");
    else
        printf ("Obeso\n");
}