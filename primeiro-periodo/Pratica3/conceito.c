/* Programa que identifica o conceito do aluno
*Bernardo Cavanellas Biondini 
* 20. 1. 4112
* Turma 43 */

#include <stdio.h>

int main(){

    char c;
    printf ("Digite o conceito do aluno: "); scanf ("%c", &c);

    switch (c){
        case ('A'):
        printf ("Excelente\n");
        break;
        case ('B'):
        printf ("Otimo\n");
        break;
        case ('C'):
        printf ("Bom\n");
        break;
        case ('D'):
        printf ("Regular\n");
        break;
        case ('E'):
        printf ("Ruim\n");
        break;
        case ('F'):
        printf ("Nos vemos de novo ano que vem...\n");
        break;
        default:
        printf ("Conceito inexistente\n");
    }
    return 0;
}