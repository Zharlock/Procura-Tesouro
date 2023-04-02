#include <stdio.h>
#include <stdlib.h>
#include "dificuldade.h"
#include "tesouro.h"


int main() {
    int x = 0, y = 0;
    int nivel = obterCoordenadas(&x, &y);
    char **matriz = criarMatriz(x, y);
    matriz = coordenadasinicio(matriz, x, y);
    tesourogen(matriz, 0, 0, nivel); // Passa a dificuldade para o tesourogen
    updatetabuleiro(matriz, x, y);
    return 0;
}
