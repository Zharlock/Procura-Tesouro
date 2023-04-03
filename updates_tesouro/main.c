#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <libary.h>

// Projeto da Disciplina Programação II (liguagem C), baseado num jogo de caça ao tesouro. Projeto elaborado por Carlos e João.

int main() 
    {
        int x = 0, y = 0;
        int linha_te, coluna_te, rowplayer, clplayer;
        char direcao;
    
        int nivel = obterCoordenadas(&x, &y);
        char **matriz = criarMatriz(x, y);
        tesourogen(&linha_te, &coluna_te, nivel);
        coordenadasinicio(&rowplayer, &clplayer);
        updatetabuleiro(matriz, x, y, rowplayer, clplayer);

        //chama a função get_distance e calcula a distancia entre o tesouro e a posição do jogador

        int distance = get_distance(rowplayer, clplayer, linha_te, coluna_te); 

        // motor do jogo

        while (distance !=0) 
            {
                posicao(matriz, direcao, &rowplayer, &clplayer, x , y);
                updatetabuleiro(matriz, x, y, rowplayer, clplayer);
                distance = get_distance(rowplayer, clplayer, linha_te, coluna_te);
                printf("Distância até o tesouro: %d\n", distance);
            }

        // O jogador encontrou o tesouro
        printf("Você encontrou o tesouro!\n");
        return 0;

    }