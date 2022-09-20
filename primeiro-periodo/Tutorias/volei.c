#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    int saques;
    int acertoSaque;
    int bloqueio;
    int acertoBloqueio;
    int ataque;
    int acertoAtaque;
}Jogador;

int main(){
    int n;
    scanf("%d", &n);

    Jogador *jogador = malloc (n * sizeof(Jogador));

    int somaSaque = 0, somaAtaque = 0, somaBloqueio = 0;
    int somaAcertoSaque = 0, somaAcertoAtaque = 0, somaAcertoBloqueio = 0;

    for (int i = 0; i < n; i++){
        getchar();
        scanf("%s", jogador[i].nome);
        scanf("%d", &jogador[i].saques);
        scanf("%d", &jogador[i].bloqueio);
        scanf("%d", &jogador[i].ataque);
        scanf("%d", &jogador[i].acertoSaque);
        scanf("%d", &jogador[i].acertoBloqueio);
        scanf("%d", &jogador[i].acertoAtaque);
        somaSaque += jogador[i].saques;
        somaAcertoSaque += jogador[i].acertoSaque;
        somaBloqueio += jogador[i].bloqueio;
        somaAcertoBloqueio += jogador[i].acertoBloqueio;
        somaAtaque += jogador[i].ataque;
        somaAcertoAtaque += jogador[i].acertoAtaque;
    }

    double pontoSaque = (double)somaAcertoSaque * 100.0/somaSaque;
    double pontoBloqueio = (double)somaAcertoBloqueio * 100.0/somaBloqueio;
    double pontoAtaque = (double)somaAcertoAtaque * 100.0/somaAtaque;

    printf("Pontos de Saque: %.2lf %%.\n", pontoSaque);
    printf("Pontos de Bloqueio: %.2lf %%.\n", pontoBloqueio);
    printf("Pontos de Ataque: %.2lf %%.\n", pontoAtaque);

    return 0;
}