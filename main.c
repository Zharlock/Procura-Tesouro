#include <stdio.h>
#include <stdlib.h>
#include "dificuldade.h"

  int main() {
    int x, y, linha, coluna;
    obterCoordenadas(&x, &y);
    char **matriz = criarMatriz(x, y);
    printf("Tabuleiro:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
   coordenadasinicio (matriz,linha, coluna);
   updatetabuleiro(matriz,x,y);
    return 0;
}