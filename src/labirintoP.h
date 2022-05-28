#include "pilha.h"
#define MAXTAM 20

typedef struct LabirintoP LabirintoP;
typedef struct PosicaoP PosicaoP;


struct LabirintoP {

    PosicaoP **map;
    int linha;
    int coluna;
};

struct PosicaoP {
    char valor;

    bool botao;
    bool e;
    bool d;
    
};



void IniciaP(LabirintoP *labirinto, int linha, int coluna);
void ImprimirLabP(LabirintoP *labirinto);
int PercorreLabirintoP(LabirintoP *labirinto, Pilha *p);
bool AbrirArquivoP(LabirintoP *labirinto);
void FinalizarP(LabirintoP *labirinto);