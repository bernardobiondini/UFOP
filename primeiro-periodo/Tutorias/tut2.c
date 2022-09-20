#include <stdio.h>

int main(){
    int x, n, N[100];
    scanf("%d", &x);

    FILE *arquivo = fopen("arq.dat", "rb");

    fread(&n, sizeof(int), 1, arquivo);
    fread(N, sizeof(int), n, arquivo);

    fclose(arquivo);

    int cont = 0;

    for (int i = 0; i < n; i++){
        if (N[i] == x) cont++;
    }
    
    printf("O numero %d apareceu %d vezes\n", x, cont);

    return 0;
}