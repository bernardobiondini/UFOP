#include <stdio.h>
#include <string.h>
#define x 50

int main(){
    char palavra[x], comp[x];
    scanf("%s", palavra);
    int tamanho = strlen(palavra);
    printf ("%d\n", tamanho);
    for (int i = 0; i < tamanho; i++)
        comp[i] = palavra[tamanho - 1 - i];
    printf ("%s\n", comp);
    
    if (strcmp(palavra, comp) == 0)
        printf ("Eh um palindromo\n");
    else
        printf("Nao eh um palindromo\n");
    
    return 0;
}