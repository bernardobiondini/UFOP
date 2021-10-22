#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    pLista->pPrimeiro = (TCelula *) malloc (sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
//semelhante ao visto em aula
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista){
    return (pLista->pPrimeiro == pLista->pUltimo);
//semelhante ao visto em aula
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
    pLista->pUltimo->pProx =( TCelula *) malloc (sizeof (TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx ;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL ;
    return 1;
//semelhante ao visto em aula
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    if (TLista_EhVazia (pLista)) return 0;
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    *pX = pAux->item;
    pLista->pPrimeiro->pProx = pAux->pProx;
    free (pAux);
    return 1;
//semelhante ao visto em aula
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    while(pAux != NULL){
        if(pAux == pLista->pUltimo){
            printf("%s\n", pAux->item.nome);
            pAux = pAux->pProx;
        } 
        else{
            printf("%s ", pAux->item.nome);
            pAux = pAux->pProx;
        }
        
    }
//semelhante ao visto em aula
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    while(pAux != NULL){
        pLista->pPrimeiro->pProx = pAux->pProx;
        pAux = pAux->pProx;
        free(pAux);
    }
//preencher
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
    pLista1->pUltimo->pProx = (TCelula *) malloc (sizeof (TCelula));
    pLista1->pUltimo->pProx = pLista2->pPrimeiro->pProx;
    pLista1->pUltimo = pLista2->pUltimo;
//preencher
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
    //printf("\nO ultimo nome e %s\n", str);
    TCelula *pAux, *pAntPAux;
    pAux = pLista1->pPrimeiro; //pAux aponta pra Lista1
    while(strcmp(pAux->item.nome, str) != 0){
        pAntPAux = pAux;
        pAux = pAux->pProx;
    } //dessa forma terei acesso ao anterior do item desejado
    //printf("opa!\n");
    pAntPAux->pProx = pLista2->pPrimeiro->pProx; //o proximo do anterior recebe a Lista 2
    pLista2->pUltimo->pProx = pAux; //e o final da lista2 recebe o resto da lista1 a partir do item desejado
//preencher
}
// void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
//     TCelula *pAux;
//     pAux = pLista1->pPrimeiro;
//     while(pAux != pLista1->pUltimo){
//         if(strcmp(pAux->pProx->item.nome, str) == 0){
//             break;
//         }
//         pAux = pAux->pProx;
//     }
//     pLista2->pUltimo->pProx = pAux->pProx;
//     pAux->pProx = pLista2->pPrimeiro->pProx;
//     pLista1->pUltimo->pProx = NULL;
// }