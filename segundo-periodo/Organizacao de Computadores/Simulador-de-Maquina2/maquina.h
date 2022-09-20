#ifndef maquina_h
#define maquina_h

#include <stdio.h>
#include <stdlib.h>

#include "instrucoes.h"
#include "endereco.h"
#include "blocodememoria.h"
#include "mmu.h"

void maquina(blocoMemoria **cache1, blocoMemoria **cache2, blocoMemoria **cache3, blocoMemoria **RAM);

#endif