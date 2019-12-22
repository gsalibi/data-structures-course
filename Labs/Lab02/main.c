#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
	Lista *pastas=NULL, *MTF=NULL, *TR=NULL;
	int N, R, i, temp, custoMTF=0, custoTR=0;
	char op;	
	
	// Recebe um número N com o número de elementos da lista e um número R representando o número de requisições
	scanf ("%d %d", &N, &R);
		
	// Recebe uma linha com os N inteiros distintos duplamente ligados e adicionados ao final da lista
	for (i=0; i<N; i++) {
		scanf ("%d", &temp);
		adicionarLista (&pastas, temp);
		adicionarLista (&MTF, temp);
		adicionarLista (&TR, temp);
	}
	
	// Receber R linhas contendo a instrução e o valor e executa as operações escolhidas
	for (i=0; i<R; i++) {
		scanf (" %c %d", &op, &temp);
		switch (op) {
			case 'a':
				acessarMTF (&MTF, temp, &custoMTF);
				acessarTR (&TR, temp, &custoTR);
				break;
			case 'i':
				inserirMTF (&MTF, temp, &custoMTF);
				inserirTR (&TR, temp, &custoTR);
				break;
			case 'r':
				remover (&MTF, temp, &custoMTF);
				remover (&TR, temp, &custoTR);
				break;
		}
	}
		
	//Saída:
	// Uma linha com o custo de MTF
	printf ("%d\n", custoMTF);
	
	// Uma linha a lista final de MTF
	imprimir(MTF);
	
	// Uma linha com o custo de TR
	printf ("%d\n", custoTR);
	
	// Uma linha a lista final de TR
	imprimir(TR);
	
	
	// Libera memória
	liberarMem (pastas);
	liberarMem (MTF);
	liberarMem (TR);
	
	return 0;
}
