/*
 *	Possuo algumas duvidas com relacao a estilizacao do codigo:
 *	Eu procuro organiza-lo de forma bem compacta, pois, para mim, 
 * desta forma a compreensao fica mais facil.
 * Porem, no curso de Harvard disponibilizado online, eles praticamente 
 * impoe um estilo rigido a ser seguido (https://manual.cs50.net/style/).
 *	O manual diz, por exemplo, que é incorreto fazer "if (comparacao){", 
 * sendo a forma "correta" colocar a chave na linha de baixo. Também 
 * considera ser errado declarar ponteiros na forma "int *p;", sendo 
 * recomendado apenas "int* p", dentre outras inúmeras peculiaridades que
 * acabam por tornar o codigo muito maior.
 *	Ate que ponto devo seguir essas recomendacoes? O quao utilizadas 
 * e importantes elas realmente sao? 
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void) 
{
	int N; // numero de elementos e tamanho da matriz
	scanf("%d", &N); // recebe uma linha com o valor de N
	
	// cria tabuleiro
	char** tabuleiro = criarTabuleiro(N);
	
	// cria pilha de rainhas
	char** rainha = criarPilha(N);
		
	// recebe N linhas com N elementos cada representando o tabuleiro completo
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf (" %c", &tabuleiro[i][j]);

	// imprime saida dizendo se existe ou nao solucao
	if (existeSol(tabuleiro, N-1, rainha, 0))
		printf ("Tem solucao.\n");
	else
		printf ("Sem solucao.\n");
		
	// libera memoria
	tabuleiro = liberarMemoria(tabuleiro, N);
	rainha = liberarMemoria(rainha, N);
	

	return 0;
}
