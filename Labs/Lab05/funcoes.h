#define INTEIRO 1
#define PARTE 2

typedef struct arquivo
{
	char nome[21];
	int quantidade; // arquivos repetidos
	int altura; // fator de balanceamento
	struct arquivo *esq;
	struct arquivo *dir;
}
Arquivo;

void touch(Arquivo **raiz, char *nome);
void encontrarRM(Arquivo **raiz, char *nome, int tamanho);
void rm(Arquivo **raiz, char *nome);
void ls(Arquivo *raiz, char *nome, int tamanho, int *ativador);
int comparar(char *nome1, char *nome2, int posicao, int posicaoFinal, int tipo);
Arquivo **buscar(Arquivo **raiz, char *nome, int tamanho);
int tamanho (char *nome);
int alturaNO(Arquivo *no);
int maior(int x, int y);
int fatorBalanceamento(Arquivo *no);
void rotacionarLL(Arquivo **A);
void rotacionarRR(Arquivo **A);
void rotacionarRL(Arquivo **A);
void rotacionarLR(Arquivo **A);
void liberarNO(Arquivo* no);

