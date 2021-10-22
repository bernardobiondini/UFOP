/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Digite a quantidade de elemnetos do vetor: "); scanf("%d", &n);

    int soma = 0;

    int *vet1 = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        printf("Digite o valor %d do vetor: ", i+1);
        scanf("%d", &vet1[i]);
        soma += vet1[i];
    }

    int media = soma/n;

    int contAcima = 0;
    int contAbaixo = 0;

    int *vet2 = malloc(contAbaixo * sizeof(int));
    int *vet3 = malloc(contAcima * sizeof(int));

    for (int i = 0; i < n; i++){
        if (vet1[i] >= media) {
            contAcima++;
        }
        else {
            contAbaixo++;
        }
    }

    int j = 0;
    int p = 0;

    for (int i = 0; i < n; i++){
        if (vet1[i] >= media) {
            vet3[j] = vet1[i];
            j++;
        }
        else {
            vet2[p] = vet1[i];
            p++;
        }
    }

    printf("O primeiro vetor gerado tem %d valores\nValores do vet2 = {", contAbaixo);
    for (int i = 0; i < contAbaixo-1; i++) printf("%d, ", vet2[i]);
    printf("%d}\n", vet2[contAbaixo-1]);

    printf("O segundo vetor gerado tem %d valores\nValores do vet3 = {", contAcima);
    for (int i = 0; i < contAcima-1; i++) printf("%d, ", vet3[i]);
    printf("%d}\n\n", vet3[contAcima-1]);

    free(vet1);
    free(vet2);
    free(vet3);

    return 0;
}