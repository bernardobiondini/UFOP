#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int N[100];

    for (int i = 0; i < n; i++){
        scanf("%d", &N[i]);
    }

    FILE *arquivo = fopen("arq.dat", "wb");

    fwrite(&n, sizeof(int), 1, arquivo);
    fwrite(N, sizeof(int), n, arquivo);

    fclose(arquivo);
    return 0;

}