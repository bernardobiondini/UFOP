#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    
    srand (time(NULL));
    int i = 20;
    
    while (i <= 29){
    int Noaleatorio = i + rand() % (200 - i + 1);
    printf ("Numero gerado = %d\n", Noaleatorio);
    i++;
    }
    
    return 0;
}    
    
    