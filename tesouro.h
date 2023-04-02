#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tesourogen(char **matriz, int coluna, int linha, int nivel) {
    srand(time(NULL));
    int range;
    switch (nivel) {
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
    linha = rand() % range;
    coluna = rand() % range;
    matriz[linha][coluna] = 'T';
}
