#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if ((n < 0) || (n > 13))
        return 0;
    int fatorial = 1;
    while (n > 0){
        fatorial *= n;
        n--;
    }
    printf("%d\n", fatorial);
    return 0;
}