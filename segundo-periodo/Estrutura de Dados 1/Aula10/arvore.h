# ifndef arvore_h
# define arvore_h

#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave chave;
} TItem ;

typedef struct No {
    TItem item;
    struct No *pEsq, *pDir;
} TNo ;

typedef TNo *TArvore;

void TArvore_Inicia (TNo ** pRaiz);
void TArvore_Insere_Raiz (TNo ** ppRaiz , TItem x);
int TArvore_Insere (TNo ** pRaiz , TItem x);
TNo * TNo_Cria (TItem x);
void Prefixa(TNo * p);
void Infixa(TNo * p);
void Posfixa(TNo * p);

# endif
