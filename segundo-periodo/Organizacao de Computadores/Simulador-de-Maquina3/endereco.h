#ifndef endereco_h
#define endereco_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int endBloco;
    int endPalavra;
}Endereco;

Endereco *criaEndereco(int enderecoBloco, int enderecoPalavra);

int getEndPalavra(Endereco *end);

int getEndBloco(Endereco *end);


#endif