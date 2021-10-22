#include <stdio.h>

int main(){
    
    int x, posicao, aux = 0, i = 1;

    while (i <= 100){
        scanf("%d", &x);
        if (x > aux){
            aux = x;
            posicao = i;
        }
        i++;
    }

    printf ("%d\n", aux);
    printf ("%d\n", posicao);
    return 0;
}
