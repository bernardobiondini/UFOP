/* Bernardo Cavanellas Biondini
* 20.1.4112
* Turma 43 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Digite a quantidade de alunos: "); scanf("%d", &n);

    double *v1 = malloc(n * sizeof(double));
    double *v2 = malloc(n * sizeof(double));
    double *v3 = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++){
        printf("Digite a primeira nota do aluno %d: ", i+1);
        scanf("%lf", &v1[i]);
        printf("Digite a segunda nota do aluno %d: ", i+1);
        scanf("%lf", &v2[i]);
        v3[i] = ((4 * v1[i]) + (6 * v2[i])) / 10;
    }
    printf("v3 = {");
    for (int i = 0; i < n-1; i++){
        printf("%.1lf, ", v3[i]);
    }
    printf("%.1lf}.\n\n", v3[n-1]);

    free(v1);
    free(v2);
    free(v3);
    
    return 0;
}