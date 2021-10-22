#include <stdio.h>
#define x 10000

int main (){
    int n, falha[x];
    scanf("%d", &n); //numero de medicoes do motor
    for (int i = 0; i < n; i++){
        scanf ("%d", &falha[i]); //numero de rotacoes por minuto a cada medida
    }
    for (int j = 1; j < n; j++){
        if (falha[j] < falha[j-1]){ //se a medida atual for menor que a anterior
            printf("%d\n", j + 1);//houve uma queda, em qual das medicoes a queda aconteceu?
            return 0; 
        }
        
    }
    printf ("0\n");
    return 0;
}