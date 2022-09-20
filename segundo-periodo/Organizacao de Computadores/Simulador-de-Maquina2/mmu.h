#ifndef mmu_h
#define mmu_h


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "define.h"
#include "blocodememoria.h"
#include "endereco.h"

int procuraPosicao(blocoMemoria **cache, Endereco *end, int tamanho);
void imprimeR(blocoMemoria **cache, int tamanho);
void transfereBloco(blocoMemoria *blocoDestino, blocoMemoria *blocoOrigem);
void trocaBloco(int posicaoDestino, int posicaoOrigem, blocoMemoria **blocoDestino, blocoMemoria **blocoOrigem);
int LFU(blocoMemoria **cache, int tamanho);
blocoMemoria *MMU(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **RAM, Endereco *end, 
                    long int hit[4], long int miss[4], long int custo[4]);
void levaParaRAM(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **RAM);

#endif
