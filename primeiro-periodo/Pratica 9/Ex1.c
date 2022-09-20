/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>

struct Racional {
    int numerador;
    int denominador;
};
int equal(struct Racional *r1, struct Racional *r2){
    if (r1->numerador/r1->denominador == r2->numerador/r2->denominador) return 1;
    else return 0;
}
int main(){
    struct Racional r1;
    struct Racional r2;

    printf ("Digite o numerador e o denominador de r1: "); scanf("%d %d", &r1.numerador, &r1.denominador);
    printf ("Digite o numerador e o denominador de r2: "); scanf("%d %d", &r2.numerador, &r2.denominador);

    printf("\n");

    int res = equal(&r1, &r2);

    if (res){
        printf("r1 e r2 sao iguais\n");
    }
    else{
        printf("r1 e r2 nao sao iguais\n");
    }

    return 0;
}