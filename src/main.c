#include "labirinto.h"
#include "labirintoP.h"
#include "locale.h"

int main() {
    /*BFS*/
    Labirinto L;
    Fila F;
    Item I;

    /*DFS*/
    LabirintoP LP;
    Pilha P;
    ItemP IP;
    /*Global*/
    int it=0;
    int linhas=0, colunas=0,i=0;
    int op=0;
    setlocale(LC_ALL,"Portuguese");
    do{
        printf("Menu\n");
        printf("1-BFS\n2-DFS\n3-Sair\n");
        scanf("%d",&op);
            if(op == 1){
                FVazia(&F);
                InicializaItem(&I);
                
                printf("1-Euclidiano\n2-Manhattan\nOutro Número-Normal\nOpção:");
                scanf("%d",&i);

                printf("Numero de Linhas:");
                scanf("%d", &linhas);
                printf("Numero de Colunas:");
                scanf("%d", &colunas);
                
                Inicia(&L, linhas, colunas);
                AbrirArquivo(&L);
                Enfileira(&F, I);
                L.map[I.lin][I.col].verificado = true;

                printf("\n");
                ImprimirLabirinto(&L);

                it = PercorreLabirinto(&L, &F , linhas, i);

                printf("\nQuantidade de iterações: %d\n", it);
            }

            if(op == 2){
                FPVazia(&P);
                InicializaItemP(&IP);
                PUSH(&P, IP);

                printf("Número de linhas: ");
                scanf("%d", &linhas);
                printf("Número de colunas: ");
                scanf("%d", &colunas);
                
                IniciaP(&LP, linhas, colunas);
                AbrirArquivoP(&LP);
                printf("\n");

                ImprimirLabP(&LP);

                it = PercorreLabirintoP(&LP, &P);
                printf("\nQuantidade de iterações: %d\n", it);
            }
        }while(op != 3);  
    return 0;
}