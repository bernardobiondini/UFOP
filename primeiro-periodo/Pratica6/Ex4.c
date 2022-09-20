/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */
#include <stdio.h>
#define x 15

int main ()
{
    int vet[x];
    for (int i=0; i < x; i++)
    {
        printf ("Digite o valor %d: ", i+1); scanf ("%d", &vet[i]);
    }
    int n;
    printf ("Digite quantas posicoes os numeros irao rotacionar: "); scanf ("%d", &n);
    int aux[x];
    for (int i = 0; i < x - n; i++)
    {
        aux[i]= vet[i+n];
    }
    for (int i = x - n; i < x; i++)
    {
        aux[i] = vet[n+i-x];
    }
    for (int i=0; i < x; i++){
        vet[i] = aux[i];
        printf ("%d ", vet[i]);
    }
    printf ("\n");
    return 0;
}