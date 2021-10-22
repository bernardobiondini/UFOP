/* programa que le o valor de x1, x2 e x3 para calcular e imprimir o rstd
de y = ((x1 + x2*x2 + x3 * x3) * (x1 + x2 * x2 + x3 * x3)) + ((x1 * x2 * x3) * (x1 * x2 * x3))
Bernardo Cavanellas Biondini
No de matricula: 20.1.4112
BCC201-43
*/

#include <stdio.h>
int main()
{
	float y, x1, x2, x3;
	printf ("Digite os valores de x1, x2 e x3:\n");
	
	scanf ("%f %f %f", &x1, &x2, &x3);
	
	y = (x1 + (x2 * x2) + (x3 * x3)) * (x1 + (x2 * x2) + (x3 * x3)) - ((x1 * x2 * x3) * (x1 * x2 * x3));
	
	printf ("y = %.2f\n", y);
	
	return 0;
}
