# ifndef fib_h
# define fib_h

typedef struct{
  int i;
  long long resultado;
  long long chamadas;
} TADfib;

TADfib* alocaTADf (int n, TADfib *f);
long long fibonacci(int i, TADfib *f);
void desaloca(TADfib *f);

# endif
