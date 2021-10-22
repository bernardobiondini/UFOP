#include <stdio.h>

int main(){
    
    FILE *arquivo = fopen("arq.txt", "w");

    char c;

  do{
        scanf("%c", &c);
        fprintf(arquivo, "%c", c);
  }while (c != '0');

    printf("aqui\n");
    fclose(arquivo);
    fopen("arq.txt", "r");

    char c1;

    while(!feof(arquivo)){
        fscanf(arquivo, "%c", &c1);
        printf("%c", c1);
    }
    fclose(arquivo);
    printf("\n");

    return 0;
}