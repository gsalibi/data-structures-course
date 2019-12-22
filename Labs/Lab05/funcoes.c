#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

// adiciona arquivo
void touch(Arquivo **raiz, char *nome)
{
	if (*raiz == NULL)
	{
		*raiz = malloc(sizeof(Arquivo));
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->quantidade = 1;
		(*raiz)->altura = 0;
		strcpy ((*raiz)->nome, nome);
		
		return;
	}
	
	Arquivo *atual = *raiz;
	int comparacao = comparar(atual->nome, nome, 0, tamanho(nome), INTEIRO);
	
	if (comparacao == -1) // menor do que o atual
	{
		touch(&(atual->esq), nome);
	
		if (fatorBalanceamento(atual) >= 2)
		{
			if (atual->esq->esq != NULL)
			{
				rotacionarLL(raiz);
			}
			else
			{
				rotacionarLR(raiz);
			}
		}
		atual->altura = maior(alturaNO((atual)->esq), alturaNO(atual->dir)) + 1;
	}
	else if (comparacao == 1) // maior do que o atual
	{
		touch(&(atual->dir), nome);	
		if (fatorBalanceamento(atual) >= 2)
		{			
			if (atual->dir->dir != NULL)
			{
				rotacionarRR(raiz);
			}
				else
			{
				rotacionarRL(raiz);
			}
		}
		atual->altura = maior(alturaNO((atual)->esq), alturaNO(atual->dir)) + 1;
	}
	else // sao iguais
	{
		((*raiz)->quantidade)++;
	}
}

// retorna o maior elemento
int maior(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
	}
}

// retorna a altura do no com relacao aos elementos inferiores
int alturaNO(Arquivo *no)
{
    if(no == NULL)
    {
        return -1;
    }
    else
    {
		return no->altura;
	}
}

// retorna o modulo do fator de balanceamento do no
int fatorBalanceamento(Arquivo *no)
{
	return labs(alturaNO(no->esq) - alturaNO(no->dir));
}

// rotaciona no caso de os dois proximos nos estarem a esquerda
void rotacionarLL(Arquivo **A)
{
    Arquivo *B = (*A)->esq;
	
	(*A)->esq = B->dir;
	B->dir = *A;
	
	(*A)->altura = maior(alturaNO((*A)->esq), alturaNO((*A)->dir)) + 1;
	B->altura = maior(alturaNO(B->esq), (*A)->altura) + 1;
    
	*A = B;
}

// rotaciona no caso de os dois proximos nos estarem a direita
void rotacionarRR(Arquivo **A)
{
	Arquivo*B = (*A)->dir;
	
	(*A)->dir = B->esq;
	B->esq = (*A);
	
	(*A)->altura = maior(alturaNO((*A)->esq), alturaNO((*A)->dir)) + 1;
	B->altura = maior(alturaNO(B->dir), (*A)->altura) + 1;	

	*A = B;
}

// rotaciona no caso de o proximo no estar a esquerda e o seguinte a ele, a direita
void rotacionarLR(Arquivo **A)
{
    rotacionarRR(&(*A)->esq);
    rotacionarLL(A);
}

// rotaciona no caso de o proximo no estar a direita e o seguinte a ele, a esquerda
void rotacionarRL(Arquivo **A)
{
    rotacionarLL(&(*A)->dir);
    rotacionarRR(A);
}

// compara dois nomes de arquivos e retorna se o segundo é maior, menor ou igual
int comparar(char *nome1, char *nome2, int posicao, int posicaoFinal, int tipo)
{
	if (nome1[posicao] > nome2[posicao])
	{
		return -1;
	}	
	else if (nome1[posicao] < nome2[posicao])
	{
		return 1; // novo elemento eh maior
	}
	else // caracteres nesta posicao sao iguais
	{
			while (posicao <= posicaoFinal) 
			{
				if (nome1[posicao] == '\0')
				{
					return 1;
				}
				else if (tipo == INTEIRO && posicao == posicaoFinal && nome1[posicao+1] != '\0' && nome1[posicao] == nome2[posicao])
				{
						return -1;
				}
				else if (posicao == posicaoFinal && nome1[posicao] == nome2[posicao])
				{
						return 0; // os elemento sao iguais
				}
				else if (nome1[posicao] > nome2[posicao])
				{
					return -1;
				}
				else if (nome1[posicao] < nome2[posicao])
				{
					return 1;
				}
				
				posicao++;
				
			}
			return -1;
	}
}

// busca um arquivo pelo nome e retorna seu endereco
Arquivo **buscar(Arquivo **raiz, char *nome, int tamanho)
{
    if(*raiz == NULL)
    {   
       return NULL;
    }	
    
    int comparacao;
    
    if (nome[tamanho+1] == '*')
    {
		comparacao = comparar((*raiz)->nome, nome, 0, tamanho, PARTE);
	}
	else
	{
		comparacao = comparar((*raiz)->nome, nome, 0, tamanho, INTEIRO);
    }
    
    if (*raiz != NULL && comparacao == -1)
    {
		return buscar(&(*raiz)->esq, nome, tamanho);
	}
	else if (*raiz != NULL && comparacao == 1)
	{
		return buscar(&(*raiz)->dir, nome, tamanho);
	}
	else if (*raiz != NULL)
	{
		return raiz;
	}
	else
	{
		return NULL;
	}
}


// encontra todos os arquivos que devem ser removidos
void encontrarRM(Arquivo **raiz, char *nome, int tamanho)
{
    Arquivo **excluir = buscar(raiz, nome, tamanho);	

	while (excluir != NULL)
	{
		rm(raiz, (*excluir)->nome);
		
		excluir = buscar(raiz, nome, tamanho);	
	}
}

void removerCaso1 (Arquivo **raiz)
{
	Arquivo *rem = *raiz;
	
	// esq eh vazia
	if (rem->esq == NULL)
	{	
		*raiz = rem->dir;
	}
	else // direita eh vazia
	{
		*raiz = rem->esq;
	}
	
	free(rem);
}

void removerCaso2 (Arquivo *rem)
{
	Arquivo **sucessor = &(rem->dir);
	
	// procura sucessor
	while ((*sucessor)->esq != NULL)
	{
		sucessor = &((*sucessor)->esq);
	}
	
	// copia e sobrescreve rem
	strcpy(rem->nome, (*sucessor)->nome);
	rem->quantidade = (*sucessor)->quantidade;
	
	// apaga No do sucessor
	removerCaso1(sucessor);	
}


// remove arquivo com o nome correspondente
void rm(Arquivo **raiz, char *nome)
{
	int comparacao = comparar((*raiz)->nome, nome, 0, tamanho(nome), INTEIRO);
	
	if (comparacao == -1) // esta a esquerda
	{
		rm(&(*raiz)->esq, nome);
		
		if (fatorBalanceamento(*raiz) >= 2)
		{
			if (alturaNO((*raiz)->dir->esq) <= alturaNO((*raiz)->dir->dir))
			{
				rotacionarRR(raiz);
			}
			else
			{
				rotacionarRL(raiz);
			}
		}
	}	
	else if (comparacao == 1) //esta a direita
	{
		rm(&(*raiz)->dir, nome);
		
		if (fatorBalanceamento(*raiz) >= 2)
		{
			if (alturaNO((*raiz)->esq->dir) <= alturaNO((*raiz)->esq->esq))
			{
				rotacionarLL(raiz);
			}
			else
			{
				rotacionarLR(raiz);
			}
		}
	}
	else // sao iguais
	{
		if((*raiz)->esq == NULL || (*raiz)->dir == NULL)
		{
			removerCaso1(raiz);
		}
		else
		{
			removerCaso2(*raiz);			
			
			if (fatorBalanceamento(*raiz) >= 2)
			{
				if (alturaNO((*raiz)->esq->dir) <= alturaNO((*raiz)->esq->esq))
				{
					rotacionarLL(raiz);
				}
				else
				{
					rotacionarLR(raiz);
				}
			}			
		}	
		
		if ((*raiz) != NULL)
		{
			(*raiz)->altura = maior(alturaNO((*raiz)->esq), alturaNO((*raiz)->dir)) + 1;
		}	
		return;
	}
	
	(*raiz)->altura = maior(alturaNO((*raiz)->esq), alturaNO((*raiz)->dir)) + 1;
}

// retorna o tamanho da string, levando em consideracao o sinal de '*'
int tamanho (char *nome)
{
	int i;
	for (i = 0; nome[i] != '\0' && nome[i] != '*'; i++);
	
	if (nome[i-1] == '*')
	{
		return i - 2;
	}
	else
	{
		return i - 1;
	}
}

// lista todos os arquivos com o nome em questao
void ls(Arquivo *raiz, char *nome, int tamanho, int *ativador)
{
	if (raiz != NULL)
	{
		ls (raiz->esq, nome, tamanho, ativador);
			
		if (nome[0] == '*' || comparar(raiz->nome, nome, 0, tamanho, PARTE) == 0)
		{
			if (raiz->quantidade == 1)
			{
				if (nome[0] == '*' || nome[tamanho + 1] == '*' || *ativador == 1)
				{
					printf ("%s\n", raiz->nome);
					*ativador = 0;
				}
			}
			else
			{
				if (nome[0] == '*' || nome[tamanho + 1] == '*' || *ativador == 1)
				{	
					for (int i=0; i < raiz->quantidade; i++)
					{			
						printf ("%s\n", raiz->nome);
					}
					*ativador = 0;
				}				
			}
		}
		
		ls (raiz->dir, nome, tamanho, ativador);		
	}	
}

// libera memoria alocada para cada no
void liberarNO(Arquivo* no)
{
    if(no == NULL)
    {
        return;
    }
    liberarNO(no->esq);
    liberarNO(no->dir);
    free(no);
    no = NULL;
}
