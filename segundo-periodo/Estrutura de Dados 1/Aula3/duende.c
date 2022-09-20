#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
  char nome[20];
  int idade;
  int escalado;
};

struct time {
  char lider[20];
  char entregador[20];
  char piloto[20];

  int idadeLider;
  int idadeEntregador;
  int idadePiloto;
};

void lerQuantidade(int *qtd){
  scanf("%d", qtd);
}
//Manter como especificado
TADduende *alocaDuendes(TADduende *D, int qtd){
  D = (TADduende *) malloc(qtd * sizeof(TADduende));
  if(D == NULL){
    exit(1);
  }
  return D;
}

//Manter como especificado
TADtime *alocaTimes(TADtime *T, int qtd){
  T = (TADtime *) malloc(qtd * sizeof(TADtime));
  if(T == NULL){
    exit(1);
  }
}

//Manter como especificado
TADduende *desalocaDuendes(TADduende *D){
  free(D);
  return D;
}

//Manter como especificado
TADtime *desalocaTimes(TADtime *T){
  free(T);
  return T;
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  int i;
  for(i = 0; i < qtd; i++){
    scanf("%s", D[i].nome);
    scanf("%d", &D[i].idade);
    D[i].escalado = 0;
  }
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int i, indice;
  //completar o XXX
  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;
    //marcar o duende do indice como escalado
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].lider, D[indice].nome);
    T[i].idadeLider = D[indice].idade;
    //copiar a idade
  }
  //repetir o laco acima, mas para o entregador
  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;

    strcpy(T[i].entregador, D[indice].nome);
    T[i].idadeEntregador = D[indice].idade;
  }
  //repetir o laco acima, mara para o piloto
  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;

    strcpy(T[i].piloto, D[indice].nome);
    T[i].idadePiloto = D[indice].idade;
  }
}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice;
  int ano = 9;
  for (int i = 0; i < qtd; i++)
  {
    if(D[i].idade > ano && D[i].escalado == 0){
      ano = D[i].idade;
      indice = i;
    }
  }
  //determinar o indice do duende mais velho nao escalado ainda
  //variaveis adicionais podem ser criadas
  return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
  for (int i = 0; i < qtd; i++)
  {
    printf("Time %d\n%s %d\n%s %d\n%s %d\n", i+1, T[i].lider, 
    T[i].idadeLider, T[i].entregador, T[i].idadeEntregador, T[i].piloto, T[i].idadePiloto);
    printf("\n");
  }
}
