#include <stdio.h>

int main (){

    int x = 1;
    double nota1, nota2, media;

    while (x == 1){
        scanf ("%lf", &nota1);
        if (nota1 < 0 || nota1 > 10)
            printf ("nota invalida\n");
        while (nota1 >= 0 && nota1 <= 10){
            scanf ("%lf", &nota2);
            if (nota2 < 0 || nota2 > 10)
                printf ("nota invalida\n");
            while (nota2 <= 10 && nota2 >= 0){
                media = (nota1 + nota2) / 2;
                printf ("%.2lf\n", media);
                nota1 = -1;
                nota2 = -1;
                printf ("novo calculo (1-sim 2-nao)\n"); scanf ("%d", &x);
                while (x != 1 && x != 2){
                    printf ("novo calculo (1-sim 2-nao)\n"); scanf ("%d", &x);
                
                }
            }
        }
    }
    
    return 0;
}
