#include "arvore.h"
#include <stdio.h>

int main ()
{
	int n, no;
	TArvore *arvore;

	TArvore_Inicia(arvore);

	scanf("%d", &n);
	TItem x;
	scanf("%d", &no);
	x.chave = no;
	TArvore_Insere_Raiz(arvore, x);

	for(int i = 1; i < n; i++) {
		scanf("%d", &no);
		x.chave = no;
		TArvore_Insere(arvore, x);
	}
	printf("PREFIXA: ");
	Prefixa(*arvore);
	printf("\nINFIXA: ");
	Infixa(*arvore);
	printf("\nPOSFIXA: ");
	Posfixa(*arvore);
	printf("\n");

	return 0;
}
