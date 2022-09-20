/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <string.h>
#define x 100

int main(){
    char frase[x];
    printf("Digite o texto para censurar: ");
    fgets(frase, x, stdin);
    int tamanho = strlen(frase);

    for (int i = 0; i < tamanho; i++){
        if (frase[i] == 'a'){
            frase[i] = '@';
        }
        if (frase[i] == 'e'){
            frase[i] = '-';
        }
        if (frase[i] == 'i'){
            frase[i] = '|';
        }
        if (frase[i] == 'o'){
            frase[i] = '0';
        }
        if (frase[i] == 'u'){
            frase[i] = '#';
        }
        if (frase[i] == 's'){
            frase[i] = '$';
        }
    }
    
    printf("\n%s", frase);
    printf("\n");
    return 0;
}