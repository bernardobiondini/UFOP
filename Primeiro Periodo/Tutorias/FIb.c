#include <stdio.h>
#define x 61

int main(){
    int T, N;
    long int Fib[x] = {0, 1};
    scanf("%d", &T); //quantos numeros voce quer que sejam encontrados na sequencia?
    for (int i = 0; i < T; i++){
        scanf ("%d", &N); //numero de posicao i
        for (int j = 2; j < x; j++){
            Fib[j] = Fib[j-1] + Fib[j-2];//confere o numero na posicao informada
        }
        printf ("Fib(%d) = %ld\n", N, Fib[N]);//imprime a posicao do numero na sequencia
    }
    return 0;
}