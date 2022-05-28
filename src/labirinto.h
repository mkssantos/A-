#include "fila.h"
#define MAXTAM 20

typedef struct Labirinto Labirinto;
typedef struct Posicao Posicao;

struct Labirinto{
    
    Posicao **map;
    int linha;
    int coluna;

};

struct Posicao{
    char valor;
    bool verificado;
};

void Inicia(Labirinto *labirinto, int l, int c);
bool VerificarUltimo(Labirinto *labirinto, Fila *f);
bool AbrirArquivo(Labirinto *labirinto);
void ImprimirLabirinto(Labirinto *labirinto);
int PercorreLabirinto(Labirinto *labirinto, Fila *f,int linhas,int i);