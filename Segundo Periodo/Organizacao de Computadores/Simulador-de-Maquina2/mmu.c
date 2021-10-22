#include "mmu.h"
#include <time.h>

int procuraPosicao(blocoMemoria **cache, Endereco *end, int tamanho){
    for (int i = 0; i < tamanho; i++){
        
        if ((cache[i]->end->endBloco) == (end->endBloco)){
            return i;
        }
    }
    return -1;
}

void imprimeR(blocoMemoria **cache, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("end = %d\n", cache[i]->end->endBloco);
    }
}

int procuraPosicaoVazia(blocoMemoria **cache, int tamanho){
    int vazio;

    for (int i = 0; i < tamanho; i++){
        if (cache[i]->end->endBloco == -1){
            vazio = i;
            return vazio;
        }
    }
    return -1;
}

void transfereBloco(blocoMemoria *blocoDestino, blocoMemoria *blocoOrigem){

    blocoDestino->end->endBloco = blocoOrigem->end->endBloco;
    blocoDestino->end->endPalavra = blocoOrigem->end->endPalavra; 
    blocoDestino->atualizado = blocoOrigem->atualizado;
    blocoDestino->palavra[0] = blocoOrigem->palavra[0];
    blocoDestino->palavra[1] = blocoOrigem->palavra[1];
    blocoDestino->palavra[2] = blocoOrigem->palavra[2];
    blocoDestino->palavra[3] = blocoOrigem->palavra[3];
}

void trocaBloco(int posicaoDestino, int posicaoOrigem, blocoMemoria **blocoDestino, blocoMemoria **blocoOrigem){

    blocoMemoria *aux = criablocoMemoriaCache();
    aux->end = criaEndereco(-1, 0);


    transfereBloco(aux, blocoDestino[posicaoDestino]);
    transfereBloco(blocoDestino[posicaoDestino], blocoOrigem[posicaoOrigem]);
    transfereBloco(blocoOrigem[posicaoOrigem], aux);
    free(aux->end);
    free(aux);
}

int LFU(blocoMemoria **cache, int tamanho){
    int indice = 0;
    time_t final = time(NULL);
    float maiorTemp = -1;

    for (int i = 0; i < tamanho; i++){
        if (difftime(final, getTempo(cache[i])) > maiorTemp){
            maiorTemp = difftime(final, getTempo(cache[i]));
            indice = i;
        }
    }
    return indice;
}

blocoMemoria *MMU(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **RAM, Endereco *end, 
                    long int hit[4], long int miss[4], long int custo[4]){

    int posicaoCache1, posicaoCache2, posicaoCache3, posicaoRAM;

    posicaoCache1 = procuraPosicao(cache1, end, tamanhoCache01);
    
    if (posicaoCache1 != -1){ 
        
        setHit(hit, 1);
        setCusto(custo, 1, 10);
        return cache1[posicaoCache1];
    }
    else{
        
        posicaoCache2 = procuraPosicao(cache2, end, tamanhoCache02);
        
        if (posicaoCache2 != -1){
           
            posicaoCache1 = procuraPosicaoVazia(cache1, tamanhoCache01);
    
            if (posicaoCache1 != -1){
              
                transfereBloco(cache1[posicaoCache1], cache2[posicaoCache2]);
                limpaBlocoMemoria(cache2[posicaoCache2]);
            }
            else{
                posicaoCache1 = LFU(cache1, tamanhoCache01); //procura a posicao com o maior tempo

                trocaBloco(posicaoCache1, posicaoCache2, cache1, cache2);
            }

            setHit(hit,2);
            setMiss(miss,1);
            setCusto(custo, 2, 30);
            
            return cache1[posicaoCache1];
        }
        else{
            posicaoCache3 = procuraPosicao(cache3, end, tamanhoCache03);

            if (posicaoCache3 != -1){
                posicaoCache2 = procuraPosicaoVazia(cache2, tamanhoCache02);

                if (posicaoCache2 != -1){
                    transfereBloco(cache2[posicaoCache2], cache3[posicaoCache3]);
                    limpaBlocoMemoria(cache3[posicaoCache3]);
                }
                else{
                    posicaoCache2 = LFU(cache2, tamanhoCache02);

                    trocaBloco(posicaoCache2, posicaoCache3, cache2, cache3);
                }
               
                posicaoCache1 = procuraPosicaoVazia(cache1, tamanhoCache01);

                if (posicaoCache1 != -1){
                    transfereBloco(cache1[posicaoCache1], cache2[posicaoCache2]);
                    limpaBlocoMemoria(cache2[posicaoCache2]);
                }
                else{
                    posicaoCache1 = LFU(cache1, tamanhoCache01);
                    trocaBloco(posicaoCache1, posicaoCache2, cache1, cache2);
                }


                setHit(hit, 3);
                setMiss(miss, 1);
                setMiss(miss, 2);
                setCusto(custo, 3, 130);

                return cache1[posicaoCache1];
            }
            else{
                
                posicaoRAM = procuraPosicao(RAM, end, tamanhoRam);
                posicaoCache3 = procuraPosicaoVazia(cache3, tamanhoCache03);
                
                if (posicaoCache3 != -1){
                    transfereBloco(cache3[posicaoCache3], RAM[posicaoRAM]);
                }
                else{
                    posicaoCache3 = LFU(cache3, tamanhoCache03);
                    if(isAtualizado(cache3[posicaoCache3])){
                        int posicaoRam2 = procuraPosicao(RAM, cache3[posicaoCache3]->end, tamanhoRam);
                        transfereBloco(RAM[posicaoRam2], cache3[posicaoCache3]);
                    }
                    transfereBloco(cache3[posicaoCache3], RAM[posicaoRAM]);
                    cache3[posicaoCache3]->atualizado = false;
                }
    
                posicaoCache2 = procuraPosicaoVazia(cache2, tamanhoCache02);

                if (posicaoCache2 != -1){
                    transfereBloco(cache2[posicaoCache2], cache3[posicaoCache3]);
                    limpaBlocoMemoria(cache3[posicaoCache3]);
                }
                else{
                    posicaoCache2 = LFU(cache2, tamanhoCache02);
                    trocaBloco(posicaoCache2, posicaoCache3, cache2, cache3);
                }
                
                posicaoCache1 = procuraPosicaoVazia(cache1, tamanhoCache01);

                if (posicaoCache1 != -1){
                    transfereBloco(cache1[posicaoCache1], cache2[posicaoCache2]);
                    limpaBlocoMemoria(cache2[posicaoCache2]);
                }
                else{
                    posicaoCache1 = LFU(cache1, tamanhoCache01);
                    trocaBloco(posicaoCache1, posicaoCache2, cache1, cache2);
                }

                setHit(hit, 0);
                setMiss(miss, 1);
                setMiss(miss, 2);
                setMiss(miss, 3);
                setCusto(custo, 0, 1130);

                return cache1[posicaoCache1];
            }
        }
    }
}

void levaParaRAM(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **RAM){
    for (int i = 0; i < tamanhoCache01; i++){
        if (cache1[i]->atualizado == true)
            RAM[procuraPosicaoVazia(RAM, tamanhoRam)] = cache1[i];
    }

    for (int i = 0; i < tamanhoCache02; i++){
        if (cache2[i]->atualizado == true)
            RAM[procuraPosicaoVazia(RAM, tamanhoRam)] = cache2[i];
    }

    for (int i = 0; i < tamanhoCache03; i++){
        if (cache3[i]->atualizado == true)
            RAM[procuraPosicaoVazia(RAM, tamanhoRam)] = cache3[i];
    }
}
