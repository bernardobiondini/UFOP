#include "lista.h"
#include <stdio.h>
#include <string.h>
//tamanho maximo de uma string
#define MAX_STR 1200

int main()
{
    TLista original, nova;
    char str[MAX_STR], str2[MAX_STR], str3[20];
    char * token;
    TItem x;

    TLista_Inicia(&original);
    TLista_Inicia(&nova);
    //iniciar listas

    //le a primeira linha
    fgets (str, MAX_STR, stdin);
    //remove o \n incluido pelo fgets
    str[strcspn(str, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str, " ");

    while (token != NULL) {
      strcpy(x.nome, token);
      TLista_InsereFinal(&original, x);
      //inserir o item na lista adequada
      token = strtok(NULL, " ");
    }

    //ler a segunda linha, igual a primeira e preencher a segunda lista
    fgets (str2, MAX_STR, stdin);
    //remove o \n incluido pelo fgets
    str2[strcspn(str2, "\n")] = 0;

    token = strtok(str2, " ");

    while (token != NULL) {
      strcpy(x.nome, token);
      TLista_InsereFinal(&nova, x);
      //inserir o item na lista adequada
      token = strtok(NULL, " ");
    }

    //ler a terceira linha, usando apenas scanf

    scanf("%s", str3);
    //str3[strlen(str3)] = '\0';
    //printf("O ultimo nome seria %s", str3);
    //dependendo se ha indicacao ou nao, manipular as listas de acordo

    if(strcmp(str3, "nao") == 0){
      TLista_append(&original, &nova);
    }
    else{
      TLista_include(&original, &nova, str3);
    }
    //printf("opa jaja imprimo\n");
    //imprimir a lista final
    TLista_Imprime(&original);
    //ao final as duas listas estarao unificadas, entao basta esvaziar a original
    //printf("saiu da funcao antes de dar falha de segmentacao\n");
    TLista_Esvazia(&original);
    return 0;//nao remova
}
