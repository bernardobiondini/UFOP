#ifndef CONCEITOS_H
#define CONCEITOS_H

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
    double media;
    char conceito;
}Conceitos;

void conceitosMain();

#endif