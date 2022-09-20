/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 100000

void vezes (int n, long *vetor)
{
    for (int i=1; i<=n; i++)
    {
        printf ("O numero %d repetiu %ld vez(es)\n", i, vetor[i]);
    }
}


int main()
{
    int n;
    printf ("Digite o valor de n menor ou igual a 500: "); scanf ("%d", &n);
    while (n > 500){
        printf ("Digite o valor de n menor ou igual a 500: "); scanf ("%d", &n);
    }
    long Ale[x];
    long A[n];
    srand (time(NULL));
    for (int i=0; i<x; i++)
    {
        Ale[i] = 1 + (rand() % n);
    }
    for (int i = 0; i <= n; i++){
        A[i] = 0;
        
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n; j++){
        if (Ale[i] == j){
            A[j]++;
        }
        }
    }
    vezes (n, A);
    printf ("\n");
    return 0;
}