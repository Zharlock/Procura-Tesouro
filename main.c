#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "library.h"
// Projeto da Disciplina Programação II (liguagem C), baseado num jogo de caça ao tesouro. Projeto elaborado por Carlos e João.

int main()
    {
        int x = 0, y = 0;
        int linha_te, coluna_te, rowplayer, clplayer, count;
        int dir;
   
        int nivel = obterCoordenadas(&x, &y);
        char **matriz = criarMatriz(x, y);
        tesourogen(&linha_te, &coluna_te, nivel);
        coordenadasinicio(&rowplayer, &clplayer);
        tabuleiro(matriz, x, y, rowplayer, clplayer, dir);

        //chama a função get_distance e calcula a distancia entre o tesouro e a posição do jogador

        int distance = get_distance(rowplayer, clplayer, linha_te, coluna_te);

        // motor do jogo

        while (distance !=0)
            {
                posicao(matriz, &dir, &rowplayer, &clplayer,linha_te,coluna_te, x , y);
                updatetabuleiro(matriz, x, y, rowplayer, clplayer, dir);
                distance = get_distance(rowplayer, clplayer, linha_te, coluna_te);
                printf("Distância até o tesouro: %d\n", distance);
                 count = count+1;
            }

        // O jogador encontrou o tesouro
        printf("Parabéns!! Chegou ao Tesouro em %d passos!! Ganho 100.000.000\n" , count);
        return 0;

    }
