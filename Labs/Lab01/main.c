#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main () {
	No *lista=NULL;
	int m, n, n1, n2, p, primeiro, ultimo;
	
	char op;
	
	// Receber uma linha com os elementos da lista
	do {
		adicionarElemento(&lista);
		scanf ("%c", &op);
	} while (op!='\n' && op!='\r');
	
	// Receber uma linha com os valores de m, n e p 
	scanf ("%d %d %d", &m, &n, &p);
	
	ultimo = lista->elemento; // Último elemento da lista original
	lista = inverter(lista); // Inverter lista lida para ficar na ordem de entrada
	primeiro = lista->elemento;// Primeiro elemento da lista original
	
	//Saída:
	// Imprimir uma linha com os valores originais da lista
	printf ("original ");
	imprimir (lista, primeiro, primeiro, ultimo);
	
	// Imprimir uma linha com os valores m, n e p
	printf ("m=%d, n=%d, p=%d\n", m, n, p);
	
	// a) Imprimir uma lista que comece na primeira ocorrência de m e termine na primeira ocorrencia de n depois de m 
	n1 = n;
	if (buscar(lista, m, primeiro)==0) // Se na primeira lista não for encontrado m, então m = primeiro número da lista
		m = primeiro;
	
	if (buscar(lista, n, m)==0) // Se na primeira lista não for encontrado n, então n = p
		n1 = p;
				
	if (buscar(lista, p, m)==0) // Se na primeira lista não for encontrado p, então p = último número da lista
		p = ultimo;
	
	printf ("primeira ");
	imprimir (lista, m, primeiro, n1);
		
	// b) Imprimir uma lista  que comece na primeira ocorrência de n depois de m e termine na primeira ocorrência de p depois de n
	n2 = n;
	if ((buscar (lista, n2, m))==0) // Se na segunda lista não for encontrado n, então n = m da primeira lista
		n2 = m;
	
	if ((buscar (lista, p, n2))==0) // Se na segunda lista não for encontrado p, então p = último número da lista
		p=ultimo;
	
	printf ("segunda ");
	imprimir (lista, n2, m, p);
	
	// c) Imprimir uma lista que comece na primeira ocorrencia de p depois de n na lista original e termine no último número da lista original
	printf ("terceira ");
	if (buscar(lista, p, n2)==0) // Se na terceira lista não for encontrado p, então p = n da segunda lista
		p = n2;
		
	if (p==ultimo) // Caso p seja igual ao último elemento da lista, então a terceira começará no mesmo lugar da segunda
		imprimir (lista, n2, m, ultimo);
	else // Se não, a lista começa depois do n da segunda lista	
		imprimir (lista, p, n2, ultimo);
	
	liberar(lista); // Liberar memória alocada para a lista
	
	return 0;
}
