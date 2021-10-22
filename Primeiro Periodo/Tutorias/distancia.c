#include <stdio.h> 
#include <math.h>

typedef struct{
    int ponto1[2];
    int ponto2[2];
}parOrdenado;

int main(){
    parOrdenado par;
    scanf("%d", &par.ponto1[0]);
    scanf("%d", &par.ponto1[1]);
    scanf("%d", &par.ponto2[0]);
    scanf("%d", &par.ponto2[1]);

    double D = sqrt(pow(par.ponto2[0] - par.ponto1[0], 2) + pow(par.ponto2[1] - par.ponto1[1], 2));
    printf ("D = %.2lf\n", D);
    return 0;
}