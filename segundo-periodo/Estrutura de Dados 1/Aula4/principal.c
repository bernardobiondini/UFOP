#include "fib.h"
#include<stdio.h>

int main()
{
    int n;
    TADfib *f = NULL;
    
    scanf("%d", &n);

    f = alocaTADf(n, f);

    //printf("aloquei?\n");
    for (int j = 0; j < n; j++){
        //printf("for?\n");
        f[j].chamadas = -1;
        scanf("%d", &f[j].i);
        //printf("%d?\n", f[j].i);
        f[j].resultado = fibonacci(f[j].i, &f[j]);
    }
    
    for (int j = 0; j < n; j++){
        printf("fib(%d) = %lld chamadas = %lld\n", f[j].i, f[j].chamadas, f[j].resultado);
    }

    desaloca(f);

    return 0;//nao remova
}
