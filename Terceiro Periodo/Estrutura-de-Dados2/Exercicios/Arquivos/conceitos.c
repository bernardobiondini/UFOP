#include "conceitos.h"

void conceitosMain(){
    Conceitos aluno;

    FILE *alunos;
    FILE *conceitos;

    if((alunos = fopen("alunos.txt", "r")) == NULL){
        printf("Impossivel abrir o arquivo\n");
        exit(0);
    }
    if((conceitos = fopen("conceitos.txt", "w+")) == NULL){
        printf("Impossivel abrir o arquivo\n");
        exit(0);
    }

    while(feof(alunos) != EOF){
        fscanf(alunos, "%d" , &aluno.matricula);
        fseek(alunos, 1, 1);
        fgets(aluno.nome, 30, alunos);
        fscanf(alunos, "%lf %lf %lf %d", &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.faltas);

        aluno.media = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0;

        if(aluno.faltas > 18) aluno.conceito = 'F';
        else if(aluno.faltas <= 18 && aluno.media <= 6.0) aluno.conceito = 'R';
        else if(aluno.faltas <= 18 && aluno.media <= 7.5) aluno.conceito = 'C';
        else if(aluno.faltas <= 18 && aluno.media <= 9.0) aluno.conceito = 'B';
        else if(aluno.faltas <= 18 && aluno.media <= 10.0) aluno.conceito = 'A';
        
        //fseek(alunos, 1, 1); 
        if(feof(alunos)) break;   

        fprintf(conceitos, "%d %s %c\n", aluno.matricula, aluno.nome, aluno.conceito);
    }
    fclose(alunos);
    fclose(conceitos);
}