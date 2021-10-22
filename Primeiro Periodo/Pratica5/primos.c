/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>

int ehprimo (long);

int main (){
    long x;
    printf ("Digite um numero: "); scanf ("%ld", &x);
    int res = ehprimo (x);
    if (res == 0){
        printf("Eh primo\n");
    }
    else 
        printf ("Nao eh primo\n");
    return 0;
}

int ehprimo (long n){
    int i = 1, somae = 0;
    while (n >= i){
        if (n % i == 0){
            somae = somae + 1;
            i++;
        }
        else {
            i++;
        }   
    }
    if (somae == 2)
        return 0;
    
    else
        return 1;
}