#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

TADfib* alocaTADf (int n, TADfib *f){
    //f = (TADfib*) malloc(n * sizeof (TADfib*));
    for (int i = 0; i < n; i++){
        f = malloc(n * sizeof(TADfib));
    }

    if(f == NULL){
        exit(1);
    }
    return f;
}

long long fibonacci(int i, TADfib *f){
    //printf("Entrei na funcao a primeira vez\n");
    if(i == 0){
        f->chamadas++;
        return 0;
    }
    else if(i == 1){
        f->chamadas++;
        return 1;
    }
    else{
        //printf("entrei no if\n");
        f->chamadas++;
        return (fibonacci(i-1, f) + fibonacci(i-2, f));
    }
}

void desaloca(TADfib *f){
    free(f);
    f = NULL;
}