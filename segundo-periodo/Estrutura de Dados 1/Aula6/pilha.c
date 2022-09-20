#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da pilha
void Pilha_Inicia(Pilha *pilha) {
    pilha->cabeca = (Celula *) malloc(sizeof(Celula));
    pilha->cabeca->proximo = NULL;
//preencher
}

//Retorna se a pilha esta vazia
int Pilha_EhVazia(Pilha *pilha) {
    return (pilha->cabeca->proximo == NULL);
//preencher
}

// Insere um item no topo da pilha
int Pilha_Push(Pilha *pilha, Item item) {
    Celula *celula = (Celula *) malloc(sizeof(Celula));
    if (celula == NULL) return 0;
    celula->item = item;
    celula->proximo = pilha->cabeca->proximo;
    pilha->cabeca->proximo = celula;
//preencher
}

// Retira o item do topo da pilha
int Pilha_Pop(Pilha *pilha, Item *item) {
    if(Pilha_EhVazia(pilha)) return 0;
    Celula *celula = pilha->cabeca->proximo;
    pilha->cabeca->proximo = celula->proximo;
    *item = celula->item;
    free(celula);
    return 1;
//preencher
}

//Remove cada elemento de uma pilha e libera a memória
void Pilha_Esvazia(Pilha *pilha) {
    Celula *celula = pilha->cabeca;
    Celula *aux;
    while(celula != NULL){
        aux = celula->proximo;
        free(celula);
        celula = aux;
    }
//preencher
}
