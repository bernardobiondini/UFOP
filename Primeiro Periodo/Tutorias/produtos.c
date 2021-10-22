/*Faça um programa que, dado um número de clientes, preencha a quantidade dos 5
produtos comprados por ele. Para isso, utilize uma matriz alocada dinamicamente.
Considerando a tabela preço dos produtos, calcule e imprima o valor final à ser pago
por cada cliente.
Dica: Crie um vetor com os valores dos produtos.
Produto 1: R$5
Produto 2: R$15
Produto 3: R$9
Produto 4: R$20
Produto 5: R$34*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main(){
    int n;
    printf("Digite a quantidade de clientes: "); scanf("%d", &n);
    int **m;
    int *total;
    
    total = malloc(n * sizeof(int));
    m = malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){ m[i] = malloc(5 * sizeof(int));}
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            printf("Digite quantos produtos do tipo %d o cliente %d comprou: ", j+1, i+1);
            scanf("%d", &m[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        m[i][0] = m[i][0] * 5;
        m[i][1] = m[i][1] * 15;
        m[i][2] = m[i][2] * 9;
        m[i][3] = m[i][3] * 20;
        m[i][4] = m[i][4] * 34;
    }
    for (int i = 0; i < n; i++){
        int soma = 0;
        for (int j = 0; j < 5; j++){
            soma += m[i][j];
        }
        total[i] = soma;
        printf("O cliente %d tera que pagar R$%d\n", i+1, total[i]);
    }
    for (int i = 0; i < n; i++)
    {
        free(m[i]);
    }
    free(m);
    free(total);
}