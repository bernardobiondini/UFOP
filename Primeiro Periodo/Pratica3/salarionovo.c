#include <stdio.h>

int main(){

    double salario;
    int codigo;
    printf ("Digite o salario atual: "); scanf ("%lf", &salario);
    printf ("Digite o codigo do cargo: "); scanf ("%d", &codigo);

    double salarioNovo, diferenca;
    

    switch (codigo){
        case 100:
        salarioNovo = salario * 1.03;
        diferenca = salarioNovo - salario;
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", salarioNovo);
        printf ("Aumento: %.2lf\n", diferenca);
        break;
        case 101:
        salarioNovo = salario * 1.05;
        diferenca = salarioNovo - salario;
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", salarioNovo);
        printf ("Aumento: %.2lf\n", diferenca);
        break;
        case 102:
        salarioNovo = salario * 1.075;
        diferenca = salarioNovo - salario;
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", salarioNovo);
        printf ("Aumento: %.2lf\n", diferenca);
        break;
        case 201:
        salarioNovo = salario * 1.10;
        diferenca = salarioNovo - salario;
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", salarioNovo);
        printf ("Aumento: %.2lf\n", diferenca);
        break;
        default:
        salarioNovo = salario * 1.15;
        diferenca = salarioNovo - salario;
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", salarioNovo);
        printf ("Aumento: %.2lf\n", diferenca);
    }
    return 0;
}   