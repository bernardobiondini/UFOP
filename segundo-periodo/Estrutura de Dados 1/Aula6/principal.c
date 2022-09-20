#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main()
{
    Pilha pilha;
    char ch;
    Item item;

    Pilha_Inicia(&pilha);

    int retorno;

    while(scanf("%c", &ch)!=EOF){
      item.c = ch;
      if(item.c == '('){
        Pilha_Push(&pilha, item);
      }
      else if(item.c == ')'){
        retorno = Pilha_Pop(&pilha, &item);
        if (!retorno) break;
      }
    }

    if(!Pilha_EhVazia(&pilha) || !retorno){
      printf("incorreto\n");
    }
    else{
      printf("correto\n");
    }

    //determinar o resultado

    Pilha_Esvazia(&pilha);

    return 0;//nao remova
}
