#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct ItemP ItemP;
typedef struct BlocoP BlocoP;
typedef struct Pilha Pilha;

struct ItemP{
	int x;
	int y;
};

struct BlocoP{
	ItemP dado;
	BlocoP *ant;
};

struct Pilha{
	BlocoP *F;
	BlocoP *T;
};

void InicializaItemP(ItemP *I);
void FPVazia(Pilha *P);
void PUSH(Pilha *P, ItemP D);
ItemP POP(Pilha *P);
void ImprimirP(Pilha *P);