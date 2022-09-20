#include <stdio.h>

int main(){
    int x, i = 1, soma=0;

    printf ("Digite o valor de x: "); scanf("%d", &x);

    do {
        if (x % i == 0){
            soma+=1;
            i++;
        }
        else
            i++;
    }while (i <= x);

    if (soma == 2)
        printf ("Numero Primo\n");
    else
        printf ("Nao e Numero Primo\n");
}