/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */
#include <stdio.h>
#define n 30

void mediaMais(double media, double *vet)
{
    int maiores=0, menores=0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i]>media)
            maiores++;
        else 
            menores++;
    }
    printf ("%d dias de temperatura abaixo da media\n%d dias de temperatura acima da media\n", menores, maiores);
}
int main()
{
    double temp[n], soma=0;
    for (int i = 0; i < n; i++)
    {
        printf("Digite a temperatura no dia %d: ", i+1);
        scanf ("%lf", &temp[i]);
        soma += temp[i];
    }

    double media = soma/n;
    mediaMais (media, temp);
    return 0;
}