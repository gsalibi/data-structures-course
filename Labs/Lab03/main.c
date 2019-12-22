#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main () {
	int tamanho, i, temp, primeiro;
	Brinquedo *pilha=NULL, *listaOrdenada=NULL;

	// Recebe o tamanho a da sequencia a ser lida
	scanf ("%d", &tamanho);
		
	// Recebe os elementos da sequencia
	for (i=0; i<tamanho; i++) {
		scanf ("%d", &temp);
		
		if (i==0) // Salva o primeiro elemento para comparar
			primeiro = -1*temp;
		// Caso o primeiro elemento seja diferente do ultimo, ha mais de um 
		//brinquedo separado sem estar dentro de outro e a lista e' invalida			
		if (i==(tamanho-1)) { 
			if (primeiro!=temp) {
				printf ("sequencia invalida ou nao pode colorir\n");
				liberarLista (&listaOrdenada); // Liberar memoria da lista ordenada
				liberarLista (&pilha); // Liberar memoria da pilha
				exit(0);		
			}		
		}
		
		if (temp<0)
			empilhar (&pilha, temp);
		else { // Caso maior do que zero, o elemento deve ser igual ao empilhado
			if (temp==pilha->n)
				desempilhar (&pilha, &listaOrdenada);
			else { // Caso diferente do empilhado, a sequencia e' invalida
				printf ("sequencia invalida ou nao pode colorir\n");
				exit(0);
			}
		}
	}
		
	// Caso sobrem elementos na pilha, a sequencia e' invalida
	if (pilha!=NULL) {	
		printf ("sequencia invalida ou nao pode colorir\n");
		liberarLista (&listaOrdenada); // Liberar memoria da lista ordenada
		liberarLista (&pilha); // Liberar memoria da pilha
		exit(0);	
	}
		
	imprimir (listaOrdenada); // Imprime saida valida
		
	liberarLista (&listaOrdenada); // Libera memoria
			
	return 0;
}
