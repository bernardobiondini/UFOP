#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct{
    char data[11];
    int duracao;
}Evento;

int main(){
    Evento Data;
    
    fgets(Data.data, 11, stdin);
    
    scanf("%d", &Data.duracao);

    char day[2], month[2], year[4];
    
    for (int i = 0; i < 2; i++){
        day[i] = Data.data[i];
    }
    for(int j = 3; j < 5; j++){
        month[j-3] = Data.data[j];
    }
    for (int z = 6; z < 10; z++){
        year[z-6] = Data.data[z];
    }
    
    printf("%s %s %s\n", day, month, year);
    
    
    int dia, mes, ano;

    dia = atoi(day);
    mes = atoi(month);
    ano = atoi(year);
    

    if (dia > 30 || mes>12){
        printf("Data invalida\n");
    }
    
    else {
        dia += Data.duracao;

        if (dia > 30){
            dia = Data.duracao - dia;
            mes += 1;
        }
    }
    printf ("%d / %d / %d\n", dia, mes, ano);

    return 0;
}