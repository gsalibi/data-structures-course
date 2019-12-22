#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Adiciona um elemento à lista
void adicionarElemento (No **lPtr) {
	No *novo;
	int elem;
	
	novo = malloc (sizeof (No));
	
	if (novo==NULL)
		exit(37);
	
	scanf ("%d", &elem);
	
	novo->elemento = elem;
	novo->prox = *lPtr;
	*lPtr = novo;
}

// Inverte a lista para que os elementos fiquem na ordem que foram adicionados
No *inverter (No *lPtr) {
	No *x, *y = lPtr, *i = NULL;
  
    while (y != NULL) { 
       x = y->prox; 
       y->prox = i; 
       i = y; 
       y = x; 
    }    
    
    return i;
}

// Busca se elemento aparece após outro elemento preestabelecido pela variável "depoisDe" e retorna 0 ou 1
int buscar (No *lPtr, int primeiro, int depoisDe) {
	No *auxiliar;
	int x=0, y=0;
	
	for (auxiliar = lPtr; auxiliar != NULL; auxiliar = auxiliar->prox) {
		if (auxiliar->elemento == depoisDe && y==0)
			y++;
			
		if ((auxiliar->elemento)==primeiro && y==1)
			x++;
	}
	
	return x;
}

// Imprime elementos da lista indo do primeiro elemento depois do elemento preestabelecido "depoisDe" até o elemento "fim"
void imprimir (No *lPtr, int primeiro, int depoisDe, int fim){
	No *auxiliar;
	int x=0, y=0;
	
	for (auxiliar = lPtr; auxiliar != NULL; auxiliar = auxiliar->prox) {
		if (auxiliar->elemento == depoisDe && x==0)
			x=1;
			
		if (x==1) {
			if (auxiliar->elemento==primeiro && y==0)
			y++;
		}
		
		if (y==1)
			printf ("%d ", auxiliar->elemento);
		
		if (auxiliar->elemento == fim && y==1)
			y++;
		
	}
	
	printf ("\n");
}

// Libera lista alocada dinamicamente
void liberar (No *lPtr) {
	No *atual, *proximo;
	
	proximo = lPtr;
	
	while (proximo != NULL) {
		atual = proximo;
		proximo = atual->prox;
		free(atual);
	}
}
