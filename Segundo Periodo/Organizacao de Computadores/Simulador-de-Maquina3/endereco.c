#include "endereco.h"

Endereco *criaEndereco(int enderecoBloco, int enderecoPalavra){

    Endereco *end = (Endereco*) malloc(sizeof(Endereco));

    end->endBloco = enderecoBloco;
    end->endPalavra = enderecoPalavra;

    return end;
}

int getEndPalavra(Endereco *end){
    return end->endPalavra;
}

int getEndBloco(Endereco *end){
    return end->endBloco;
}


