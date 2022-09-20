#include "maquina.h"

void maquina(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **RAM){
    int op;
    int endereco1 = 0;
    int endereco2 = 0;
    int resultado = 0;
    int PC = 0;
    long int miss[4], hit[4], custo[4],
            custoC1 = 0, custoC2 = 0, custoC3 = 0, custoRam = 0, 
            hitTotal = 0, missTotal = 0,
            custoTotal = 0, hitRAM = 0,
            missC1 = 0, hitC1 = 0,
            missC2 = 0, hitC2 = 0,
            missC3 = 0, hitC3 = 0;
        
    Instrucoes **umaInstrucao;

    for (int i = 0; i < 4; i++)
    {
        miss[i] = 0;
        hit[i] = 0;
        custo[i] = 0;
    }
    

    umaInstrucao = PreencherInstrucoes();
    op = umaInstrucao[PC]->opcode;

    while(op != -1){

        op = umaInstrucao[PC]->opcode;
        
        switch(op){
            case 0:
                endereco1 = getPalavra(MMU(cache1, cache2, cache3, RAM, umaInstrucao[PC]->end1, hit, miss, custo), umaInstrucao[PC]->end1->endPalavra);
                endereco2 = getPalavra(MMU(cache1, cache2, cache3, RAM, umaInstrucao[PC]->end2, hit, miss, custo), umaInstrucao[PC]->end2->endPalavra);
                resultado = endereco1 + endereco2;
                
                printf("Somando %d com %d e obtendo: %d. \n", endereco1, endereco2, resultado);
                setPalavra(MMU(cache1, cache2, cache3, RAM, umaInstrucao[PC]->end3, hit, miss, custo), resultado, umaInstrucao[PC]->end3->endPalavra);

            break;

            case 1:
                
                endereco1 = getPalavra(MMU(cache1, cache2, cache3, RAM, umaInstrucao[PC]->end1, hit, miss, custo), umaInstrucao[PC]->end1->endPalavra);
                endereco2 = getPalavra(MMU(cache1, cache2, cache3, RAM, umaInstrucao[PC]->end2, hit, miss, custo), umaInstrucao[PC]->end2->endPalavra);
                
                resultado = endereco1 - endereco2;
                
                printf("Subtraindo %d com %d e obtendo %d\n", endereco1, endereco2, resultado);
                setPalavra(MMU(cache1, cache2, cache3, RAM, umaInstrucao[PC]->end3, hit, miss, custo), resultado, umaInstrucao[PC]->end3->endPalavra);
               
        
            break;

            case (-1):
                printf("\n_____________________________________________________\n");
                printf("Nao ha demanda por levar dados para as memorias.\n");
                printf("______________________________________________________\n");
                levaParaRAM(cache1, cache2, cache3, RAM);
            break;
        }
         
        PC++;
        //imprimeR(RAM, tamanhoRam);
    }

    free(umaInstrucao);

    hitC1 = getHit(hit, 1);
    hitC2 = getHit(hit, 2);
    hitC3 = getHit(hit, 3);
    hitRAM = getHit(hit, 0);

    missC1 = getMiss(miss, 1);
    missC2 = getMiss(miss, 2);
    missC3 = getMiss(miss, 3);

    custoC1 = getCusto(custo, 1);
    custoC2 = getCusto(custo, 2);
    custoC3 = getCusto(custo, 3);
    custoRam = getCusto(custo, 0);
    
    missTotal = missC1 + missC2 + missC3;
    hitTotal = hitC1 + hitC2 + hitC3 + hitRAM;
    custoTotal = custoC1 + custoC2 + custoC3 + custoRam;

    printf("\n ____________________");
    printf("\n|     RESULTADOS     | \n" );
    printf(  "|____________________|\n\n");

    printf("| TAMANHO CACHE 1 -> %d|\n", tamanhoCache01);
    printf("| TAMANHO CACHE 2 -> %d|\n", tamanhoCache02);
    printf("| TAMANHO CACHE 3 -> %d|\n", tamanhoCache03);
    printf("| TAMANHO RAM     -> %d|\n\n", tamanhoRam);

    printf("| HIT CACHE 1 -> %ld | MISS CACHE 1 -> %ld |\n", hitC1, missC1);
    printf("| HIT CACHE 2 -> %ld | MISS CACHE 2 -> %ld |\n", hitC2, missC2);
    printf("| HIT CACHE 3 -> %ld | MISS CACHE 3 -> %ld |\n", hitC3, missC3);
    printf("| HIT RAM     -> %ld |\n", hitRAM);

    printf("\n| HIT TOTAL   -> %ld | MISS TOTAL   -> %ld |\n", hitTotal, missTotal);
    
    printf("\n| CUSTO CACHE 1 -> %ld |", custoC1);
    printf("\n| CUSTO CACHE 2 -> %ld |", custoC2);
    printf("\n| CUSTO CACHE 3 -> %ld |", custoC3);
    printf("\n| CUSTO RAM      -> %ld|", custoRam);
    printf("\n\n| CUSTO TOTAL    -> %ld|\n\n", custoTotal);

}