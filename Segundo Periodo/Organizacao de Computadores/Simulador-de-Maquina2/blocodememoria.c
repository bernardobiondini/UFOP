#include "blocodememoria.h"
#include "endereco.h" 
#include <time.h>

blocoMemoria **criaMemoriaRAM(){
   
    blocoMemoria **bloco = malloc(tamanhoRam * sizeof(blocoMemoria));
   
    for (int i = 0; i < tamanhoRam; i++){
        bloco[i] = criablocoMemoriaRAM();
        bloco[i]->end = criaEndereco(i, 0);
    }
    return bloco;
}

blocoMemoria **criaMemoriaCache(int tamanho){
  
    blocoMemoria **bloco = (blocoMemoria**) malloc(tamanho * sizeof(blocoMemoria*));

    for (int i = 0; i < tamanho; i++){
        bloco[i] = criablocoMemoriaCache();
        bloco[i]->end = criaEndereco(-1, 0);
    }
    return bloco;
}

blocoMemoria *criablocoMemoriaCache(){
    
    blocoMemoria *bloco = (blocoMemoria*)malloc(sizeof(blocoMemoria));
    srand(time(NULL));
    for(int i = 0; i < 4; i++){
	    bloco->palavra[i] = rand() % 100;
    }

    bloco->atualizado = false;
    time_t t = time(NULL);
    bloco->tempo = time(&t);
    
    return bloco;
}
void limpaBlocoMemoria(blocoMemoria *bloco){
    bloco->end->endBloco = -1;
    bloco->atualizado = false;
}

blocoMemoria *criablocoMemoriaRAM(){
    blocoMemoria *bloco = malloc(sizeof(blocoMemoria));

    srand(time(NULL));
    for(int i = 0; i < 4; i++){
	    bloco->palavra[i] = rand() % 100;
    }
    
    bloco->atualizado = false;
    
    time_t t = time(NULL);
    bloco->tempo = time(&t);

    return bloco;
}

void liberaMemoria(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **Ram, double *tempo){
  
    free(cache1);
    cache1 = NULL;
   
    free(cache2);
    cache2 = NULL;

    free(cache3);
    cache3 = NULL;
    
    free(tempo);
    tempo = NULL;
}

blocoMemoria *getBloco (blocoMemoria **bloco, int posicao){
    return bloco[posicao];
}

void setBloco(blocoMemoria **bloco, blocoMemoria *novo, int posicao){
    bloco[posicao] = novo;
}

int getPalavra(blocoMemoria *bloco, int posicao){
    return bloco->palavra[posicao];
}

void setPalavra(blocoMemoria *bloco, int palavra, int posicao){
    bloco->palavra[posicao] = palavra;
    setAtualizado(bloco);
}

int getEnderecoBloco(blocoMemoria *bloco){
   return bloco->end->endBloco;
}

void setEnderecoBloco(blocoMemoria *bloco, int endereco){
   bloco->end->endBloco = endereco;
}

long int getCusto(long int *vetor, int posicao){
    return vetor[posicao];
}


void setCusto(long int *vetor, int posicao, int custo){
    vetor[posicao]+= custo;
}

bool isAtualizado(blocoMemoria* bloco){
    return bloco->atualizado;
}

void setAtualizado(blocoMemoria* bloco){
    bloco->atualizado = true;
}

void setDesatualizado(blocoMemoria* bloco){
    bloco->atualizado = false;
}

long int getHit(long int *vetor, int posicao){
    return vetor[posicao];
}
long int getMiss(long int *vetor, int posicao){
    return vetor[posicao];
}

void setHit(long int *vetor, int posicao){
    vetor[posicao]+=1;
}
void setMiss(long int *vetor, int posicao){
    vetor[posicao]+=1;
}

time_t getTempo(blocoMemoria *bloco){
    return bloco->tempo;
}

void setTempo(blocoMemoria *bloco, time_t tempo){
    bloco->tempo = tempo;
}