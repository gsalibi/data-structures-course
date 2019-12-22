/*	Infelizmente nao tive tempo suficiente para concluir o LAB de forma bem feita e
 * nem mesmo de comenta-lo adequadamente.
 * Isso aconteceu devido a incongruência do exercicio em relacao a proposta (ser
 * um exercicio semanal complementar a muitas outras atividades, e, portanto, 
 * nao tão extenso); além disso, houve prova de MC202 durante a semana, onde o 
 * conteudo do LAB nem foi cobrado.
 * Aliado a isso, somente descobri a existencia dos casos de teste poucos minutos antes
 * do tempo se esgotar e sem mais submissoes disponiveis.
 * Fui a duas monitorias durante a semana e mandei e-mail ao PED, nada disso resolveu....
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(void)
{
	char comando[6], nomeArq[21];
	Arquivo *diretorios=NULL;
	
	while (scanf(" %s", comando) != EOF)
	{
		scanf(" %s", nomeArq); // recebe nome do arquivo
		
		if (strcmp(comando, "touch") == 0) // comando touch
		{
			touch(&diretorios, nomeArq); // cria arquivo com o nome correspondente
		}
		else if (strcmp(comando, "rm") == 0) // comando rm
		{
			// caso seja '*', remove todos os arquivos
			if (nomeArq[0] == '*' && diretorios != NULL)
			{
				liberarNO(diretorios);
				diretorios = NULL;
			}
			// verifica se o arquivo existe
			else if (buscar(&diretorios, nomeArq, tamanho(nomeArq)) != NULL)
			{
				encontrarRM(&diretorios, nomeArq, tamanho(nomeArq));
			}
			else // arquivo nao encontrado
			{
				printf ("nao existem arquivos com essa expressao\n");
			}
		}
		else // comando ls
		{
			int temp = 1;
			if (nomeArq[0] == '*' && diretorios != NULL)
			{			
				ls(diretorios, nomeArq, tamanho(nomeArq), &temp);
			}
			else if (buscar(&diretorios, nomeArq, tamanho(nomeArq)) != NULL)
			{
				ls(diretorios, nomeArq, tamanho(nomeArq), &temp);
			}
			else
			{
				printf ("nao existem arquivos com essa expressao\n");
			}
		}
	}
	
	// libera memoria
	liberarNO(diretorios);	
	diretorios = NULL;

	return 0;
}
