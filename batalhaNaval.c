#include <stdio.h>

#define TAM 10
#define NAVIO_DIAGONAL 7
#define NAVIO_HORIZONTAL 4
#define NAVIO_VERTICAL 3
#define SIMBOLO_DIAGONAL '3'
#define SIMBOLO_HORIZONTAL '3'
#define SIMBOLO_VERTICAL '3'
#define SIMBOLO_AGUA '.'

int main() {
    int tabuleiro[TAM][TAM] = {0};
    char letraslinha[TAM] = {'A','B','C','D','E','F','G','H','I','J'}; 
    int i, j; 
    // diagonal principal (3 partes)
    for(i = 0; i < 3; i++) {
        tabuleiro[i][i] = NAVIO_DIAGONAL;
    }

    // diagonal secundária (3 partes)
    for(i = 2; i < 5; i++) {
        tabuleiro[i][TAM - 1 - i] = NAVIO_DIAGONAL;
    }

    // navio horizontal 
    for (j = 1; j < 4; j++) {
        tabuleiro[5][j] = NAVIO_HORIZONTAL;
    }

    // navio vertical
    for(i = 7; i < 10; i++) {
        tabuleiro[i][5] = NAVIO_VERTICAL;
    }

    // cabeçalho das colunas
    printf("   ");
    for (j = 0; j < TAM; j++)
        printf(" %d", j);
    printf("\n");

    // impressão do tabuleiro
    for (i = 0; i < TAM; i++) {
        printf(" %c ", letraslinha[i]);
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == NAVIO_DIAGONAL) {
                printf("%c ", SIMBOLO_DIAGONAL);
            } else if (tabuleiro[i][j] == NAVIO_HORIZONTAL) {
                printf("%c ", SIMBOLO_HORIZONTAL);
            } else if (tabuleiro[i][j] == NAVIO_VERTICAL) {
                printf("%c ", SIMBOLO_VERTICAL);
            } else {
                printf("%c ", SIMBOLO_AGUA);
            }
        }
        printf("\n");
    }

    return 0;
}



    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

