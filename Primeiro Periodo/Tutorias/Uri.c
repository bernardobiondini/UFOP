#include <stdio.h>
#include <stdlib.h>

int main(){
    int coluna;
    char c;

    scanf("%d", &coluna);
    coluna = coluna - 1;
    getchar();
    scanf("%c", &c);

    double **m = malloc(12 * sizeof(double *));

    for (int i = 0; i < 12; i++){
        m[i] = malloc(12 * sizeof(double));
    }
    
    double somaElementos = 0;

    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            scanf("%lf", &m[i][j]);
            if(j == coluna) somaElementos += m[i][j];
        }
    }

    double media;

    if(c == 'M'){
        media = somaElementos/12;
        printf("%.1lf\n", media);
    }
    else{
        printf("%.1lf\n", somaElementos);
    }

    for (int i = 0; i < 12; i++)
        free(m[i]);
    free(m);
    

    return 0; 
}