#include <stdio.h>

int main(){
    int x, y;
    int w; //declarado x, y e a variavel auxiliar
    scanf("%d %d", &x, &y); //le os dois numeros
    if (x > y){ //se o primeiro numero eh maior, eu nao consigo operar com o while (pq eu vou pegar cada numero entre o menor e o maior)
        w = x;
        x = y;
        y = w; //por isso eu faco a troca
    } //agora, se eu digitar o numero maior primeiro, ele sera o y e nao o x. Portanto, todo x sera o menor numero
    int i = x + 1; //aqui eu falo que o i vai se iniciar com o primeiro valor depois do menor numero (que sera sempre x por causa do if acima)
    int soma = 0; //do mesmo jeito, aqui eu inicalizo a soma com o valor 0 (esse valor sera "aumentado" dentro do while)
    while (i <  y){ //enquanto o i (que sera inicialmente o x (menor numero) + 1) for menor que o maior numero, o while executa o bloco:
        if (i % 2 != 0){ //verifico se esse numero eh impar 
            soma += i; //se for eu vou falar que a soma = soma + o numero (a partir do momento em que o programa executar esse comando, soma != 0)
            i++; //ai eu vou somar 1 unidade no i (assim, eu pego o segundo numero depois do menor numero digitado) e volto na condicao
        }
        else //se nao for impar
        i++; //somo 1 unidade no ultimo numero verificado no o while e assim por diante
    } //esse bloco vai acontecer ate a soma de 1 unidade em cada i for menor que o maior numero (y)
    printf ("%d\n", soma); //imprimo a soma que vai ter o valor da soma de todos os i's que sao impares
    return 0;
}