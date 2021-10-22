/* programa que le o valor das variáveis a, b, c e d do tipo float e
calcula o resultado da expressão x = (a*a*a) ((b+c)/d)
Bernardo Cavanellas Biondini
No de matricula: 20.1.4112
BCC201-43
*/

#include <stdio.h>

int main ()
{    
    float x, a, b, c, d;
    
    printf ("digite os valores de a, b, c e d:\n");
    scanf ("%f", &a);
    scanf ("%f", &b);
    scanf ("%f", &c);
    scanf ("%f", &d);
    
    x = (a * a * a) * ((b + c) / d);
    
    printf ("\na = %.0f, b = %.0f, c = %.0f, d = %.0f", a, b, c, d);
    printf ("\nx = %.0f\n", x);
    return 0;
}    
