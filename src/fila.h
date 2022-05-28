#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct Item Item;
typedef struct Bloco Bloco;
typedef struct Fila Fila;

struct Item{
	int lin;
	int col;
	float dist;
};

struct Bloco{
	Item dado;
	Bloco *prox;
};

struct Fila{
	Bloco *Primeiro;
	Bloco *Ultimo;
};

void InicializaItem(Item *I);
void FVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void Imprime(Fila *f);
int calculadist(Item *lc, int linhas,int i);
void bubblesort(Fila *f);