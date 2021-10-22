#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n){
    heap = (TipoCaixa*) malloc(n * sizeof(TipoCaixa));
    if(heap == NULL) exit(0);
    return heap;
}

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap){
    free(heap);
    heap = NULL;
    return heap;
}

//Manter como especificado
void Heap_Constroi(TipoCaixa *heap, int n){
    int esq;

    esq = (n/2) - 1; // esq = primeiro no antes do no folha do heap
    
    while (esq >= 0){
        Heap_Refaz(heap, esq, n - 1);
        esq--;
    }
}

//Manter como especificado
void Heap_Refaz(TipoCaixa *heap, int esq, int dir){
    int i, j;
    TipoCaixa aux;
    
    i = esq;
    j = i * 2 + 1;
    aux = heap[i];
    
    while (j <= dir){
        
        if ((j < dir && heap[j].tempoCompra > heap[j+1].tempoCompra) ||
           (j < dir && heap[j].id > heap[j+1].id && heap[j].tempoCompra == heap[j+1].tempoCompra)) j = j + 1; // j recebe o outro filho de i
    
        if ((aux.tempoCompra < heap[j].tempoCompra) || 
            (aux.tempoCompra == heap[j].tempoCompra && aux.id < heap[j].id)) break;
        
        heap[i] = heap[j];
        i = j;
        j = i * 2 + 1;
    }
    
    heap[i] = aux;
}
