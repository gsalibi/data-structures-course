typedef struct lista {
	int elem;
	struct lista *prox;
	struct lista *ant;
} Lista;


void adicionarLista (Lista **lPtr, int n);
void acessarMTF (Lista **lPtr, int n, int *custo);
void acessarTR (Lista **lPtr, int n, int *custo);
void inserirMTF (Lista **lPtr, int n, int *custo);
void inserirTR (Lista **lPtr, int n, int *custo);
void remover (Lista **lPtr, int n, int *custo);
void imprimir (Lista *lPtr);
void liberarMem (Lista *lPtr);
