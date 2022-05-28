#include "pilha.h"

void FPVazia(Pilha *P) 
{
	P->T = (BlocoP*)malloc(sizeof(BlocoP));
	P->T->ant = NULL;
	P->F = P->T;
}

void InicializaItemP(ItemP *I)
{
	I->x = 0;
	I->y = 0;
}


ItemP POP(Pilha *P) 
{
	BlocoP *tmp;
	ItemP aux;
	
	if (P->T == P->F) {
		printf("PILHA VAZIA!");
		aux.x = -1;
		aux.y = -1;
	} else {
		tmp = P->T; 
		aux = P->T->dado;
		P->T = P->T->ant;
		free(tmp);
	}

	return aux;
};

void PUSH(Pilha *P, ItemP D) 
{
	BlocoP *aux = (BlocoP*)malloc(sizeof(BlocoP));;
	aux->dado = D;
	aux->ant = P->T;
	P->T = aux;
};


