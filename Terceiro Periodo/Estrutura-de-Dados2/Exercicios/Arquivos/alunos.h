#ifndef ALUNOS_H
#define ALUNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[30];
    double nota1;
    double nota2;
    double nota3;
    int faltas;
}Aluno;

void alunosMain();

#endif