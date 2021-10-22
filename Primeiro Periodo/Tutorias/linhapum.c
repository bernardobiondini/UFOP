#include <stdio.h>

int main(){
    int n, i = 1;
    scanf ("%d", &n);
    while (i <= n){
        printf ("%d %d %d PUM\n", 4 * i - 3, 4 * i - 2, 4 * i - 1);
        i++;
    }
    return 0;
}