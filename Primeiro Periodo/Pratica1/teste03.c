/* Programa que converte um valor em graus celsius para graus fahrenheit e kelvin
Bernardo Cavanellas Biondini
No de matricula: 20.1.4112
BCC201-43
*/

#include <stdio.h>

int main ()
{	
    float f, k, c;
	
    printf ("Digite um valor para Celsius\n");
	
    scanf ("%f", &c);
	
    f = 9 / 5.0 * c + 32;
    k = c + 273.15;
	
    printf ("%.2f graus Celsius em Fahrenheit = %.2f, e em Kelvins = %.2f\n", c, f, k);
	
    return 0;
}
