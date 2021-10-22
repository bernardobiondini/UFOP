#include <stdio.h>
#define x 20

int main ()
{
    int N[x];
    for (int i=0; i < x; i++)
    {
        scanf ("%d", &N[i]);
    }
    int aux[x];
    for (int i = x - 1; i >= 0; i--)
    {
        aux[i] = N[x - i - 1];
    }
    for (int i=0; i < x; i++){
        N[i] = aux[i];
        printf ("N[%d] = %d\n", i, N[i]);
    }
    return 0;
}