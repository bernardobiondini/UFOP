// Algoritimo que gera um numero aleatorio a partir da entrada de um numero que esteja entre dois outros

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    
    srand (time(NULL));
    int A, B;
    
    printf ("Digite os valores de A e B\n");
    scanf ("%d %d", &A, &B);
    
    int Noaleatorio = A + rand() % (B - A + 1);
    
    printf ("Numero gerado = %d\n", Noaleatorio);
    
    return 0;
}    
    
    
