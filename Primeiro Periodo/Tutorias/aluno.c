/*Crie uma struct Aluno com o nome, a matrícula e uma matriz que deve armazenar as
notas do aluno nas disciplinas que ele está matriculado. Crie uma função que aloque a
matriz de notas de acordo com a quantidade de provas e de disciplinas que o aluno tem.
A função também deve inserir as notas das disciplinas na matriz. Crie uma função que
calcule a média do aluno em cada disciplina e mostre se o aluno foi ou não aprovado
na disciplina.
Crie uma função para desalocar dinamicamente a matriz. Implemente o programa
principal para usar as funções acima.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int matricula;
    double **m;
}Aluno;

void alocaELeMatriz(Aluno *aluno, int x, int y){
    aluno->m = malloc(x * sizeof(double *));
    for (int i = 0; i < x; i++){
        aluno->m[i] = malloc(y * sizeof(double));
    }
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("Digite a nota %d do aluno na disciplina %d: ", i+1, j+1);
            scanf("%lf", &aluno->m[i][j]);
        }
    }
}
void calculaMedia(Aluno *aluno, int x, int y){
    double *media;
    media = malloc(x * sizeof(double));
    
    for (int i = 0; i < x; i++){
        double soma = 0;
        for (int j = 0; j < y; j++){
            soma += aluno->m[i][j];
        }
        media[i] = soma/x;
    }
    for (int i =0; i < x; i++){
        if(media[i] > 6) printf("Aprovado na disciplina %d!\n", i+1);
        else printf("Reprovado na disciplina %d!\n", i+1);
    }
    free(media);
}
void LiberaMatriz(Aluno *aluno, int x){
    for (int i = 0; i < x; i++)
    {
        free(aluno->m[i]);
    }
    free(aluno->m);
}
int main(){
    Aluno aluno;
    int disciplinas, provas;
    
    printf("Qual eh o nome do aluno? ");
    fgets(aluno.nome, 20, stdin);
    aluno.nome[strlen(aluno.nome)-1] = '\0';

    printf("Digite a matricula do aluno: "); scanf("%d", &aluno.matricula);

    printf("Digite o numero de disciplinas do aluno %s: ", aluno.nome);
    scanf("%d", &disciplinas);
    
    printf("Digite o numero de provas de cada disciplina: ");
    scanf("%d", &provas);

    alocaELeMatriz(&aluno, disciplinas, provas);
    calculaMedia(&aluno, disciplinas, provas);
    LiberaMatriz(&aluno, disciplinas);

    return 0;
}