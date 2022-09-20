#include <stdio.h>

int main(){
    int n;
    printf ("Digite um numero: "); scanf ("%d", &n);

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            printf("(%d, %d)\n", x, y);
        }
    }
    return 0;
}