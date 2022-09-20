/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <string.h>
#define x 100

int main(){
    
    char word[x], aux[x], fim[] = "FIM";
    printf ("Digite uma palavra ou FIM para sair: ");
    scanf ("%s", word);
    
    
    do {
        int tamanho = strlen(word);

        for (int i = 0; i < tamanho; i++){
            aux[i] = word[tamanho - 1 - i];
        }

        if (strcmp(word, aux) == 0){
            printf ("%s Eh um palindromo\n", word);
        }
        else{
            printf("%s Nao eh um palindromo\n", word);
        }
        
        for(int i = 0; i < tamanho; i++){
            aux[i] = '\0';
            word[i] = '\0';
        }
        
        printf ("Digite uma palavra ou FIM para sair: ");
        scanf ("%s", word);

    }while ((strcmp(word, fim) != 0));
    
    return 0;
}