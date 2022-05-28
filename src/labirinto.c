#include "labirinto.h"

void Inicia(Labirinto *labirinto, int l, int c){
    labirinto->map = malloc(l * sizeof(Posicao*));

    labirinto->coluna = c;
    labirinto->linha = l;
    
    for(int i = 0; i < l; i++) {
        labirinto->map[i] = malloc(c *sizeof(Posicao));
    }
}

bool AbrirArquivo(Labirinto *labirinto) 
{
    FILE *File;
    int i=0, j=0;
    char arquivo[MAXTAM];
    char Posicao;
    
    scanf("%c", (char *) stdin);
    printf("Digite o nome do arquivo:");
	fgets(arquivo, MAXTAM-4, stdin);
	strtok(arquivo, "\n");
    strcat(arquivo,".txt");

    File = fopen(arquivo, "r");
    if (File == NULL) {
        printf("Arquivo não Encontrado!\n");
        exit(1);
    } 
    else 
    {
        while((Posicao = (char)fgetc(File)) != EOF) {
            if(Posicao != '\n') {
                labirinto->map[i][j].valor = Posicao;
                labirinto->map[i][j].verificado = false;
                j++;
            }
            else {
                i++;
                j = 0;
            }
        }
    }
    fclose(File);
    return true;
}

bool VerificarUltimo(Labirinto *labirinto, Fila *f) {
    if(f->Ultimo->dado.lin == (labirinto->linha-1) && f->Ultimo->dado.col == (labirinto->coluna-1)){
        return true;
    }     
    return false;
}

int calculadist(Item *lc,int linhas,int i){
    int x=0,y=0;
    x = lc->lin;
    y = lc->col;
    int resultx=0;
    int resulty=0;

    resultx = (x-linhas-1);
    resulty = (y-linhas-1);

    
    if (i == 1 ){  /*Euclidiano*/
        lc->dist = sqrt(pow(resultx,2)+pow(resulty,2));
    }

    else if(i == 2){ /*Manhattan*/ 
        lc->dist = abs(resultx)+abs(resulty);
    }
    

    return lc->dist;
}


int PercorreLabirinto(Labirinto *labirinto, Fila *f , int linhas, int i) {
    bool cont = true;
    int cont2 = 1, x=0, y=0;
    int tamanho = linhas;
    Item aux, aux2;

    while (cont){

        // Imprime(f); 

        Desenfileira(f, &aux);
        x = aux.lin;
        y = aux.col;
        if((x+1) < labirinto->linha && labirinto->map[x+1][y].valor != '#' && !labirinto->map[x+1][y].verificado && cont) {
            aux2.lin = x+1;
            aux2.col = y;

            
            aux2.dist = calculadist(&aux2,tamanho,i);

            labirinto->map[aux2.lin][aux2.col].verificado = true;
            Enfileira(f, aux2);

            cont2++;

            if(VerificarUltimo(labirinto, f)){
                cont = false;
            }
                
        }
        if((y+1) < labirinto->coluna && labirinto->map[x][y+1].valor != '#' && !labirinto->map[x][y+1].verificado && cont) {
            aux2.col = y+1;
            aux2.lin = x;  
            
    
            aux2.dist = calculadist(&aux2,tamanho,i);
            

            labirinto->map[aux2.lin][aux2.col].verificado = true;
            Enfileira(f, aux2);

            cont2++;

            if(VerificarUltimo(labirinto, f))
            {
                cont = false;
            }     
        }
        if((y-1) >= 0 && labirinto->map[x][y-1].valor != '#' && !labirinto->map[x][y-1].verificado && cont) 
        {
            aux2.col = y-1;
            aux2.lin = x;

            aux2.dist = calculadist(&aux2,tamanho,i);
           

            labirinto->map[aux2.lin][aux2.col].verificado = true;
            Enfileira(f, aux2);

            cont2++;

            if(VerificarUltimo(labirinto, f)){
                cont = false;
            }
                
        }
        if((x-1) >= 0 && labirinto->map[x-1][y].valor != '#' && !labirinto->map[x-1][y].verificado && cont) 
        {
            aux2.lin = x-1;
            aux2.col = y;
            
            aux2.dist = calculadist(&aux2,tamanho,i);

            labirinto->map[aux2.lin][aux2.col].verificado = true;
            Enfileira(f, aux2);

            cont2++;
            
            if(VerificarUltimo(labirinto, f))
            {
                cont = false;
            }
        }
        if (i == 1 || i == 2)
        {
            bubblesort(f);
        }
    }
    return cont2;
}

void ImprimirLabirinto(Labirinto *labirinto) 
{   
    printf("!!!Imprimindo o labirinto!!!\n\n");

    for(int i=0; i<labirinto->linha; i++) 
    {
        printf("      ");

        for(int j=0; j<labirinto->coluna; j++) 
        {
            printf("%c ", labirinto->map[i][j].valor);
        }
        printf("\n");
    }
}
void bubblesort(Fila *f)
{
    bool swapped;
    Bloco *ptr1;
    Bloco *lptr = NULL;
  
    do
    {
        swapped = 0;
        ptr1 = f->Primeiro;

        while (ptr1->prox != lptr)
        {
            if (ptr1->dado.dist > ptr1->prox->dado.dist)
            { 
                Item temp = ptr1->dado;
				ptr1->dado = ptr1->prox->dado;
				ptr1->prox->dado = temp;
                swapped = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    }while (swapped);
}
