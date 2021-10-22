#include "alunos.h"

void alunosMain(){
    int numAlunos;
    printf("Digite a quantidade de alunos\n");
    scanf("%d", &numAlunos);
    
    Aluno aluno;

    FILE *alunos;

    if((alunos = fopen("alunos.txt", "w+")) == NULL){
        printf("Impossivel abrir o arquivo\n");
        exit(0);
    }
    int x = numAlunos;

    while(numAlunos != 0){
        printf("\nDados do aluno %d\n", x-numAlunos+1);
        printf("Digite a matricula: ");
        scanf("%d", &aluno.matricula);
        while(aluno.matricula < 1000 || aluno.matricula > 9999){
            printf("numero de matrícula invalido\n");
            printf("digite outro numero de matricula");
            scanf("%d", &aluno.matricula);
        }
        printf("Digite o nome: ");
        setbuf(stdin, NULL);
        fgets(aluno.nome, 30, stdin);
        aluno.nome[strlen(aluno.nome)-1] = '\0';
        printf("Digite a nota1: ");
        scanf("%lf", &aluno.nota1);
        while(aluno.nota1 > 10.0 || aluno.nota1 < 0.0){
            printf("nota invalida\n digite outra nota 1");
            scanf("%lf", &aluno.nota1);
        }
        printf("Digite a nota2: ");
        scanf("%lf", &aluno.nota2);
        while(aluno.nota2 > 10.0 || aluno.nota2 < 0.0){
            printf("nota invalida\n digite outra nota 2");
            scanf("%lf", &aluno.nota2);
        }
        printf("Digite a nota3: ");
        scanf("%lf", &aluno.nota3);
        while(aluno.nota3 > 10.0 || aluno.nota3 < 0.0){
            printf("nota invalida\n digite outra nota 3");
            scanf("%lf", &aluno.nota3);
        }
        printf("Digite as faltas: ");
        scanf("%d", &aluno.faltas);

        fprintf(alunos, "%d %s", aluno.matricula, aluno.nome);
        int tamanhoNome = 30 - strlen(aluno.nome);
        while(tamanhoNome != 0){
            char c = ' ';
            fputc(c, alunos);
            tamanhoNome--;
        }

        fprintf(alunos, " %.1lf %.1lf %.1lf %d\n", aluno.nota1, aluno.nota2, aluno.nota3, aluno.faltas);
        numAlunos--;
    }
    fclose(alunos);
}
