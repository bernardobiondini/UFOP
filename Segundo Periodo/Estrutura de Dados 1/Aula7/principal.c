#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int i=0;
	int n, k;
	TipoAluno *alunos;

	scanf("%d %d", &n, &k);
	k--;
	//scanf("", );
	//printf("%d %d\n", n, k);
	alunos = alocaAlunos(alunos, n);
	for (i = 0; i < n; i++){
		scanf("%s", alunos[i].nome);
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	printf("%s\n", alunos[i].nome);
	// }
	//printf("salvei o primeiro? %s\n", alunos[0].nome);
	
	ordena(alunos, n);
	printf("%s\n", alunos[k].nome);
	// for (int i = 0; i < n; i++)
	// {
	// 	printf("%s %d\n", alunos[i].nome, i);
	// }
	
	alunos = desalocaAlunos(alunos);
	return 0;
}
