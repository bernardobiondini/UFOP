/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>

typedef struct{
    char nome[30];
    double nota;
    double frequencia;
}Aluno;

int main(int argc, char **argv){
    
    Aluno estudante;

    FILE *arquivo = fopen(argv[1], "r");

    int n;

    fscanf(arquivo, "%d", &n);

    double somaNotas = 0.0, somaFrequencia = 0.0;

    while(!feof(arquivo)){
        fscanf(arquivo, "%s %lf %lf", estudante.nome, &estudante.nota, &estudante.frequencia);
        somaNotas += estudante.nota;
        somaFrequencia += estudante.frequencia;
    }

    double mediaNotas = somaNotas/n;
    double mediaFrequencias = somaFrequencia/n;

    int cont = 0;

    while(!feof(arquivo)){
        fscanf(arquivo, "%s %lf %lf", estudante.nome, &estudante.nota, &estudante.frequencia);
        if (estudante.nota > mediaNotas && estudante.frequencia > mediaFrequencias) cont++;
    }

    double aprovacao = (double)cont/n *100;

    printf ("Nota media: %.2lf\nFrequencia media: %.2lf%%\nPercentual de Aprovacao: %.2lf%%\n", mediaNotas, mediaFrequencias, aprovacao);

    while(!feof(arquivo)){
        fscanf(arquivo, "%s %lf %lf", estudante.nome, &estudante.nota, &estudante.frequencia);
        if (estudante.nota > mediaNotas && estudante.frequencia > mediaFrequencias) printf("%s\n", estudante.nome);
    }
    return 0;
}