#define LINHA 0 // define LINHA como o numero 0 para ser usado na pilha
#define CARACTERE 1 // define CARACTERE como o numero 1 para ser usado na pilha

char** criarTabuleiro (int n);
char** criarPilha (int n);
int existeSol (char** tabuleiro, int tamanho, char** rainha, int atualCol);
int ehValido (char** tabuleiro, int tamanho, char** rainha, int atualCol);
char** liberarMemoria (char** matriz, int colunas);
