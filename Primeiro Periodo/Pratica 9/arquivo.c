#include <stdio.h>

int main(){
    
    FILE *arquivo = fopen("arq.txt", "w+");

    char c;

    do{
        getchar();
        scanf("%c", &c);
        fprintf(arquivo, "%c", c);
    }while (c != '0');

    fclose(arquivo);
    fopen("arq.txt", "r");

    char c1;

    while(!feof(arquivo)){
        fscanf(arquivo, "%c", &c1);
        printf("%c", c1);
    }
    fclose(arquivo);

    return 0;
}