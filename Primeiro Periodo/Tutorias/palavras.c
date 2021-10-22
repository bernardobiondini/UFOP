#include <stdio.h>
#include <string.h>
#define x 60

int main(){
    char word[x], word2[x];
    scanf ("%s", word);
    fflush(stdin);
    scanf ("%s", word2);
    fflush(stdin);

    int tamanho = strlen(word);
    int tamanho2 = strlen(word2);

    if (tamanho + tamanho2 < 10){
        strcat(word, word2);
        printf ("%s", word);
    }
    else {
        for (int i = 0; i < tamanho; i = i+2){
            printf ("%c ", word[i]);
        }
        for (int i = 1; i < tamanho2; i = i+2){
            printf ("%c ", word2[i]);
        }
    }
    printf("\n");
    return 0;
}
