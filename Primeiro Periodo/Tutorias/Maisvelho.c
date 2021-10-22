#include <stdio.h>
#include <string.h>
#define x 30


int main(){

    char nome1[x], nome2[x];
    int idade1, idade2;

    scanf ("%s", nome1);
    scanf("%d", &idade1);
    fflush(stdin);
    scanf ("%s", nome2);
    scanf("%d", &idade2);
    fflush(stdin);

    if (idade1 > idade2)
        printf ("%s eh a pessoa mais velha\n", nome1);
    else 
        printf ("%s eh a pessoa mais velha\n", nome2);
    return 0;
}