#include <stdio.h>
#include <string.h>
#define v 50

int main () {
	int tam;
	char palavra[v], comparar[v];
	printf("Digite uma palavra\n");
	scanf("%s", palavra);
	tam = strlen(palavra);		
	for (int i = 0; i < tam; i++) {
        comparar[i] = palavra[(tam - 1) - i];
	}
	if (strcmp(palavra, comparar) == 0)
		printf("Eh um palindromo\n");
	else
		printf("Nao eh um palindromo\n");
	return 0;
}