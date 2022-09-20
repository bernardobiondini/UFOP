/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>

int main(){
    double nota; 
    double maior=0, menor=100;
    int aluno = 0;
    double soma = 0;    
    do {
        printf ("DIGITE UMA NOTA (ou uma nota negativa para sair): ");
        scanf ("%lf", &nota);
        if (nota >= 0){
            if (nota > maior)
            maior = nota;
            if (nota < menor)
            menor = nota;
            soma += nota;
            aluno++;
        }
        
        
    } while (nota > 0);
    printf ("A media das %d notas e %.2lf\n", aluno, (double)soma/aluno);
    printf ("A maior nota e: %.2lf\n", maior);
    printf ("A menor nota e: %.2lf\n", menor);
    return 0;
}
