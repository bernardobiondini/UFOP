/* Programa que le o salario e o codigo do cargo e apresenta o ajuste salarial respectivo
*Bernardo Cavanellas Biondini 
* 20. 1. 4112
* Turma 43 */

#include <stdio.h>

int main(){

    double salario;
    int codigo;
    printf ("Digite o salario atual: "); scanf ("%lf", &salario);
    printf ("Digite o codigo do cargo: "); scanf ("%d", &codigo);

    double x = salario * 1.03;
    double y = salario * 1.05;
    double w = salario * 1.075;
    double z = salario * 1.10;
    double k = salario * 1.15;
    double diferencax = x - salario;
    double diferencay = y - salario;
    double diferencaw = w - salario;
    double diferencaz = z - salario;
    double diferencak = k - salario;

    switch (codigo){
        case 100:
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", x);
        printf ("Aumento: %.2lf\n", diferencax);
        break;
        case 101:
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", y);
        printf ("Aumento: %.2lf\n", diferencay);
        break;
        case 102:
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", w);
        printf ("Aumento: %.2lf\n", diferencaw);
        break;
        case 201:
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", z);
        printf ("Aumento: %.2lf\n", diferencaz);
        break;
        default:
        printf ("Salario antigo: %.2lf\n", salario);
        printf ("Novo salario: %.2lf\n", k);
        printf ("Aumento: %.2lf\n", diferencak);
    }
    return 0;
}   