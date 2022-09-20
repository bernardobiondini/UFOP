/* Escreva um programa que leia de 3 n´umeros inteiros. Em seguida, o programa deve verificar qual dos
* valores ´e o menor, o intermedi´ario e o maior.
* Supondo as entradas 23, 11, 31, a sa´ıda do programa seria:
* Menor: 11
* Intermediario: 23
*/// Maior: 31

#include <stdio.h>

int main (){
    
    int x, y, z;
    
    printf ("Digite os valores de x, y e z:\n");
    scanf ("%d %d %d", &x, &y, &z);
    
    if ((x > y) && (x >z) && (y > z)){
       printf ("Menor: %d\nIntermediario: %d\nMaior: %d\n", z, y, x);
    }   
    
    if ((x > y) && (x >z) && (z > y)){
       printf ("Menor: %d\nIntermediario: %d\nMaior: %d\n", y, z, x);
    }   
    
    if ((y > x) && (y >z) && (x > z)){
       printf ("Menor: %d\nIntermediario: %d\nMaior: %d\n", z, x, y);
    }   
    
    if ((y > x) && (y >z) && (z > x)){
       printf ("Menor: %d\nIntermediario: %d\nMaior: %d\n", x, z, y);
    }   
    
    if ((z > y) && (z > x) && (y > x)){
       printf ("Menor: %d\nIntermediario: %d\nMaior: %d\n", x, y, z);
    }   
    
    if ((z > y) && (z > x) && (x > y)){
       printf ("Menor: %d\nIntermediario: %d\nMaior: %d\n", y, x, z);
    }   
    
    return 0;
}    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
