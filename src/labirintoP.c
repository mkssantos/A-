#include "labirintoP.h"

void IniciaP(LabirintoP *labirinto, int linha, int coluna)
{
    labirinto->coluna = coluna;
    labirinto->linha = linha;
    labirinto->map = malloc(linha * sizeof(PosicaoP*));

    for(int i=0; i<linha; i++) 
    {
        labirinto->map[i] = malloc(coluna *sizeof(PosicaoP));
    }

}

void FinalizarP(LabirintoP *labirinto)
{
    for(int i=0; i<labirinto->linha; i++)
    {
        free(labirinto->map[i]);
    }
    free(labirinto->map);
}

void ImprimirLabP(LabirintoP *labirinto) 
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



bool AbrirArquivoP(LabirintoP *labirinto)
{
    FILE *file;
    int i=0, j=0;
    char arquivo[MAXTAM];
    char PosicaoP;
    

    scanf("%c", (char *) stdin);
    printf("Digite o nome do arquivo:");
	fgets(arquivo, MAXTAM-4, stdin);
	strtok(arquivo, "\n");
    strcat(arquivo,".txt");

    file = fopen(arquivo, "r");
    if (file == NULL)
    {
        printf("Arquivo não Encontrado!\n");
        exit(1);
    } 
    else 
    {
        while((PosicaoP = (char)fgetc(file)) != EOF) 
        {
            
            if(PosicaoP == '\n')
            {
                j=0;
                i++;
            }
            else
            {
                labirinto->map[i][j].valor = PosicaoP;
                labirinto->map[i][j].e = false;
                labirinto->map[i][j].d = false;
                labirinto->map[i][j].botao = false;
                j++;
            }
        }
    }
    fclose(file);
    return true;
}

int PercorreLabirintoP(LabirintoP *labirinto, Pilha *p)
{
    bool cont = true;
    ItemP aux, aux2;
    int x, y, cont2 = 1;

    while (cont)
    {
        aux = POP(p);
        
        x = aux.x;
        y = aux.y;

        if(x == (labirinto->linha - 1) && y == (labirinto->coluna - 1)) 
        {
            cont = false;
        }
         
        else
        {
            if((x+1) < labirinto->linha && labirinto->map[x+1][y].valor != '#' && ! labirinto->map[x][y].botao) 
            {
                labirinto->map[x][y].botao = true;
               
                aux2.x = x;
                aux2.y = y;

                PUSH(p, aux2);

                if((x+1) < labirinto->linha && labirinto->map[x+1][y].valor != '#'){
                    aux2.x = x+1;
                    aux2.y = y;
                    
                    PUSH(p, aux2);
                    cont2++;
                }
            } 
            else if((y+1) < labirinto->coluna && labirinto->map[x][y+1].valor != '#' && !labirinto->map[x][y].d) 
            {
                labirinto->map[x][y].d = true;
               
                aux2.x = x;
                aux2.y = y;

                PUSH(p, aux);

                if((y+1) < labirinto->coluna && labirinto->map[x][y+1].valor != '#') 
                {
                    aux2.x = x;
                    aux2.y = y+1;

                    PUSH(p, aux2);
                    cont2++;
                }
            } 
            else if((y-1) > 0 && labirinto->map[x][y-1].valor != '#' && !labirinto->map[x][y].e) 
            {
                labirinto->map[x][y].e = true;
                
                aux2.x = x;
                aux2.y = y;

                PUSH(p, aux);

                if((y-1) > 0 && labirinto->map[x][y-1].valor != '#')
                {
                    aux2.x = x;
                    aux2.y = y-1;

                    PUSH(p, aux2);
                    cont2++;
                }
            } 
            else
            {   
                labirinto->map[x][y].d = true;
                labirinto->map[x][y].e = true; 
                labirinto->map[x][y].botao = true;
                  
            }
        }
    }
    return cont2;
}