#include <stdio.h>
#include <stdlib.h>

// função para perguntar ao utilizador o grau de dificuldade e obter as coordenadas.

void obterCoordenadas(int *x, int *y) {
    int nivel = 0;
    while (nivel < 1 || nivel > 3) /*um ciclo while caso o  valor introduzido pelo utilizador esteja fora dos parametro*/
    {
        printf("Escolha o nivel de dificuldade (1, 2 ou 3):\n");
        scanf("%d", &nivel);
        switch (nivel) /*Verifica a opção escolhida e atribui as coordenadas*/
            {
            case 1:     /*Facil*/
                *x = 5; 
                *y = 5;
                break;
            case 2:     /*"Normal"*/
                *x = 10;
                *y = 10;
                break;
            case 3:     /*Dificil*/
                *x = 15;
                *y = 15;
                break;
            default:
                printf("Nivel invalido! Tente novamente.\n");
                break;
            }
    }
}

// Função para criar tabuleiro com base na dificuldade.
char **criarMatriz(int x, int y) {
    char **matriz = (char **)malloc(x * sizeof(char *));
    for (int i = 0; i < x; i++) {
        matriz[i] = (char *)malloc(y * sizeof(char));
        for (int j = 0; j < y; j++) {
            matriz[i][j] = 'X';
        }
    }
    return matriz;
}
void coordenadasinicio (char**matriz, int coluna, int linha) /* Função Para Perguntar ao utilizador onde pretente começar.*/
    {
        printf("Pretende iniciar onde, 1ª Coordenada ");
        scanf("%d",&linha);
        printf("Pretende iniciar onde, 2ª Coordenada ");
        scanf("%d",&coluna);
        printf("vai comecar na Posição seguinte: \n");
        matriz[linha][coluna] = '&';
        return matriz;
    }
    void updatetabuleiro (char**matriz, int x, int y)
    {
        for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    }