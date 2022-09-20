/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <math.h>

double pi(int);

int main(){
    int n;
    printf ("Digite a quantidade de numeros: "); scanf ("%d", &n);
    double x = pi(n);
    printf ("%lf eh o valor de pi para %d numeros\n", x, n);
    return 0;
}

double pi(int n){
    int i = 0;
    double x, soma = 1;
    int sinal = -1;

    while (n >= i){
        int z = 3 + 2 * i;
        soma = soma +  sinal*(1 / pow (z, 3));
        i++;
        sinal*= -1;    
    }
    x = cbrt(soma * 32);
    return x;
}