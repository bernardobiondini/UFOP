#include <stdio.h>
#include <string.h>
#define x 50

void consoante(char *frase){
    for (int i = 0; i < x; i++){
        if((frase[i] >= 'b' && frase[i] <= 'd') || (frase[i] >= 'f' && frase[i] <= 'h') || (frase[i]>= 'j' && frase[i] <='n') || (frase[i]>='p' && frase[i]<= 't') || (frase[i]>= 'v' && frase[i]<= 'z')){
            printf ("%d ", i);
        }
    }
}

int main(){
    char frase[x];
    printf("Digite a frase:\n"); fgets(frase, x, stdin);

    consoante(frase);

    printf("\n");

    return 0;
}

