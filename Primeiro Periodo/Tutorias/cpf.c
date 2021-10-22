#include <stdio.h>
#include <math.h>

int vCPF(long);

int main(){
    long CPF;
    printf ("Digite o CPF: "); scanf("%ld", &CPF);
    int valido = vCPF(CPF);
    
    if(valido == 1)
        printf("Valido\n");
    else
        printf("Invalido\n");
    return 0;
}
int vCPF(long CPF){
    int a = CPF / pow(10, 10);
    int b = (CPF / pow(10, 9)) - (CPF / pow(10, 10));
    int c = (CPF / pow(10, 8)) - (10 * CPF / pow(10, 10));
    int d = (CPF / pow(10, 7)) - (100 * CPF / pow(10, 10));
    int e = (CPF / pow(10, 6)) - (1000 * CPF / pow(10, 10));
    int f = (CPF / pow(10, 5)) - (10000 * CPF / pow(10, 10));
    int g = (CPF / pow(10, 4)) - (100000 * CPF / pow(10, 10));
    int h = (CPF / pow(10, 3)) - (1000000 * CPF / pow(10, 10));
    int i = (CPF / pow(10, 2)) - (10000000 * CPF / pow(10, 10));
    int j = (CPF / pow(10, 1)) - (100000000 * CPF / pow(10, 10));
    int k = CPF - (1000000000 * CPF / pow(10, 10));
    if (((((a * 10) + (b * 9) + (c * 8) + (d * 7) + (e * 6) + (f * 5)
     + (g * 4) + (h * 3) + (i * 2)) * 10) % 11 == a) && ((((a * 11) + 
     (b * 10) + (c * 9) + (d * 8) + (e * 7) + (f * 6) + (g * 5) + (h * 4) + (i * 3) + (j * 2)) * 10) % 11 == k))
    return 1;
     else
    return 0; 
}