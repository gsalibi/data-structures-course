typedef struct no {
	int elemento;
	struct no *prox;	
} No;

void adicionarElemento (No **lPtr);
No *inverter (No *lPtr);
int buscar (No *lPtr, int primeiro, int depoisDe);
void imprimir (No *lPtr, int primeiro, int depoisDe, int fim);
void liberar (No *lPtr);
