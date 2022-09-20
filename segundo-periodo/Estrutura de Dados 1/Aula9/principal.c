#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m;
	TipoCaixa *heap;

	scanf("%d %d", &n, &m);

	heap = alocaVetor(heap, n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &heap[i].v);
		heap[i].id = i+1;
		heap[i].tempoCompra = 0;
	}
	
	//criar a fila de prioridades
	//a principio, cada caixa esta disponivel no tempo zero
	Heap_Constroi(heap, n);

	int produtos, tempo = 0;
	
	while (m--) {
		scanf("%d", &produtos);
		
		heap[0].tempoCompra += heap[0].v * produtos;

		if(heap[0].tempoCompra > tempo) tempo = heap[0].tempoCompra;
		
		Heap_Constroi(heap, n);
	}

	heap = desalocaVetor(heap);
	printf("%d\n", tempo);

	return 0;
}
