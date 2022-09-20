/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <string.h>
#define x 70

int main(){
    char nome[x], sobrenome[x];
    
    printf ("Digite o seu nome completo: ");
    fgets(nome, x, stdin);
    printf("\n");
    int space = 0, tamanho = strlen(nome);
    int tamanhoSobrenome, ultimoespaco;

    for (int i = 0; i < tamanho; i++){
        if (nome[i] == ' '){
            space += 1;
            ultimoespaco = i;
        }
    }

    int letras = tamanho - space - 1;
    printf("%d\n", letras);

    int j = 0;

    for (int i = 0; i <= tamanho; i++){
        if (i > ultimoespaco){
            sobrenome[j] = nome[i];
            j++;
        }
    }
    
    tamanhoSobrenome = strlen(sobrenome) - 1;
    sobrenome[tamanhoSobrenome] = '\0';
    printf("%s, ", sobrenome);
    
    for (int i = 0; i <= letras - tamanhoSobrenome; i++)
    {
        printf("%c", nome[i]);
    }
    
    printf ("\nTotal de letras: %d\n", letras);
    printf("Total de letras do ultimo sobrenome: %d\n", tamanhoSobrenome);
    return 0;
}