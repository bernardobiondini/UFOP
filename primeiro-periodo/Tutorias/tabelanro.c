#include <stdio.h>

int main(){
    
    int n, i = 1;

    scanf ("%d", &n);

    if (n>2 && n< 1000){
        while (i <= 10){
            printf("%d x %d = %d\n", i, n, i * n);
            i++;
        }
    }
    return 0;
}