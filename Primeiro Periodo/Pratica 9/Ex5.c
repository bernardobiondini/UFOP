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

int main(){
    char nomeArquivo[30], arquivoDat[30];
    printf("Digite o nome do arquivo texto: ");
    fgets(nomeArquivo, 30, stdin);
    nomeArquivo[strlen(nomeArquivo) - 1] = '\0';

    for(int i = 0; i < strlen(nomeArquivo) - 3; i++){
        arquivoDat[i] = nomeArquivo[i];
    }

    strcat(arquivoDat, "dat");

    printf("Arquivo %s criado com sucesso!\n", arquivoDat);
    
    
    FILE *arquivotxt = fopen(nomeArquivo, "r");
    FILE *arquivodat = fopen(arquivoDat, "wb+");
    
    int n;
    Aluno estudante;

    fscanf(arquivotxt, "%d", &n);
    fwrite(&n, sizeof(int), 1, arquivodat);

    while(!feof(arquivotxt)){
        fscanf(arquivotxt, "%s %lf %lf", estudante.nome, &estudante.nota, &estudante.frequencia);
        fwrite(estudante.nome, sizeof(Aluno), 30, arquivodat);
        fwrite(&estudante.nota, sizeof(double), 1, arquivodat);
        fwrite(&estudante.frequencia, sizeof(double), 1, arquivodat);
    }

    fclose(arquivotxt);

    fseek(arquivodat, 0, SEEK_SET);

    double somaNotas = 0.0, somaFrequencia = 0.0;

    while(!feof(arquivodat)){
        fread(&estudante.nota, sizeof(double), 1, arquivodat);
        fread(&estudante.frequencia, sizeof(double), 1, arquivodat);
        somaNotas += estudante.nota;
        somaFrequencia += estudante.frequencia;
    }

    double mediaNotas = somaNotas/n;
    double mediaFrequencias = somaFrequencia/n;

    int cont = 0;

    while(!feof(arquivodat)){
        fread(&estudante.nota, sizeof(double), 1, arquivodat);
        fread(&estudante.frequencia, sizeof(double), 1, arquivodat);
        if (estudante.nota > mediaNotas && estudante.frequencia > mediaFrequencias) cont++;
    }

    double aprovacao = (double)cont/n *100;

    printf ("Nota media: %.2lf\nFrequencia media: %.2lf%%\nPercentual de Aprovacao: %.2lf%%\n", mediaNotas, mediaFrequencias, aprovacao);

    while(!feof(arquivodat)){
        fread(estudante.nome, sizeof(char), 30, arquivodat);
        fread(&estudante.nota, sizeof(double), 1, arquivodat);
        fread(&estudante.frequencia, sizeof(double), 1, arquivodat);
        if (estudante.nota > mediaNotas && estudante.frequencia > mediaFrequencias) printf("%s\n", estudante.nome);
    }
    
    return 0;
}