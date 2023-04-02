#include <stdio.h>
#include <stdlib.h>

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
//Função Para Perguntar ao utilizador onde pretente começar.
char **coordenadasinicio(char **matriz, int coluna, int linha) {

    printf("Pretende iniciar onde, 1ª Coordenada ");
    scanf("%d", &linha);
    printf("Pretende iniciar onde, 2ª Coordenada ");
    scanf("%d", &coluna);
    printf("vai comecar na Posição seguinte: \n");
    matriz[linha][coluna] = '&';
    return matriz;
}
//Update da tabela
void updatetabuleiro (char**matriz, int x, int y){

        for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}