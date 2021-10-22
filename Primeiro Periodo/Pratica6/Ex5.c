/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */
#include <stdio.h>
#define n 15


int main()
{
    double nota1[n];
    double nota2[n];

    for (int i = 0; i < n; i++)
    {
        printf ("Nota 1 do aluno %d:\n", i+1);
        scanf ("%lf", &nota1[i]);
        printf ("Nota 2 do aluno %d:\n", i+1);
        scanf ("%lf", &nota2[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (((nota1[i] + nota2[i]) / 2) >= 60.0)
            printf("Aluno %d Aprovado\n", i+1);
        else 
            printf ("Aluno %d Reprovado\n", i+1);
    }
    return 0;
}