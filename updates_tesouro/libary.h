#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// devolve as coordenadas do Tessouro!

int tesourogen(int * linha_tesouro, int * coluna_tesouro, int nivel) 
{
    srand(time(NULL));
    int range;
    switch (nivel)
     {
        case 1:
            range = 5;
            break;
        case 2:
            range = 10;
            break;
        case 3:
            range = 15;
            break;
        default:
            range = 5; // dá te um default para a menor dificuldade, para caber sempre dentro da matriz
            break;
    }
    *linha_tesouro = rand() % range;
    *coluna_tesouro = rand() % range;
   
}

// função para perguntar ao utilizador o grau de dificuldade e obter as coordenadas.

int obterCoordenadas(int *x, int *y) {
    int nivel = 0;
    while (nivel < 1 || nivel > 3) {
        printf("Escolha o nivel de dificuldade (1, 2 ou 3):\n");
        scanf("%d", &nivel);
        switch (nivel) {
            case 1:
                *x = 5;
                *y = 5;
                break;
            case 2:
                *x = 10;
                *y = 10;
                break;
            case 3:
                *x = 15;
                *y = 15;
                break;
            default:
                printf("Nivel invalido! Tente novamente.\n");
                break;
        }
    }
    return nivel;
}



char **criarMatriz(int x, int y) // Função para criar tabuleiro com base na dificuldade.
    {
        char **matriz = (char **)malloc(x * sizeof(char *));
        for (int i = 0; i < x; i++) 
            {
                matriz[i] = (char *)malloc(y * sizeof(char));

        for (int j = 0; j < y; j++) 
            {
                matriz[i][j] = 'X';
            }
    }
    return matriz;
    }

int coordenadasinicio(int * linha_player, int * coluna_player) //Função Para Perguntar ao utilizador onde pretente começar.
    {
        printf("Pretende iniciar onde, 1ª Coordenada ");
            scanf("%d", linha_player);
        printf("Pretende iniciar onde, 2ª Coordenada ");
            scanf("%d", coluna_player);
        printf("vai comecar na Posição seguinte: \n"); // Temos que verificar se vale a pena incluir
    }


char **updatetabuleiro(char**matriz, int x, int y, int linha_p, int col_p) //Update da tabela
    {
        printf("\n");
        for(int i = 0; i < x; i++) 
            {
                for(int j = 0; j < y; j++) 
                    {
                        if(i == linha_p && j == col_p) 
                            {
                                printf("& ");
                            }
                        else 
                            {
                                printf("%c ", matriz[i][j]);
                            }
                    }
                printf("\n");
            }
        printf("\n");
    }

void posicao(char **matriz, char direcao, int *linha_p, int *col_p, int linha_t, int co_t, int x, int y) 
    {
        printf("Indique a direcao que pretende seguir:\n"); 
        printf("B - baixo\nC - Cima\nE - Esquerda\nD - Direita\n0 - Desistir\n");
        scanf(" %c", &direcao);
    
    while (1) 
    {
        if (direcao == 'B' && *linha_p + 1 < x)
                {
                    matriz[*linha_p][*col_p] = 'O';
                    *linha_p += 1;
                    break;
                }
            else if (direcao == 'C' && *linha_p - 1 >= 0)
                {
                    matriz[*linha_p][*col_p] = 'O';
                    *linha_p -= 1;
                    break;
                } 
            else if (direcao == 'E' && *col_p - 1 >= 0)
                {
                    matriz[*linha_p][*col_p] = 'O';
                    *col_p -= 1;
                    break;
                } 
            else if (direcao == 'D' && *col_p + 1 < y)
                {
                    matriz[*linha_p][*col_p] = 'O';
                    *col_p += 1;
                    break;
                }
            else if (direcao == '0')
                {
                    printf("Paciencia... O tesouro estava na posição (%d,%d)  e valia 1.000,00 €",linha_t, co_t);
                    exit(1);
                }
            else 
                {
                    printf("Direcao invalida. Escolha novamente:\n");
                    scanf(" %c", &direcao);
                }
    }
    matriz[*linha_p][*col_p] = '&';
}
double get_distance(int row1, int col1, int row2, int col2)  // Calcular a distância euclidiana entre duas posições
    {
        int dx = col2 - col1;
        int dy = row2 - row1;
        return (int)sqrt(dx*dx + dy*dy);
    }