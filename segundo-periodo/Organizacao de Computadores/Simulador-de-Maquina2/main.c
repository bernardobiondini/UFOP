#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#include "mmu.h"
#include "maquina.h"
#include "blocodememoria.h"


int main(){
    
    clock_t tempo;

    blocoMemoria **RAM = criaMemoriaRAM();
    blocoMemoria **cache1 = criaMemoriaCache(tamanhoCache01);
    blocoMemoria **cache2 = criaMemoriaCache(tamanhoCache02);
    blocoMemoria **cache3 = criaMemoriaCache(tamanhoCache03);
   
   //imprimeR(RAM, tamanhoRam);

    tempo = clock(); //aloca tempo inicial 

    maquina(cache1, cache2, cache3, RAM);

    tempo = clock() - tempo;
    double *tempoPrograma = malloc (sizeof(double));
    *tempoPrograma = ((double)tempo)/((CLOCKS_PER_SEC/1000));

    printf("\nTempo de execucao: %.2lf ms.\n\n", *tempoPrograma);


    liberaMemoria(cache1, cache2, cache3, RAM, tempoPrograma);
    printf("DEU TUDO CERTO!\n");
    return 0;
}