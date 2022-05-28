#include "fila.h"

void FVazia(Fila *f)
{
	f->Primeiro= NULL;
	f->Ultimo= NULL;
}

void Enfileira(Fila *f, Item d){
	
	Bloco *novo = (Bloco*)malloc(sizeof(Bloco));
    novo->dado = d;
    novo->prox = NULL;
    if (f->Primeiro== NULL) {
		f->Primeiro= novo;
	}
    else {
		f->Ultimo->prox = novo;
	}
	f->Ultimo= novo;
}

void InicializaItem(Item *I)
{
	I->lin = 0;
	I->col = 0;
}

void Desenfileira(Fila *f, Item *d)
{
	Bloco *aux;

	if(f->Primeiro== NULL){
		printf("FILA VAZIA!\n");
		d->lin = -1;
		d->col = -1;
		return;
	}
	
	*d = f->Primeiro->dado;
	aux = f->Primeiro;
	f->Primeiro= f->Primeiro->prox;
	
	free(aux);
	if(f->Primeiro== NULL)
	{
		f->Ultimo= NULL;
	}

}
