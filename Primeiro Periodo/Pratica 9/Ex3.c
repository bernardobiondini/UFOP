/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30];
    double nota;
    double frequencia;
}Aluno;

int main(int argc, char **argv){
    Aluno estudante;
    int n;
    
    FILE *arquivo = fopen(argv[1], "w");
    
    printf("Voce quer amazenar informacoes de quantos alunos? "); scanf("%d", &n);
    fprintf(arquivo, "%d\n", n);

    int i = 0;
    
    do{
        getchar();
        printf("Digite o nome do aluno: ");
        fgets(estudante.nome, 30, stdin);
        estudante.nome[strlen(estudante.nome) - 1]  = '\0';
        fprintf (arquivo, "%s ", estudante.nome);
        printf("Digite a nota do aluno: ");
        scanf("%lf", &estudante.nota);
        fprintf (arquivo, "%.2lf  ", estudante.nota);
        printf("Digite a frequencia do aluno: ");
        scanf("%lf", &estudante.frequencia);
        fprintf (arquivo, "%.2lf\n", estudante.frequencia);
        i++;
    }while(i < n);

    return 0;
}