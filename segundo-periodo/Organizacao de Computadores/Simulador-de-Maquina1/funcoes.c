#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*opcode
0 -> Somar
1 -> Subtrair
2 -> Salvar na memoria
-1 -> HALT
*/

struct memoria{
    int RAM[100]; 
    int MemoriaInstrucoes[2000][4]; 
};
Memoria* alocaMemoria(){
 
    Memoria *memoria = malloc(sizeof(Memoria));

    return memoria;
}
void Free(Memoria **memoria){
    free(memoria);
    memoria = NULL;
}
int *retornaRAM(Memoria *memoria){
    return memoria->RAM;
}
void maquina(Memoria *memoria){
    int cont = 0;
    int opcode = 218485;
    int *umaInstrucao;
    while(opcode != -1){
        int *umaInstrucao = memoria->MemoriaInstrucoes[cont];
        opcode = umaInstrucao[0];
        
        maquinaInterpretada(umaInstrucao, memoria);
        cont++;
    }
}
void maquinaInterpretada(int *umaInstrucao, Memoria *memoria){
    int opcode, num, end1, end2, end3;
    opcode = umaInstrucao[0];

    switch (opcode){
        
        //Somar
        case 0:
            end1 = umaInstrucao[1];
            end2 = umaInstrucao[2];
            end3 = umaInstrucao[3];

            memoria->RAM[end3] = memoria->RAM[end1] + memoria->RAM[end2];
            break;
        //Subtrair
        case 1:
            end1 = umaInstrucao[1];
            end2 = umaInstrucao[2];
            end3 = umaInstrucao[3];

            memoria->RAM[end3] = memoria->RAM[end1] - memoria->RAM[end2];
            break;
        //Salvar
        case 2:
            num = umaInstrucao[1];
            end1 = umaInstrucao[2];

            memoria->RAM[end1] = num;
            break;
        case 3:
            end1 = umaInstrucao[2];

            num = memoria->RAM[end1];
            umaInstrucao[1] = num;
            break;
    }
}


void funcaoSoma(Memoria *memoria, int num1, int num2){
    memoria->MemoriaInstrucoes[0][0] = 2;
    memoria->MemoriaInstrucoes[0][1] = num1;
    memoria->MemoriaInstrucoes[0][2] = 0;
    memoria->MemoriaInstrucoes[0][3] = -1;
    //num1 na posicao 0
    memoria->MemoriaInstrucoes[1][0] = 2;
    memoria->MemoriaInstrucoes[1][1] = num2;
    memoria->MemoriaInstrucoes[1][2] = 1;
    memoria->MemoriaInstrucoes[1][3] = -1;
    //num2 posicao 1
    memoria->MemoriaInstrucoes[2][0] = 0;
    memoria->MemoriaInstrucoes[2][1] = 0;
    memoria->MemoriaInstrucoes[2][2] = 1;
    memoria->MemoriaInstrucoes[2][3] = 3;
    //soma o que ta na 0 com o que ta na 1 e guarda na 3
    memoria->MemoriaInstrucoes[3][0] = -1;
    memoria->MemoriaInstrucoes[3][1] = -1;
    memoria->MemoriaInstrucoes[3][2] = -1;
    memoria->MemoriaInstrucoes[3][3] = -1;
    //halt

    maquina(memoria);
}
void funcaoSubtracao(Memoria *memoria, int num1, int num2){
    memoria->MemoriaInstrucoes[0][0] = 2;
    memoria->MemoriaInstrucoes[0][1] = num1;
    memoria->MemoriaInstrucoes[0][2] = 0;
    memoria->MemoriaInstrucoes[0][3] = -1;
    //num1 na posicao 0
    memoria->MemoriaInstrucoes[1][0] = 2;
    memoria->MemoriaInstrucoes[1][1] = num2;
    memoria->MemoriaInstrucoes[1][2] = 1;
    memoria->MemoriaInstrucoes[1][3] = -1;
    //num2 na posicao 1
    memoria->MemoriaInstrucoes[2][0] = 1;
    memoria->MemoriaInstrucoes[2][1] = 0;
    memoria->MemoriaInstrucoes[2][2] = 1;
    memoria->MemoriaInstrucoes[2][3] = 3;
    //subtrai o que ta na 0 com o que esta na 1
    memoria->MemoriaInstrucoes[3][0] = -1;
    memoria->MemoriaInstrucoes[3][1] = -1;
    memoria->MemoriaInstrucoes[3][2] = -1;
    memoria->MemoriaInstrucoes[3][3] = -1;
    //halt
    maquina(memoria);
}
void multiplicacao(Memoria *memoria, int num1, int num2){
    memoria->MemoriaInstrucoes[0][0] = 2;
    memoria->MemoriaInstrucoes[0][1] = num1;
    memoria->MemoriaInstrucoes[0][2] = 0;
    memoria->MemoriaInstrucoes[0][3] = -1;
    //num1 na posicao 0
    memoria->MemoriaInstrucoes[1][0] = 2;
    memoria->MemoriaInstrucoes[1][1] = 0;
    memoria->MemoriaInstrucoes[1][2] = 3;
    memoria->MemoriaInstrucoes[1][3] = -1;
    //num2 na posicao 3
    for (int i = 0; i < num2; i++){
        memoria->MemoriaInstrucoes[i+2][0] = 0;
        memoria->MemoriaInstrucoes[i+2][1] = 0;
        memoria->MemoriaInstrucoes[i+2][2] = 3;
        memoria->MemoriaInstrucoes[i+2][3] = 3;
    }//[3] = [0] + [3]

    memoria->MemoriaInstrucoes[num2 + 2][0] = -1;
    memoria->MemoriaInstrucoes[num2 + 2][1] = -1;
    memoria->MemoriaInstrucoes[num2 + 2][2] = -1;
    memoria->MemoriaInstrucoes[num2 + 2][3] = -1;

    maquina(memoria);
}
void divisaoEResto(Memoria *memoria, int num1, int num2){
    int cont = 0, instrucaoAux[4], aux1, aux2;
    
    memoria->MemoriaInstrucoes[0][0] = 2;
    memoria->MemoriaInstrucoes[0][1] = num1;
    memoria->MemoriaInstrucoes[0][2] = 0;
    memoria->MemoriaInstrucoes[0][3] = -1;

    memoria->MemoriaInstrucoes[1][0] = 2;
    memoria->MemoriaInstrucoes[1][1] = num2;
    memoria->MemoriaInstrucoes[1][2] = 1;
    memoria->MemoriaInstrucoes[1][3] = -1;

    memoria->MemoriaInstrucoes[2][0] = -1;
    memoria->MemoriaInstrucoes[2][1] = -1;
    memoria->MemoriaInstrucoes[2][2] = -1;
    memoria->MemoriaInstrucoes[2][3] = -1;

    maquina(memoria);

    // instrucaoAux[0] = 3;
    // instrucaoAux[1] = 0;
    // instrucaoAux[2] = 0;
    // instrucaoAux[1] = -1;

    // maquinaInterpretada(instrucaoAux, memoria);
    aux1 = num1;

    // instrucaoAux[0] = 3;
    // instrucaoAux[1] = 0;
    // instrucaoAux[2] = 1;
    // instrucaoAux[1] = -1;
    
    // maquinaInterpretada(instrucaoAux, memoria);
    aux2 = num2;

    //aux1 sera o que esta na RAM[0]
    //aux2 RAM[1]
    while(aux1 >= aux2){
        memoria->MemoriaInstrucoes[0][0] = 1;
        memoria->MemoriaInstrucoes[0][1] = 0;
        memoria->MemoriaInstrucoes[0][2] = 1;
        memoria->MemoriaInstrucoes[0][3] = 0;

        memoria->MemoriaInstrucoes[3][0] = -1;
        memoria->MemoriaInstrucoes[3][1] = -1;
        memoria->MemoriaInstrucoes[3][2] = -1;
        memoria->MemoriaInstrucoes[3][3] = -1;

        maquina(memoria);


        instrucaoAux[0] = 3;
        instrucaoAux[1] = 0; //RAM[0]
        instrucaoAux[2] = 0;
        instrucaoAux[3] = -1;

        maquinaInterpretada(instrucaoAux, memoria);
        aux1 = instrucaoAux[1];

        //aux1 sera o que esta na RAM[0]
        //aux2 RAM[1]
        cont++;
    }
    //RAM[0] = Resto
    memoria->MemoriaInstrucoes[0][0] = 2;
    memoria->MemoriaInstrucoes[0][1] = cont;
    memoria->MemoriaInstrucoes[0][2] = 3;
    memoria->MemoriaInstrucoes[0][3] = -1;
    //salva resultado na RAM[3]

    memoria->MemoriaInstrucoes[1][0] = -1;
    memoria->MemoriaInstrucoes[1][1] = -1;
    memoria->MemoriaInstrucoes[1][2] = -1;
    memoria->MemoriaInstrucoes[1][3] = -1;

    maquina(memoria);
}


void potencia(Memoria *memoria, int num1, int num2){
    int res = num1, instrucaoAux[4];
    
    if(num2 == 0){
        
        memoria->MemoriaInstrucoes[0][1] = 2;
        memoria->MemoriaInstrucoes[0][1] = 1;
        memoria->MemoriaInstrucoes[0][2] = 3;
        memoria->MemoriaInstrucoes[0][3] = -1;

        memoria->MemoriaInstrucoes[1][1] = -1;
        memoria->MemoriaInstrucoes[1][1] = -1;
        memoria->MemoriaInstrucoes[1][2] = -1;
        memoria->MemoriaInstrucoes[1][3] = -1;
        //coloca 1 como resultado
        maquina(memoria);
    }
    else if(num2 == 1){
        memoria->MemoriaInstrucoes[0][1] = 2;
        memoria->MemoriaInstrucoes[0][1] = num1;
        memoria->MemoriaInstrucoes[0][2] = 3;
        memoria->MemoriaInstrucoes[0][3] = -1;

        memoria->MemoriaInstrucoes[1][1] = -1;
        memoria->MemoriaInstrucoes[1][1] = -1;
        memoria->MemoriaInstrucoes[1][2] = -1;
        memoria->MemoriaInstrucoes[1][3] = -1;
        //coloca o proprio numero como resultado
        maquina(memoria);
    }
    else{
        for (int i = 0; i < num2-1; i++){
            multiplicacao(memoria, res, num1);
            
            instrucaoAux[0] = 3;
            instrucaoAux[1] = 0;
            instrucaoAux[2] = 3;
            instrucaoAux[1] = -1;
            maquinaInterpretada(instrucaoAux, memoria);
            res = instrucaoAux[1]; //res = resultado da multiplicacao
        }
        memoria->MemoriaInstrucoes[0][1] = 2;
        memoria->MemoriaInstrucoes[0][1] = res;
        memoria->MemoriaInstrucoes[0][2] = 3;
        memoria->MemoriaInstrucoes[0][3] = -1;
        //leva o resultado para RAM[3]
        memoria->MemoriaInstrucoes[1][0] = -1;
        memoria->MemoriaInstrucoes[1][1] = -1;
        memoria->MemoriaInstrucoes[1][2] = -1;
        memoria->MemoriaInstrucoes[1][3] = -1;

        maquina(memoria);
    }
}
void fatorial(Memoria *memoria, int num1){
    int res = num1, instrucaoAux[4];
    
    for (int i = num1-1; i > 0; i--){
        multiplicacao(memoria, res, i);
        
        instrucaoAux[0] = 3;
        instrucaoAux[1] = 0;
        instrucaoAux[2] = 3;
        instrucaoAux[3] = -1;

        maquinaInterpretada(instrucaoAux, memoria);
        res = instrucaoAux[1];
    }
    memoria->MemoriaInstrucoes[0][1] = 2;
    memoria->MemoriaInstrucoes[0][1] = res;
    memoria->MemoriaInstrucoes[0][2] = 3;
    memoria->MemoriaInstrucoes[0][3] = -1;
    //leva o resultado para RAM[3]
    memoria->MemoriaInstrucoes[1][0] = -1;
    memoria->MemoriaInstrucoes[1][1] = -1;
    memoria->MemoriaInstrucoes[1][2] = -1;
    memoria->MemoriaInstrucoes[1][3] = -1;

    maquina(memoria);
}
void areaQuadrado(Memoria *memoria, int num1){
    potencia(memoria, num1, 2);//RAM[3]
}
void areaRetangulo(Memoria *memoria, int num1, int num2){
    multiplicacao(memoria, num1, num2); //RAM[3]
}
void areaTriangulo(Memoria *memoria, int num1, int num2){
    int instrucaoAux[4], aux;
    multiplicacao(memoria, num1, num2);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux = instrucaoAux[1];
    
    divisaoEResto(memoria, aux, 2);
}
void perimetroCircunferencia(Memoria *memoria, int num1){
    multiplicacao(memoria, 6, num1);
}
void perimetroCircunferenciaDiametro(Memoria *memoria, int num1){
    int instrucaoAux[4], aux;
    perimetroCircunferencia(memoria, num1);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux = instrucaoAux[1];
    divisaoEResto(memoria, aux, 2);
}
void volumeCubo(Memoria *memoria, int num1){
    multiplicacao(memoria, num1, 3);
}
void volumePiramide(Memoria *memoria, int num1, int num2){
    int instrucaoAux[4], aux;
    multiplicacao(memoria, num1, num2);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux = instrucaoAux[1];
    divisaoEResto(memoria, aux, 3);
}
void somaQuadrados(Memoria *memoria, int num1, int num2){
    int instrucaoAux[4], aux1, aux2;
    potencia(memoria, num1, 2);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux1 = instrucaoAux[1];
    potencia(memoria, num2, 2);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux2 = instrucaoAux[1];
    funcaoSoma(memoria, aux1, aux2);
}
// void raiz(Memoria *memoria, int num1, int num2){
//     int instrucaoAux[4], aux, auxres = 0;
//     for (int i = 1; i < 31; i++){
//         potencia(memoria, i, num2);
//         instrucaoAux[0] = 3;
//         instrucaoAux[1] = 0;
//         instrucaoAux[2] = 3;
//         instrucaoAux[3] = -1;
//         //memoria->RAM[3]
//         maquinaInterpretada(instrucaoAux, memoria);
//         aux = instrucaoAux[1];
//         if(aux == num1){ //se o resultado da potencia for igual ao numero
//             memoria->MemoriaInstrucoes[0][1] = 2;
//             memoria->MemoriaInstrucoes[0][1] = i;
//             memoria->MemoriaInstrucoes[0][2] = 3;
//             memoria->MemoriaInstrucoes[0][3] = -1;
//             //salvo o numero RAM[3]
//             memoria->MemoriaInstrucoes[1][0] = -1;
//             memoria->MemoriaInstrucoes[1][1] = -1;
//             memoria->MemoriaInstrucoes[1][2] = -1;
//             memoria->MemoriaInstrucoes[1][3] = -1;
//             maquina(memoria);
//             //auxres = i;
//             break; //encerra
//         }

//     }    
// }
void raiz(Memoria *memoria, int num1, int num2){
    int instrucaoAux[4], aux, auxres = 0;
    
    for (int i = 1; i < 31; i++){
        potencia(memoria, i, num2);
        instrucaoAux[0] = 3;
        instrucaoAux[1] = 0;
        instrucaoAux[2] = 3;
        instrucaoAux[3] = -1;

        maquinaInterpretada(instrucaoAux, memoria);
        aux = instrucaoAux[1];
        if(aux == num1){ //se o resultado da potencia for igual ao numero
            auxres = i;
            break; //encerra
        }
        else{
            auxres = 0;
        }
        
    }
    if(auxres != 0){
        memoria->MemoriaInstrucoes[0][1] = 2;
        memoria->MemoriaInstrucoes[0][1] = auxres;
        memoria->MemoriaInstrucoes[0][2] = 3;
        memoria->MemoriaInstrucoes[0][3] = -1;
        //salvo o numero RAM[3]
        memoria->MemoriaInstrucoes[1][0] = -1;
        memoria->MemoriaInstrucoes[1][1] = -1;
        memoria->MemoriaInstrucoes[1][2] = -1;
        memoria->MemoriaInstrucoes[1][3] = -1;
        maquina(memoria);
    }
    else{
        memoria->MemoriaInstrucoes[0][1] = 2;
        memoria->MemoriaInstrucoes[0][1] = -1;
        memoria->MemoriaInstrucoes[0][2] = 3;
        memoria->MemoriaInstrucoes[0][3] = -1;
        //salvo o numero RAM[3]
        memoria->MemoriaInstrucoes[1][0] = -1;
        memoria->MemoriaInstrucoes[1][1] = -1;
        memoria->MemoriaInstrucoes[1][2] = -1;
        memoria->MemoriaInstrucoes[1][3] = -1;
        maquina(memoria);
    }

}


void celsiusToFahrenheit(Memoria *memoria, int num1){
    int instrucaoAux[4], aux;
    multiplicacao(memoria, num1, 9);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux = instrucaoAux[1];
    divisaoEResto(memoria, aux, 5);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux = instrucaoAux[1];
    funcaoSoma(memoria, aux, 32);
}
void fahrenheitToCelsius(Memoria *memoria, int num1){
    int instrucaoAux[4], aux;
    funcaoSubtracao(memoria, num1, 32);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux = instrucaoAux[1];

    multiplicacao(memoria, aux, 5);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux = instrucaoAux[1];

    divisaoEResto(memoria, aux, 9);
}


void anoParaMeses(Memoria *memoria, int num1){
    multiplicacao(memoria, num1, 12);
}
void anoParaDias(Memoria *memoria, int num1){
    multiplicacao(memoria, num1, 365);
}
void mesesParaDias(Memoria *memoria, int num1){
    multiplicacao(memoria, num1, 30);
}

void diaParaMinutos(Memoria *memoria, int num1){
    multiplicacao(memoria, num1, 1440);
}

void minutoParaSegundos(Memoria *memoria, int num1){
    multiplicacao(memoria, num1, 60);
}
void segundoParaMinuto(Memoria *memoria, int num1){
    divisaoEResto(memoria, num1, 60);
}

void minutoParaDia(Memoria *memoria, int num1){
    divisaoEResto(memoria, num1, 1440);
}
void diaParaMes(Memoria *memoria, int num1){
    divisaoEResto(memoria, num1, 12);
}
void diaParaAno(Memoria *memoria, int num1){
    divisaoEResto(memoria, num1, 365);
}
void mesParaAno(Memoria *memoria, int num1){
    divisaoEResto(memoria, num1, 30);
}
void diasParaTempoADM(Memoria *memoria, int num1){
    int instrucaoAux[4], aux1, aux2, aux3, aux4;
    
    divisaoEResto(memoria, num1, 365);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux1 = instrucaoAux[1]; //anos
    
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 0;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux2 = instrucaoAux[1]; //aux2 tem o resto 
    //sera usado para encontrar meses e dias
    //printf("%d\n", aux2);
    divisaoEResto(memoria, aux2, 30);
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 3;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux3 = instrucaoAux[1]; //meses é o resultado da divisao
    
    instrucaoAux[0] = 3;
    instrucaoAux[1] = 0;
    instrucaoAux[2] = 0;
    instrucaoAux[1] = -1;

    maquinaInterpretada(instrucaoAux, memoria);
    aux4 = instrucaoAux[1]; //dias é o resto da divisao
    //anos RAM[4]
    //meses RAM[5]
    //dias RAM[6]
    //printf("%d\n", aux1);printf("%d\n", aux3);printf("%d\n", aux4);
    memoria->MemoriaInstrucoes[0][1] = 2;
    memoria->MemoriaInstrucoes[0][1] = aux1;
    memoria->MemoriaInstrucoes[0][2] = 4;
    memoria->MemoriaInstrucoes[0][3] = -1;

    memoria->MemoriaInstrucoes[1][0] = 2;
    memoria->MemoriaInstrucoes[1][1] = aux3;
    memoria->MemoriaInstrucoes[1][2] = 5;
    memoria->MemoriaInstrucoes[1][3] = -1;

    memoria->MemoriaInstrucoes[2][0] = 2;
    memoria->MemoriaInstrucoes[2][1] = aux4;
    memoria->MemoriaInstrucoes[2][2] = 6;
    memoria->MemoriaInstrucoes[2][3] = -1;

    memoria->MemoriaInstrucoes[3][0] = -1;
    memoria->MemoriaInstrucoes[3][1] = -1;
    memoria->MemoriaInstrucoes[3][2] = -1;
    memoria->MemoriaInstrucoes[3][3] = -1;

    maquina(memoria);
}