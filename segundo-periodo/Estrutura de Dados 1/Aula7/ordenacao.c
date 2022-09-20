#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
  alunos = (TipoAluno*) malloc(n * sizeof(TipoAluno));
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
  free(alunos);
  alunos = NULL;
}

void ordena(TipoAluno *alunos, int n){
  char aux[20];
  //porque esse trem nao funcionaaaaaa
  for (int i = 0; i < n; i++){
    for (int j = 1; j < n-i; j++){
      if (strcmp(alunos[j].nome, alunos[j-1].nome) < 0){
        //printf("Estou trocando %s por %s\n", alunos[j].nome, alunos[j-1].nome);
        strcpy(aux, alunos[j].nome);
        strcpy(alunos[j].nome, alunos[j-1].nome);
        strcpy(alunos[j-1].nome, aux);
      }
    }
  }
}

	// char *aux;
  // int j;
  // for (int i = 1; i < n; i++){
  //       strcpy(aux, alunos[i].nome);
  //       j = i - 1;
  //       while (j >= 0 && strcmp(aux, alunos[j].nome) < 0){
  //           strcpy(alunos[j+1].nome, alunos[j].nome);
  //           j -= 1;
  //       }
  //       strcpy(alunos[j+1].nome, aux);
  //   }