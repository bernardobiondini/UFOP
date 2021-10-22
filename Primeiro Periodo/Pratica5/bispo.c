/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>

void movimBispo(int, int);

int main(){
    int l, c;
    printf("Movimentos de um Bispo no xadrez!\n");
    printf ("Digite a linha em que o Bispo se encontra: "); scanf ("%d", &l);
    printf ("Digite a coluna em que o Bispo se encontra: "); scanf ("%d", &c);

    printf("\t\t1\t2\t3\t4\t5\t6\t7\t8\n\t----------------------------------------------------------------------\n");

    movimBispo(l, c);
    return 0;
}

void movimBispo(int l, int c){
    int i = 0, j = 0;
    while (i <= 7){ //iniciei com 0, entao de 0 a 7 sao 8 linhas
        j=0;
        printf("%d\t|\t", i+1);
        while (j <=7){ //pois inicie com 0
            if ((i - j == l - c) || (i + j == l -1 + c - 1)) //quando executava a posicao do bispo aumentava em 1 coluna e 1 linha (l-1 + c- 1)
                printf("x\t");
            else 
                printf("-\t");\
        j++;
        }
    i++;
    printf ("\n");
    }
}