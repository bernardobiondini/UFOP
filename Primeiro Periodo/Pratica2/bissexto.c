// programa que le um ano e diz se ele eh ou nao um ano bissexto

#include <stdio.h>

int main(){
    
    int ano;
    
    printf ("Digite um ano:");
    scanf ("%d", &ano);
    
    if (ano % 4 == 0){
       printf ("\nO ano de %d eh bissexto\n", ano);
    }   
    
    if ((ano % 100 == 0) && (ano % 400 == 0)){
        printf ("\nO ano de %d eh bissexto\n", ano);
    }   
    
    if (ano != (ano % 4 == 0) && ((ano % 100 == 0) && (ano % 400 == 0))){
       printf ("\nO ano de %d nao eh bissexto\n", ano);
    }   
     
     return 0;
}     
