#include "instrucoes.h"
#include "define.h"

Instrucoes* criainstrucoes(int opcode, Endereco* add1, Endereco* add2, Endereco* add3){
	
    Instrucoes *instrucao = (Instrucoes *) malloc(sizeof(Instrucoes));
	
    instrucao->opcode = opcode;
	instrucao->end1 = add1;
	instrucao->end2 = add2;
	instrucao->end3 = add3;
    
    
	return instrucao;
}

Instrucoes **PreencherInstrucoes (){

    FILE *arquivo = fopen ("instrucoes.txt", "r");

    int opcode,
        endBloco1,
        endPalavra1,
        endBloco2,
        endPalavra2,
        endBloco3,
        endPalavra3;
    
    Endereco *end1,
             *end2,
             *end3;


    Instrucoes **preencherInstrucoes = malloc (tamanhoInstrucao * sizeof (Instrucoes*));

    for (int i = 0; i < tamanhoInstrucao ; i++){
        fscanf (arquivo, "%d", &opcode);

        fscanf (arquivo, "%d", &endBloco1);
        fscanf (arquivo, "%d", &endPalavra1);
        
        fscanf (arquivo, "%d", &endBloco2);
        fscanf (arquivo, "%d", &endPalavra2);

        fscanf (arquivo, "%d", &endBloco3);
        fscanf (arquivo, "%d", &endPalavra3);


        end1 = criaEndereco(endBloco1,endPalavra1);
        end2 = criaEndereco(endBloco2,endPalavra2);
        end3 = criaEndereco(endBloco3,endPalavra3);
        
        
        preencherInstrucoes[i] = criainstrucoes(opcode,end1,end2,end3); //funciona
    }
    fclose (arquivo);
    
    return preencherInstrucoes;
}

Endereco* getEnd1(Instrucoes*  i){
	return i->end1;
}

Endereco* getEnd2(Instrucoes*  i){
	return i->end2;
}

Endereco* getEnd3(Instrucoes*  i){
	return i->end3;
}


void setEnd1 (Instrucoes *instrucao, Endereco *end){
   instrucao->end1 = end;
}

void setEnd2(Instrucoes *instrucao, Endereco *end){
    instrucao->end2 = end;
}

void setEnd3(Instrucoes *instrucao, Endereco *end){
    instrucao->end2 = end;
}

int getOpcode (Instrucoes *instrucao){
    return instrucao->opcode;
}

void setOpcode (Instrucoes *instrucao, int opcode){
    instrucao->opcode = opcode;
}