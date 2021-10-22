/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>

typedef struct {
    int real;
    int imaginario;
} Complexo;

void multComplexo(Complexo *x, Complexo *y, Complexo *z){
    z->real = x->real * y->real - x->imaginario * y->imaginario; 
    z->imaginario = (x->real* y->imaginario + x->imaginario * y->real);
}
void somaComplexo(Complexo *x, Complexo *y, Complexo *z){
    z->real = x->real + y->real;
    z->imaginario = x->imaginario + y->imaginario;
}
void subComplexos(Complexo *x, Complexo *y, Complexo *z){
    z->real = x->real - y->real;
    z->imaginario = x->imaginario - y->imaginario;
}
int main(){
    Complexo x;
    Complexo y;
    Complexo z;

    char op;

    printf("Digite os valores de a e b (x = a + bi): "); scanf("%d %d", &x.real, &x.imaginario);
    printf("Digite os valores de c e d (y = c + di): "); scanf("%d %d", &y.real, &y.imaginario);

    printf("Digite a opera¸c~ao (+, - ou *): "); 
    getchar();
    scanf("%c", &op);

    if (op == '*') multComplexo(&x, &y, &z);
    else if(op == '+') somaComplexo(&x, &y, &z);
    else subComplexos(&x, &y, &z);

    if (z.imaginario == 0) printf("Resultado: %d\n", z.real);
    else printf("Resultado: %d + %di\n", z.real, z.imaginario);

    return 0;
}
