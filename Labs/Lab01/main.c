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
	
	ultimo = lista->elemento; // �ltimo elemento da lista original
	lista = inverter(lista); // Inverter lista lida para ficar na ordem de entrada
	primeiro = lista->elemento;// Primeiro elemento da lista original
	
	//Sa�da:
	// Imprimir uma linha com os valores originais da lista
	printf ("original ");
	imprimir (lista, primeiro, primeiro, ultimo);
	
	// Imprimir uma linha com os valores m, n e p
	printf ("m=%d, n=%d, p=%d\n", m, n, p);
	
	// a) Imprimir uma lista que comece na primeira ocorr�ncia de m e termine na primeira ocorrencia de n depois de m 
	n1 = n;
	if (buscar(lista, m, primeiro)==0) // Se na primeira lista n�o for encontrado m, ent�o m = primeiro n�mero da lista
		m = primeiro;
	
	if (buscar(lista, n, m)==0) // Se na primeira lista n�o for encontrado n, ent�o n = p
		n1 = p;
				
	if (buscar(lista, p, m)==0) // Se na primeira lista n�o for encontrado p, ent�o p = �ltimo n�mero da lista
		p = ultimo;
	
	printf ("primeira ");
	imprimir (lista, m, primeiro, n1);
		
	// b) Imprimir uma lista  que comece na primeira ocorr�ncia de n depois de m e termine na primeira ocorr�ncia de p depois de n
	n2 = n;
	if ((buscar (lista, n2, m))==0) // Se na segunda lista n�o for encontrado n, ent�o n = m da primeira lista
		n2 = m;
	
	if ((buscar (lista, p, n2))==0) // Se na segunda lista n�o for encontrado p, ent�o p = �ltimo n�mero da lista
		p=ultimo;
	
	printf ("segunda ");
	imprimir (lista, n2, m, p);
	
	// c) Imprimir uma lista que comece na primeira ocorrencia de p depois de n na lista original e termine no �ltimo n�mero da lista original
	printf ("terceira ");
	if (buscar(lista, p, n2)==0) // Se na terceira lista n�o for encontrado p, ent�o p = n da segunda lista
		p = n2;
		
	if (p==ultimo) // Caso p seja igual ao �ltimo elemento da lista, ent�o a terceira come�ar� no mesmo lugar da segunda
		imprimir (lista, n2, m, ultimo);
	else // Se n�o, a lista come�a depois do n da segunda lista	
		imprimir (lista, p, n2, ultimo);
	
	liberar(lista); // Liberar mem�ria alocada para a lista
	
	return 0;
}
