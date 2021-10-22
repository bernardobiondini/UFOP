#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>


/*opcode
0 -> Somar
1 -> Subtrair
2 -> Salvar na memoria
-1 -> HALT
*/


int main(){
    Memoria *memoria;
    memoria = alocaMemoria();
    int *resultado;
    printf("Bem vindo a sua Calculadora!\n");
    printf("Digite o comando desejado:\n");
    int comando, operacao, numero1, numero2, subOperacao;
    printf("-1 - Sair\t1 - Matematica Basica\t2 - Matematica Aplicada\t3 - Conversoes\n");
    scanf("%d", &comando);
    do
    {
        switch (comando){
            //matematica basica
            case 1:
                printf("Qual funcao deseja realizar?\n");
                printf("1 - soma\t2 - subtracao\t3 - multiplicacao\t4 - divisao\n");
                scanf("%d", &operacao);
                switch (operacao){
                    case 1:
                        printf("Digite os numeros aos quais voce deseja somar:\n");
                        scanf("%d %d", &numero1, &numero2);
                        funcaoSoma(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        printf("Somando %d com %d e gerando %d\n\n", numero1, numero2, resultado[3]);
                        break;
                    
                    case 2:
                        printf("Digite os numeros aos quais voce deseja subtrair:\n");
                        scanf("%d %d", &numero1, &numero2);
                        funcaoSubtracao(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        printf("Subtraindo %d com %d e gerando %d\n\n", numero1, numero2, resultado[3]);
                        break;
                    
                    case 3:
                        printf("Digite os numeros aos quais voce deseja multiplicar:\n");
                        scanf("%d %d", &numero1, &numero2);
                        multiplicacao(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        printf("Multiplicando %d com %d e gerando %d\n\n", numero1, numero2, resultado[3]);
                        break;
                    case 4:
                        printf("Digite os numeros aos quais voce deseja dividir:\n");
                        scanf("%d %d", &numero1, &numero2);
                        divisaoEResto(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        printf("Dvidindo %d por %d e gerando %d, com resto %d\n\n", numero1, numero2, resultado[3], resultado[0]);
                        break;
                    default:
                        printf("Comando Invalido\n");
                        break;
                }
                break;
            //matematica aplicada
            case 2:
                printf("Qual funcao deseja realizar?\n");
                printf("1 - potencia\t2 - fatorial\t3 - soma de quadrados\t4 - radiciacao\n");
                printf("5 - area de quadrado\t6 - area de retangulo\t7 - volume de cubo\t8 - volume de piramide\n");
                printf("9 - perimetro de circunferencia\n");
                scanf("%d", &operacao);
                switch (operacao){
                    case 1:
                        printf("Digite a base e o expoente:\n");
                        scanf("%d %d", &numero1, &numero2);
                        potencia(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        printf("A potencia de %d com indice %d gera %d\n\n", numero1, numero2, resultado[3]);
                        break;
                    
                    case 2:
                        printf("Voce quer saber o fatorial de qual numero?:\n");
                        scanf("%d", &numero1);
                        fatorial(memoria, numero1);
                        resultado = retornaRAM(memoria);
                        printf("Fatorial de %d gera %d\n\n", numero1, resultado[3]);
                        break;
                    
                    case 3:
                        printf("Digite os numeros aos quais voce deseja somar:\n");
                        scanf("%d %d", &numero1, &numero2);
                        somaQuadrados(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        printf("O quadrado de %d somado com o quadrado de %d gera %d\n\n", numero1, numero2, resultado[3]);
                        break;
                    case 4:
                        printf("Digite o radicando e o indice:\n");
                        scanf("%d %d", &numero1, &numero2);
                        raiz(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        if(resultado[3] != -1){
                            printf("A raiz de indice %d de %d gera %d\n\n", numero2, numero1, resultado[3]);
                        }
                        else{
                            printf("A raiz de indice %d de %d nao gera um numero inteiro\n", numero2, numero1, resultado[3]);
                        }
                        break;
                    case 5:
                        printf("Digite o lado do quadrado:\n");
                        scanf("%d", &numero1);
                        areaQuadrado(memoria, numero1);
                        resultado = retornaRAM(memoria);
                        printf("A area do quadrado de lado %d é de %d\n\n", numero1, resultado[3]);
                        break;
                    case 6:
                        printf("Digite os lados do retangulo:\n");
                        scanf("%d %d", &numero1, &numero2);
                        areaRetangulo(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        printf("A area do retangulo de lados %d e %d é de %d\n\n", numero1, numero2, resultado[3]);
                        break;
                    case 7:
                        printf("Digite o lado do cubo:\n");
                        scanf("%d", &numero1);
                        volumeCubo(memoria, numero1);
                        resultado = retornaRAM(memoria);
                        printf("O volume do cubo de lado %d é de %d\n\n", numero1, resultado[3]);
                        break;
                    case 8:
                        printf("Digite a base e a altura da piramide:\n");
                        scanf("%d %d", &numero1, &numero2);
                        volumePiramide(memoria, numero1, numero2);
                        resultado = retornaRAM(memoria);
                        printf("O volume da piramide de base %d e altura %d é de %d\n\n", numero1, numero2, resultado[3]);
                        break;
                    case 9:
                        printf("Voce deseja calcular a partir do raio ou do diametro? 1- raio 2 - diametro\n");
                        scanf("%d", &subOperacao);
                        switch (subOperacao){
                            case 1:
                                printf("Digite o raio da circunferencia:\n");
                                scanf("%d", &numero1);
                                perimetroCircunferencia(memoria, numero1);
                                resultado = retornaRAM(memoria);
                                printf("O perimetro da circunferencia de raio %d é %d\n\n", numero1, resultado[3]);
                                break;
                            
                            case 2:
                                printf("Digite o diametro da circunferencia:\n");
                                scanf("%d", &numero1);
                                perimetroCircunferenciaDiametro(memoria, numero1);
                                resultado = retornaRAM(memoria);
                                printf("O perimetro da circunferencia de diametro %d é %d\n\n", numero1, resultado[3]);
                                break;
                            default:
                                printf("Comando Invalido\n");
                                break;
                            break;
                        }
                        break;
                    default:
                        printf("Comando Invalido\n");
                        break;
                    }
                break;
            //conversoes
            case 3:
                printf("Qual conversao voce deseja realizar?\n");
                printf("1 - Celsius para Fahrenheit\t2 - Fahrenheit para Celsius\n3 - anos em meses(ou vice-versa)\t4 - anos em dias(ou vice-versa)\n");
                printf("5 - meses em dias(ou vice-versa)\t6 - dias em minutos(ou vice-versa)\n7 - minutos em segundos(ou vice-versa)\t8 - dias em anos, meses e dias\n");
                scanf("%d", &operacao);
                switch (operacao){
                    case 1:
                        printf("Digite a temperatura em Celsius:\n");
                        scanf("%d", &numero1);
                        celsiusToFahrenheit(memoria, numero1);
                        resultado = retornaRAM(memoria);
                        printf("%d graus Celsius gera %d graus Fahrenheit\n\n", numero1, resultado[3]);
                        break;
                    
                    case 2:
                        printf("Digite a temperatura em Fahrenheit:\n");
                        scanf("%d", &numero1);
                        fahrenheitToCelsius(memoria, numero1);
                        resultado = retornaRAM(memoria);
                        printf("%d graus Fahrenheit gera %d graus Celsius\n\n", numero1, resultado[3]);
                        break;
                    
                    case 3:
                        printf("Voce deseja transformar anos em meses ou meses em anos? 1-anos em meses, 2- meses em anos:\n");
                        scanf("%d", &subOperacao);
                        switch (subOperacao){
                        case 1:
                            printf("Digite um valor para anos:");
                            scanf("%d", &numero1);
                            anoParaMeses(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d anos geram %d meses\n\n", numero1, resultado[3]);
                            break;
                        
                        case 2:
                            printf("Digite um valor para meses:\n");
                            scanf("%d", &numero1);
                            mesParaAno(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d meses são %d em anos\n\n", numero1, resultado[3]);
                            break;
                        default:
                            printf("Comando Invalido\n");
                            break;
                        }
                        break;
                    case 4:
                        printf("Voce deseja transformar anos em dias ou dias em anos? 1-anos em dias, 2- dias em anos:\n");
                        scanf("%d", &subOperacao);
                        switch (subOperacao){
                        case 1:
                            printf("Digite um valor para anos:\n");
                            scanf("%d", &numero1);
                            anoParaDias(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d anos geram %d dias\n\n", numero1, resultado[3]);
                            break;
                        
                        case 2:
                            printf("Digite um valor para dias:\n");
                            scanf("%d", &numero1);
                            diaParaAno(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d meses são %d em anos\n\n", numero1, resultado[3]);
                            break;
                        default:
                            printf("Comando Invalido\n");
                            break;
                        }
                        break;
                    case 5:
                        printf("Voce deseja transformar meses em dias ou dias em meses? 1-meses em dias, 2- dias em meses:\n");
                        scanf("%d", &subOperacao);
                        switch (subOperacao){
                        case 1:
                            printf("Digite um valor para meses:\n");
                            scanf("%d", &numero1);
                            mesesParaDias(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d meses geram %d dias\n\n", numero1, resultado[3]);
                            break;
                        
                        case 2:
                            printf("Digite um valor para dias:\n");
                            scanf("%d", &numero1);
                            diaParaMes(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d dias são %d em meses\n\n", numero1, resultado[3]);
                            break;
                        default:
                            printf("Comando Invalido\n");
                            break;
                        }
                        break;
                    case 6:
                        printf("Voce deseja transformar dias em minutos ou minutos em dias? 1-dias em minutos, 2- minutos em dias:\n");
                        scanf("%d", &subOperacao);
                        switch (subOperacao){
                        case 1:
                            printf("Digite um valor para dias:\n");
                            scanf("%d", &numero1);
                            diaParaMinutos(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d dias geram %d minutos\n\n", numero1, resultado[3]);
                            break;
                        
                        case 2:
                            printf("Digite um valor para minutos:\n");
                            scanf("%d", &numero1);
                            minutoParaDia(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d minutos são %d dias\n\n", numero1, resultado[3]);
                            break;
                        default:
                            printf("Comando Invalido\n");
                            break;
                        }
                        break;
                    case 7:
                        printf("Voce deseja transformar minutos em segundos ou segundos em minutos? 1-minutos em segundos, 2- segundos em minutos:\n");
                        scanf("%d", &subOperacao);
                        switch (subOperacao){
                        case 1:
                            printf("Digite um valor para minutos:\n");
                            scanf("%d", &numero1);
                            minutoParaSegundos(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d minutos geram %d segundos\n\n", numero1, resultado[3]);
                            break;
                        
                        case 2:
                            printf("Digite um valor para segundos:\n");
                            scanf("%d", &numero1);
                            segundoParaMinuto(memoria, numero1);
                            resultado = retornaRAM(memoria);
                            printf("%d segundos são %d minutos\n\n", numero1, resultado[3]);
                            break;
                        default:
                            printf("Comando Invalido\n");
                            break;
                        }
                        break;
                    case 8:
                        printf("Digite um valor em dias\n");
                        scanf("%d", &numero1);
                        diasParaTempoADM(memoria, numero1);
                        resultado = retornaRAM(memoria);
                        printf("%d dias equivalem a %d anos %d meses e %d dias\n\n", numero1, resultado[4], resultado[5], resultado[6]);
                        break;
                    default:
                        printf("Comando Invalido\n");
                        break;
                    }
                break;
            case -1:
                printf("Voce saiu da calculadora\n");
                break;
            default:
                printf("Comando Invalido\n");
                break;
        }
        printf("Digite outro comando\n");
        printf("-1 - Sair\t1 - Matematica Basica\t2 - Matematica Aplicada\t3 - Conversoes\n");
        scanf("%d", &comando);
    } while (comando != -1);
    
    free(memoria);
    return 0;
}
// funcaoSoma(memoria, 10, 9);
//     vetor = retornaRAM(memoria)(memoria);
//     printf("Soma %d\n", vetor[3]);
//     funcaoSubtracao(memoria, 10, 9);
//     vetor = retornaRAM(memoria);
//     printf("Subtracao %d\n", vetor[3]);
//     multiplicacao(memoria, 10, 9);
//     vetor = retornaRAM(memoria);
//     printf("Multiplicacao %d\n", vetor[3]);
//     divisao(memoria, 10, 9);
//     vetor = retornaRAM(memoria);
//     printf("Divisao %d\n", vetor[3]);
//     potencia(memoria, 3, 3);
//     vetor = retornaRAM(memoria);
//     printf("Potencia %d\n", vetor[3]);
//     fatorial(memoria, 8);
//     vetor = retornaRAM(memoria);
//     printf("Fatorial %d\n", vetor[3]);


// montarRam(int *memoriaDados){
//     //memoriaRam = numeroAleatório
// }

// montarInstrucoes(int *memoriaInstrucoes){
//     int umaInstrucao[4];
//     for(int i = 0; i < 99; i++){
//         //umaInstrucao[0] = numeroAleatorio
//         //umaInstrucao[1] = numeroAleatorio
//         //umaInstrucao[2] = numeroAleatorio
//         //umaInstrucao[3] = numeroAleatorio
//         memoriaInstrucoes[i] = umaInstrucao;
//     }

//     //umaInstrucao[0] = -1;
//     //umaInstrucao[1] = -1;
//     //umaInstrucao[2] = -1;
//     //umaInstrucao[3] = -1;
//     memoriaInstrucoes[99] = umaInstrucao;
// }
