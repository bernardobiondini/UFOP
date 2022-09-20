# ifndef funcoes_h
# define funcoes_h

typedef struct memoria Memoria;

Memoria* alocaMemoria();
void Free(Memoria **memoria);
void montarRam(Memoria *memoria);
void montarInstrucoes(Memoria *memoria);
void maquina(Memoria *memoria);
void maquinaInterpretada(int *umaInstrucao, Memoria *memoria);
int *retornaRAM(Memoria *memoria);

void funcaoSoma(Memoria *memoria, int num1, int num2);
void funcaoSubtracao(Memoria *memoria, int num1, int num2);
void multiplicacao(Memoria *memoria, int num1, int num2);
void divisaoEResto(Memoria *memoria, int num1, int num2);

void potencia(Memoria *memoria, int num1, int num2);
void fatorial(Memoria *memoria, int num1);

void areaQuadrado(Memoria *memoria, int num1);
void areaRetangulo(Memoria *memoria, int num1, int num2);
void perimetroCircunferencia(Memoria *memoria, int num1);
void perimetroCircunferenciaDiametro(Memoria *memoria, int num1);
void volumeCubo(Memoria *memoria, int num1);
void volumePiramide(Memoria *memoria, int num1, int num2);
void somaQuadrados(Memoria *memoria, int num1, int num2);
void raiz(Memoria *memoria, int num1, int num2);

void celsiusToFahrenheit(Memoria *memoria, int num1);
void fahrenheitToCelsius(Memoria *memoria, int num1);

void anoParaMeses(Memoria *memoria, int num1);
void anoParaDias(Memoria *memoria, int num1);
void mesesParaDias(Memoria *memoria, int num1);
void diaParaMinutos(Memoria *memoria, int num1);
void minutoParaSegundos(Memoria *memoria, int num1);
void segundoParaMinuto(Memoria *memoria, int num1);
void minutoParaDia(Memoria *memoria, int num1);
void diaParaMes(Memoria *memoria, int num1);
void diaParaAno(Memoria *memoria, int num1);
void mesParaAno(Memoria *memoria, int num1);
void diasParaTempoADM(Memoria *memoria, int num1);

# endif