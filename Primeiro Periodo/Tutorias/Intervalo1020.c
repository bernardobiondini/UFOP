#include <stdio.h>

int main(){
    int n, i=1;
    long x;
    long somain = 0;
    long somaout = 0;
    scanf ("%d", &n);
    while (i <= n){
        scanf("%ld", &x);
        if ((x <= 20) && (x >= 10)){
            somain += 1;
            i++;
        }
        else{
            somaout += 1;
            i++;
        }
    }
    printf ("%ld in\n", somain);
    printf ("%ld out\n", somaout);
    return 0;
}