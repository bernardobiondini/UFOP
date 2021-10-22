#include <stdio.h>

double operacaoMais(int, int);
double operacaoMenos(int, int);
double operacaoDivisao(int, int);
double operacaoMultiplicacao(int, int);

int main(){
    int nm1, nm2;
    char op;
    printf("Digite o operador: "); scanf ("%c", &op);
    printf("Digite os numeros: "); scanf ("%d %d", &nm1, &nm2);
    double resultado;
    switch (op){
        case ('+'):
        resultado = operacaoMais(nm1, nm2);
        printf("%.3lf\n", resultado);
        break;
        case ('-'):
        resultado = operacaoMenos(nm1, nm2);
        printf("%.3lf\n", resultado);
        break;
        case ('/'):
        resultado = operacaoDivisao(nm1, nm2);
        printf("%.3lf\n", resultado);
        break;
        case ('*'):
        resultado = operacaoMultiplicacao(nm1, nm2);
        printf("%.3lf\n", resultado);
        break;
        default:
        return 0;
    }
    return 0;
}

double operacaoMais(int a, int b){
    return a + b;
}
double operacaoMenos(int a, int b){
    return a - b;
}
double operacaoDivisao(int a, int b){
    return (double)a / b;
}
double operacaoMultiplicacao(int a, int b){
    return (double)a * b;
}
