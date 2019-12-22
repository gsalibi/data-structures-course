typedef struct brinquedo {
	int n;
	// "cor" representa a quantidade de azuis e tambem se a cor e' vermelha ou azul
	int cor;
	struct brinquedo *prox;
} Brinquedo;


void empilhar (Brinquedo **p, int elem);
void desempilhar (Brinquedo **p, Brinquedo **o);
void ordenar (Brinquedo **o, int elem, int cor, Brinquedo **l);
void imprimir (Brinquedo *o);
void liberarLista (Brinquedo **l);
