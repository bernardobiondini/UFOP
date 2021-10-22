
#include <stdio.h>


void troca(int *A, int *B, int *C){
    int aux1 = *A;
    *A = *B;
    *B = *C;
    *C = aux1;
}

int main (){
    int A, B, C;
    printf ("Digite os Valores de A, B e C:\n");
    scanf ("%d %d %d", &A, &B, &C);
    troca(&A, &B, &C);
    printf ("A = %d\nB = %d\nC = %d\n", A, B, C);
    return 0;
}