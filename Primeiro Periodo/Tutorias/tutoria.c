// Programa que le a temperatura em graus Celsius e converte para graus Fahrenheit

#include <stdio.h>

int main () {

    float C, F;
    
    printf ("Digite a temperatura em graus Celsius: ");
    scanf ("%f", &C);
    
    F = (9 * C + 160)/5;
    
    printf ("%.0f graus Fahrenheit\n", F);
    
    return 0;
}    
