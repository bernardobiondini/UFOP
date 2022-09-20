#include "maquina.h"

void maquina(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **RAM){
    int op;
    int endereco1 = 0;
    int endereco2 = 0;
    int resultado = 0;
    int PC = 0;
    long int miss[5], hit[5], custo[5],
            custoC1 = 0, custoC2 = 0, custoC3 = 0, custoRam = 0, custoHd = 0, custoTotal = 0, 
            hitTotal = 0, hitRAM = 0, hitC1 = 0, hitC2 = 0, hitC3 = 0, hitHd = 0,
            missTotal = 0, missC1 = 0, missC2 = 0, missC3 = 0, missRam = 0;
        
    Instrucoes **umaInstrucao;

    for (int i = 0; i < 5; i++)
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

        srand(PC);
        int random = rand() % 11;
        

        if (random == 0){
            printf("\nExecutando interrupção do teclado!\n");
            interrupcoes(cache1, cache2, cache3, RAM, hit, miss, custo);
            printf("\nFim das interrupcoes do teclado!\n");
        } else if (random == 1){
            printf("\nExecutando interrupção do mouse!\n");
            interrupcoes(cache1, cache2, cache3, RAM, hit, miss, custo);
            printf("\nFim das interrupcoes do mouse!\n");
        } else if (random == 2){
            printf("\nExecutando interrupção da camera!\n");
            interrupcoes(cache1, cache2, cache3, RAM, hit, miss, custo);
            printf("\nFim das interrupcoes da camera!\n");
        }  
            
        PC++;
    }

    free(umaInstrucao);


    hitC1 = getHit(hit, 1);
    hitC2 = getHit(hit, 2);
    hitC3 = getHit(hit, 3);
    hitRAM = getHit(hit, 0);
    hitHd = getHit(hit, 4);

    missC1 = getMiss(miss, 1);
    missC2 = getMiss(miss, 2);
    missC3 = getMiss(miss, 3);
    missRam = getMiss(miss,0);


    custoC1 = getCusto(custo, 1);
    custoC2 = getCusto(custo, 2);
    custoC3 = getCusto(custo, 3);
    custoRam = getCusto(custo, 0);
    custoHd = getCusto(custo, 4);
    
    missTotal = missC1 + missC2 + missC3 + missRam;
    hitTotal = hitC1 + hitC2 + hitC3 + hitRAM + hitHd;
    custoTotal = custoC1 + custoC2 + custoC3 + custoRam + custoHd;

    printf("\n ________________________");
    printf("\n|  :D   RESULTADOS  :D   | \n" );
    printf(  "|________________________|\n\n");

    printf("| TAMANHO CACHE 1 -> %d|\n", tamanhoCache01);
    printf("| TAMANHO CACHE 2 -> %d|\n", tamanhoCache02);
    printf("| TAMANHO CACHE 3 -> %d|\n", tamanhoCache03);
    printf("| TAMANHO RAM     -> %d|\n", tamanhoRam);
    printf("| TAMANHO HD      -> %d|\n\n", tamanhoHD);

    printf("| HIT CACHE 1 -> %ld | MISS CACHE 1 -> %ld |\n", hitC1, missC1);
    printf("| HIT CACHE 2 -> %ld | MISS CACHE 2 -> %ld |\n", hitC2, missC2);
    printf("| HIT CACHE 3 -> %ld | MISS CACHE 3 -> %ld |\n", hitC3, missC3);
    printf("| HIT RAM     -> %ld | MISS RAM     -> %ld |\n", hitRAM, missRam);
    printf("| HIT HD      -> %ld | \n", hitHd);

    printf("\n| HIT TOTAL   -> %ld | MISS TOTAL   -> %ld |\n", hitTotal, missTotal);
    
    printf("\n| CUSTO CACHE 1 -> %ld |", custoC1);
    printf("\n| CUSTO CACHE 2 -> %ld |", custoC2);
    printf("\n| CUSTO CACHE 3 -> %ld |", custoC3);
    printf("\n| CUSTO RAM     -> %ld|", custoRam);
    printf("\n| CUSTO HD      -> %ld|", custoHd);
    printf("\n\n| CUSTO TOTAL    -> %ld|\n\n", custoTotal);
    
}
void interrupcoes(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **RAM, long int hit[5], long int miss[5], long int custo[5]){
    
    FILE *arquivo = fopen ("interrupcoes.txt", "r");
    
    int op;
    int endereco1 = 0;
    int endereco2 = 0;
    int resultado = 0;
    int PC = 0;
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


    Instrucoes **preencherInstrucoes = malloc (tamanhoInterrupcao * sizeof (Instrucoes*));

    for (int i = 0; i < tamanhoInterrupcao; i++){
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
        
        
        preencherInstrucoes[i] = criainstrucoes(opcode,end1,end2,end3); 
    }
    fclose (arquivo);
    op = 0;

    while(op != -1){

        op = preencherInstrucoes[PC]->opcode;
        
        switch(op){
            case 0:
                endereco1 = getPalavra(MMU(cache1, cache2, cache3, RAM, preencherInstrucoes[PC]->end1, hit, miss, custo), preencherInstrucoes[PC]->end1->endPalavra);
                endereco2 = getPalavra(MMU(cache1, cache2, cache3, RAM, preencherInstrucoes[PC]->end2, hit, miss, custo), preencherInstrucoes[PC]->end2->endPalavra);
                resultado = endereco1 + endereco2;
                
                printf("Somando %d com %d e obtendo: %d. \n", endereco1, endereco2, resultado);
                setPalavra(MMU(cache1, cache2, cache3, RAM, preencherInstrucoes[PC]->end3, hit, miss, custo), resultado, preencherInstrucoes[PC]->end3->endPalavra);

            break;

            case 1:
                
                endereco1 = getPalavra(MMU(cache1, cache2, cache3, RAM, preencherInstrucoes[PC]->end1, hit, miss, custo), preencherInstrucoes[PC]->end1->endPalavra);
                endereco2 = getPalavra(MMU(cache1, cache2, cache3, RAM, preencherInstrucoes[PC]->end2, hit, miss, custo), preencherInstrucoes[PC]->end2->endPalavra);
                
                resultado = endereco1 - endereco2;
                
                printf("Subtraindo %d com %d e obtendo %d. \n", endereco1, endereco2, resultado);
                setPalavra(MMU(cache1, cache2, cache3, RAM, preencherInstrucoes[PC]->end3, hit, miss, custo), resultado, preencherInstrucoes[PC]->end3->endPalavra);
               
        
            break;

            case (-1):
                printf("\n_____________________________________________________\n");
                printf("Nao ha demanda por levar dados para as memorias.\n");
                printf("______________________________________________________\n");
                levaParaRAM(cache1, cache2, cache3, RAM);
            break;
        }
         
        PC++;
    }

    free(preencherInstrucoes);
}