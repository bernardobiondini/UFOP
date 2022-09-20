#include <stdio.h>

int main(){
    int x, n=1;
    scanf ("%d", &x);
    int soma = 0;
    while((x != 0)&&(n <= 5)){
        if (x % 2 == 0){
            soma = x + x+2 + x+4 + x+6 + x+8;
            x = x + 2;
            n++;
        }
        else {
            soma = x+1 + x+3 + x+5 + x+7 + x+9;
            x = x + 2;
            n++;
        }
    printf("%d\n", soma);scanf ("%d", &x);    
    }
    printf("%d\n", soma);
    return 0;
}