/* Programa que le a idade de de alguem e determina o valor do plano de saude
*Bernardo Cavanellas Biondini 
* 20. 1. 4112
* Turma 43 */

#include <stdio.h>

int main(){
    
    int idade;
    printf ("Digite sua idade: "); scanf ("%d", &idade);

    if (idade > 65)
            printf ("Valor: R$695,00\n");
    else if ((idade > 59) && (idade <= 65))
            printf ("Valor : R$515,00\n");
    else if ((idade > 45) && (idade <= 59))
            printf ("Valor : R$400,00\n");
    else if ((idade > 29) && (idade <= 45))
            printf ("Valor : R$290,00\n");   
    else if ((idade > 10) && (idade <= 29))
            printf ("Valor : R$170,00\n");
    else
            printf ("Valor : R$90,00\n");        

    return 0;
}