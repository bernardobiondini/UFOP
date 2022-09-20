#ifndef blocodememoria_h
#define blocodememoria_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "define.h"
#include "endereco.h"


typedef struct{
    Endereco *end;
    int palavra[tamanhoPalavra];
    bool atualizado;
    time_t tempo;
}blocoMemoria;


blocoMemoria **criaMemoriaRAM();

blocoMemoria **criaMemoriaCache(int tamanho);

void limpaBlocoMemoria(blocoMemoria *bloco);

blocoMemoria *criablocoMemoriaCache();

blocoMemoria *criablocoMemoriaRAM();

void liberaMemoria(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **Ram, double *tempo);

blocoMemoria *getBloco(blocoMemoria **bloco, int posicao);

void setBloco(blocoMemoria **bloco, blocoMemoria *novo, int posicao);

int getPalavra(blocoMemoria *bloco, int posicao);

void setPalavra(blocoMemoria *bloco, int palavra, int posicao);

int getEnderecoBloco(blocoMemoria *bloco);

void setEnderecoBloco(blocoMemoria *bloco, int endereco);

long int getCusto(long int *vetor, int posicao);

void setCusto(long int *vetor, int posicao, int custo);

bool isAtualizado(blocoMemoria* bloco);

void setAtualizado(blocoMemoria* bloco);

void setDesatualizado(blocoMemoria* bloco);

long int getHit(long int *vetor, int posicao);

long int getMiss(long int *vetor, int posicao);

void setHit(long int *vetor, int posicao);

void setMiss(long int *vetor, int posicao);


time_t getTempo(blocoMemoria *bloco);

void setTempo(blocoMemoria *bloco, time_t tempo);

#endif