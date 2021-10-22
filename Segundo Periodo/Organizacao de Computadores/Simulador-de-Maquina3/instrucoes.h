#ifndef instucoes_h
#define instrucoes_h

#include <stdio.h>
#include <stdlib.h>

#include "endereco.h"
#include "blocodememoria.h"

typedef struct{
    int opcode;
    Endereco *end1;
    Endereco *end2;
    Endereco *end3;
}Instrucoes;

Instrucoes* criainstrucoes(int opcode, Endereco* ad1, Endereco* ad2, Endereco* ad3);

Instrucoes **PreencherInstrucoes ();

Endereco* getEnd1(Instrucoes*  i);

Endereco* getEnd2(Instrucoes*  i);

Endereco* getEnd3(Instrucoes*  i);

void setEnd1 (Instrucoes *instrucao, Endereco *end);

void setEnd2(Instrucoes *instrucao, Endereco *end);

void setEnd3(Instrucoes *instrucao, Endereco *end);

int getOpcode (Instrucoes *instrucao);

void setOpcode (Instrucoes *instrucao, int opcode);


#endif