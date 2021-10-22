// program que le uma letra e fla se ela eh ou nao uma vogal.


#include <stdio.h>

int main () {
    
    char letra;
   
    printf ("Digite a letra desejada: ");
    scanf ("%c", &letra);
   
    if (letra == 'a' || letra == 'A' ||letra == 'E' ||letra == 'e' ||letra == 'i' ||letra == 'I' ||letra == 'o' ||letra == 'O' ||letra == 'U' ||letra == 'u'){
       printf ("'%C' eh uma vogal\n", letra);
    }   
    if (letra != 'a' && letra != 'A' && letra != 'E' &&letra != 'e' && letra != 'i' && letra != 'I' && letra != 'o' && letra != 'O' && letra != 'U' && letra != 'u'){
       printf ("'%C' eh uma consoante\n", letra);
    }
    
    return 0;
}    
