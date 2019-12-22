#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Empilha elementos negativos como positivos
void empilhar (Brinquedo **p, int elem) {
	Brinquedo *novo = malloc (sizeof (Brinquedo));
	
	if (novo==NULL) // Sai do programa caso nao haja memoria
		exit (1); 
	
	novo->n = (-1*elem); // Salva o elemento como positivo
	novo->cor = 0; // Zera a quantidade de brinquedos azuis dentro deste
	novo->prox = *p;
	*p = novo;
}

// Desempilha o primeiro elemento
void desempilhar (Brinquedo **p, Brinquedo **o) {
	Brinquedo *aux=*p;
	int cor=2; // '2' Representa a cor vermelha e '1' a azul
	
	*p = (*p)->prox;
	
	// Caso a soma da cor com o numero do brinquedo seja par
	if ((aux->cor + aux->n)%2==0) {
		cor--; // A cor sera 1, representando o azul
		
		if (*p!=NULL) // Caso o proximo brinquedo exista
			((*p)->cor)++; // Aumenta em 1 a quantidade de brinquedos azuis
	}
	
	ordenar (o, aux->n, cor, p); // Inclui o elemento na lista ordenada
	
	free(aux); // Libera memoria utilizda pelo elemento desempilhado
	aux=NULL;
}

// Ordena em uma segunda lista os elementos a serem impressos juntamente com suas respectivas cores
void ordenar (Brinquedo **o, int elem, int cor, Brinquedo **l) {
	Brinquedo *novo = malloc (sizeof (Brinquedo));
	
	if (novo==NULL)
		exit (1); // Sai do programa em caso de falta de memoria
		
	novo->n = elem;
	novo->cor = cor;
	
	// Caso seja o primeiro elemento da lista
	if (*o==NULL) { 
		novo->prox = NULL;
		*o = novo;
		return;
	} 
	
	// Caso nao seja o primeiro elemento da lista
	Brinquedo *atual=*o, *anterior=NULL;
	
	while (atual!=NULL && atual->n <= elem) {
		anterior = atual;
		atual = atual->prox;
	}
	
	if (anterior==NULL) {
		novo->prox = *o;
		*o = novo;
	} else if (anterior->n==elem) {
			// Caso existam elementos iguais com cores diferentes e' invalida
			if (anterior->cor!=cor) { 
				printf ("sequencia invalida ou nao pode colorir\n");
				liberarLista (o);  // Liberar memoria da lista ordenada
				liberarLista (l); // Liberar memoria da pilha
				exit(0);
			} 		
	} else {
		novo->prox = anterior->prox;
		anterior->prox = novo;		
	}
}

// Imprime a lista de elementos ja ordenados e suas respectivas cores
void imprimir (Brinquedo *o) {
	Brinquedo *aux;
	
	printf ("sequencia valida pode ser colorida\n");
	
	for (aux=o; aux!=NULL; aux = aux->prox) {
		printf ("%d: ", aux->n);
		if (aux->cor==2)
			printf ("vermelho\n");
		else
			printf ("azul\n");
	}
}

// Libera a memoria alocada para a lista
void liberarLista (Brinquedo **l) {
	Brinquedo *atual, *proximo=*l;
	
	while (proximo != NULL) {
		atual = proximo;
		proximo = atual->prox;
		free(atual);
	}
	
	*l = NULL;
}
