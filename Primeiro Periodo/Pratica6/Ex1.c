/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */
#include <stdio.h>
#define n 10

int main()
{
    int vet[n];
    for (int i=0; i <=1; i++)
    {
        vet[i] = 1;
        printf("%d ", vet[i]);
    }
    for (int i=2; i < n; i++)
    {
        vet[i] = vet[i-1] + vet[i-2];
        printf("%d ", vet[i]);
    }
    printf("\n");
    return 0;
}