#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// cria tabuleiro para receber os caracteres que serao usados na validacao
char** criarTabuleiro (int n) {
	char** tabuleiro = malloc(n * sizeof(char*)); 
	
	if (tabuleiro == NULL)
		exit(1); // aborta em caso de falta de memoria
	
	for (int i = 0; i < n; i++) {
		tabuleiro[i] = malloc(n * sizeof(char));
		if (tabuleiro == NULL)
			exit(1); // aborta em caso de falta de memoria
	}
	
	return tabuleiro;
}

// cria pilha para salvar os dados das rainhas
char** criarPilha (int n) {
	char** pilha = malloc(n * sizeof(char*));
	int i, j; 

	if (pilha == NULL)
		exit(1); // aborta em caso de falta de memoria
	
	for (i = 0; i < n; i++) {
		pilha[i] = malloc(2 * sizeof(char));
		if (pilha == NULL)
			exit(1); // aborta em caso de falta de memoria
	}
	
	// inicializa pilha com "-1"
	for (i = 0; i < n; i++)
		for (j = 0; j < 2; j++)
			pilha[i][j] = -1;
	
	return pilha;
}

// verifica se existe solucao no tabuleiro dado
int existeSol (char** tabuleiro, int tamanho, char** rainha, int atualCol) {
	if (atualCol > tamanho) // ja validou todas as colunas
		return 1; // existe solucao	
	else if (atualCol < 0) // nao foi possivel validar todas as colunas
		return 0; //nao existe solucao
	else {
		if (rainha[atualCol][LINHA] > tamanho) // linha ja passou pela coluna inteira 
			rainha[atualCol][LINHA] = -1; // comeca da primeira linha novamente
		
		if (rainha[atualCol][LINHA] == tamanho) { // ultimo elemento da linha
			rainha[atualCol][LINHA]++; 
			return existeSol(tabuleiro, tamanho, rainha, atualCol-1); // volta para a coluna anterior
		} else {
			rainha[atualCol][LINHA]++; //aumenta 1 na linha
			rainha[atualCol][CARACTERE] = tabuleiro[(int)rainha[atualCol][LINHA]][atualCol]; // copia caractere
			
			if (ehValido(tabuleiro, tamanho, rainha, atualCol)) // caso seja valido ate esta coluna
				return existeSol(tabuleiro, tamanho, rainha, atualCol + 1); // vai para proxima coluna
			else // caso nao seja valido
				return existeSol(tabuleiro, tamanho, rainha, atualCol); // vai para a proxima linha
		}
	}
}

// verifica se o elemento e' valido em determinada posicao
int ehValido (char** tabuleiro, int tamanho, char** rainha, int atualCol)
{	
	int i;
		
	// verifica linhas
	for (i = 0; i < atualCol; i++)
		if (rainha[atualCol][LINHA] == rainha[i][LINHA])
			return 0; // caso esteja na mesma linha que outra rainha
	
	// verifica caractere (nao pode haver mais de uma rainha com o mesmo)
	for (i = 0; i < atualCol; i++)
		if (rainha[atualCol][CARACTERE] == rainha[i][CARACTERE])
			return 0; // caso posua caractere igual ao de outra
	
	// verificar diagonal
	int linha = rainha[atualCol][LINHA] - 1;
	
	if (linha >= 0) {
		for (i = atualCol - 1; i >= 0; i--) {
			if (rainha[i][LINHA] == linha)
				return 0; // caso haja outra rainha na mesma diagonal
			
			linha--;
			
			if (linha < 0)
				break; // caso nao haja mais linhas a serem verificadas
		}
	}
	
	// verificar diagonal no outro sentido
	linha = rainha[atualCol][LINHA] + 1;
	if (linha <= tamanho) {
		for (i = atualCol - 1; i >= 0; i--) {
			if (rainha[i][LINHA] == linha)
				return 0; // caso haja outra rainha na mesma diagonal
			
			linha++;
			
			if (linha > tamanho)
				break; // caso nao haja mais linhas a serem verificadas
		}	
	}
	
	// caso tenha passado por todas as verificacoes
	return 1;
}

// libera a memoria alocada dinamicamente
char** liberarMemoria (char** matriz, int colunas) {	
	for (int i = 0; i < colunas; i++)
		free (matriz[i]); // libera colunas

	free(matriz); // libera linhas
	
	return NULL;
}
