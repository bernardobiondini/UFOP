/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <string.h>
#define x 100

void strmaius(char *frase, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if (frase[i] >= 'A' && frase[i] <= 'Z')
            frase[i] = frase[i];
        else if (frase[i] >= 'a' && frase[i] <= 'z'){
            frase[i] = frase[i] - 32;
        }
    }
    printf ("%s\n", frase);
}

int main(){
    char frase[x];
    printf("Digite o texto: ");
    fgets(frase, x, stdin);
    int tamanho = strlen(frase);
    strmaius(frase, tamanho);
    
    return 0;
}