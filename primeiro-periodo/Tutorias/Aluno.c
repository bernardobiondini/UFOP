#include <stdio.h> 
#include <string.h>

typedef struct{
    char nome[30];
    int matricula;
    char disciplina[30];
    double notas[3];
}Aluno;

void leitura(Aluno *aluno, double *soma){
    fgets(aluno->nome, 30, stdin);//le o nome do aluno
    aluno->nome[strlen(aluno->nome) - 1] = '\0';//tira o \n do final
    
    scanf("%d", &aluno->matricula);

    getchar(); //limpa o buffer

    fgets(aluno->disciplina, 30, stdin);
    aluno->disciplina[strlen(aluno->disciplina) - 1] = '\0';

    for (int i = 0; i < 3; i++){
        scanf("%lf", &aluno->notas[i]);
        *soma += aluno->notas[i]; //soma as notas do aluno ponteiro pois o valor sera usado na funcao de media
    }
}
double media(double *soma){
    double media = *soma/3;
    return media;
}
void impressao(double media, Aluno *aluno){
    printf("A media de %s na disciplina %s foi %.2lf\n", aluno->nome, aluno->disciplina, media);
}

int main (){
    Aluno aluno;

    double soma = 0.0;
    
    leitura(&aluno, &soma);
    
    double m = media(&soma);

    impressao(m, &aluno);

    return 0;
}