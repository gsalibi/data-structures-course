#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Adiciona elementos em lista duplamente ligada
void adicionarLista (Lista **l, int n) {
	Lista *novo = malloc (sizeof (Lista));
	if (novo==NULL) 
		exit (1); // Sair do programa em caso de indisponibilidade de memória
	
	novo->elem = n;
	novo->prox = NULL;
	
	if (*l==NULL) {
		*l = novo;
		novo->ant = NULL;
	} else {
		Lista *aux = *l;
		
		while (aux->prox!=NULL)
			aux = aux->prox;
		
		novo->ant = aux;
		aux->prox = novo;
	}
}

// Acessa item em MTF e, após o acesso, move o item para o início da lista
void acessarMTF (Lista **l, int n, int *custo) {
	Lista *atual=*l;
	
	atual->ant=NULL;
	
	while (atual->prox!=NULL && atual->elem!=n) {
		atual = atual->prox;
		(*custo)++; // Atualiza o custo
	}
	(*custo)++; // Atualiza o custo
	
	if (atual->ant!=NULL) { // Move item para o ínicio
		if (atual->prox!=NULL)
			atual->prox->ant = atual->ant;
		atual->ant->prox = atual->prox;
		atual->prox = *l;
		atual->ant = NULL;
		(*l)->ant = atual;
		*l = atual;
	}
}

// Acessa item em TR e, após o acesso, o transpõe com o item imediatamente anterior na lista
void acessarTR (Lista **l, int n, int *custo) {
	Lista *atual=*l;
	
	while (atual->prox!=NULL && atual->elem!=n) {
		atual = atual->prox;
		(*custo)++; // Atualiza o custo
	}
	(*custo)++; // Atualiza o custo
	
	if (atual->ant!=NULL) { // Transpõe item
		if (atual->prox==NULL && atual->elem!=n)
			return;

		Lista *anterior2 = atual->ant->ant;		
		if (atual->prox!=NULL)
			atual->prox->ant = atual->ant;
		atual->ant->prox = atual->prox;
		atual->ant->ant = atual;
		atual->prox = atual->ant;
		atual->ant = anterior2;
		if (anterior2==NULL) {
			*l = atual;
			return;
		}
		anterior2->prox = atual;
	}
	
}

// Insere item em MTF, no final da lista
void inserirMTF (Lista **l, int n, int *custo) {
	Lista *novo = malloc (sizeof (Lista));
	
	if (novo==NULL)
		exit (1);
		
	novo->elem = n;
	novo->prox = NULL;
	
	if (*l==NULL) {
		*l = novo;
		(*custo)++; // Atualiza o custo		
	} else {
		Lista *atual=*l;
		
		while (atual->prox!=NULL) {
			atual = atual->prox;
			(*custo)++; // Atualiza o custo
		}
		(*custo) += 2; // Atualiza o custo
		
		atual->prox = novo;
		novo->ant = atual;
	}
}

// Insere item em TR e, após ser inserido, ele é transposto com o item imediatamente anterior da lista
void inserirTR (Lista **l, int n, int *custo) {
	Lista *novo = malloc (sizeof (Lista));
	
	if(novo==NULL)
		exit (1); // Sair do programa em caso de indisponibilidade de memória
		
	novo->elem = n;
	novo->prox = NULL;
	
	if (*l==NULL) {
		*l=novo;
		(*custo)++; // Atualiza o custo
	} else {
		Lista *atual=*l;
		
		while (atual->prox!=NULL) {
			(*custo)++; // Atualiza o custo
			atual = atual->prox;
		}
		(*custo) += 2; // Atualiza o custo
		
		if (atual->ant==NULL) {
			novo->prox = atual;
			atual->ant = novo;
			novo->ant = NULL;
			*l = novo;
		} else { // Transpõe item
			atual->ant->prox = novo;
			novo->ant = atual->ant;
			atual->ant = novo;
			novo->prox = atual;
		}
	}
}

// Remove item da lista
void remover(Lista **l, int n, int *custo) {
	Lista *aux=*l;
	
	while (aux->prox!=NULL && aux->elem!=n) {
		aux=aux->prox;
		(*custo)++; // Atualiza o custo
	}
	(*custo)++; // Atualiza o custo
	
	if (aux->prox!=NULL && aux->elem!=n) // Item não encontrado
		return;
	
	if (aux==*l)
		*l = aux->prox;
	else
		aux->ant->prox = aux->prox;
	
	if (aux->prox != NULL)
		aux->prox->ant = aux->ant;
			
	free(aux); // Libera memória alocada para o elemento
}

// Imprime todos os itens da lista
void imprimir (Lista *l) {
	Lista *aux;
	
	for (aux=l; aux!=NULL; aux=aux->prox)
		printf ("%d ", aux->elem);
	printf ("\n");	
}

// Libera toda a memória alocada para a lista
void liberarMem (Lista *l) {
	Lista *atual=l, *proximo;
	
	while (atual!=NULL) {
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	l=NULL;
}
