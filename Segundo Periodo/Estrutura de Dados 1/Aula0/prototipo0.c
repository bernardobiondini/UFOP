#include <stdio.h>
int main()
{
    double M[12][12];//utilize esta matriz para ler os 144 numeros reais
    char O;
    double resultado = 0;
    int cont = 0;

    scanf("%c", &O);

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%lf", &M[i][j]);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if( (j > i) && ((i + j) < 11) )
            {
                resultado += M[i][j];
                cont++;
            }
        }
    }
    
    if(O == 'M')
    {
        resultado = resultado/cont;
        printf("%.1lf\n", resultado);
    }
    else if(O == 'S')
    {
        printf("%.1lf\n", resultado);
    }
    
    return 0;//não remova
}