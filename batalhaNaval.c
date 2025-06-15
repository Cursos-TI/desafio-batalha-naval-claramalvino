#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
int main (){ 
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {0};

    // Letras para rotular as linhas
    char letrasLinha[10] = {'A','B','C','D','E','F','G','H','I','J'};


    // Posiciona navio vertical (coluna 2, linhas 1 a 3)
    for (int i = 1; i <= 3; i++) {
        tabuleiro[i][2] = 4; // Marca como navio
    }

    // Posiciona navio horizontal (linha 6, colunas 4 a 6)
    for (int j = 4; j <= 6; j++) {
        tabuleiro[6][j] = 4; // Marca como navio
    }

    // Imprime cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf(" %d", j);
    }
    printf("\n");

    // Imprime linhas do tabuleiro com navios visuais
    for (int i = 0; i < 10; i++) {
        printf(" %c ", letrasLinha[i]);
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 4) {
                printf("3 ");  // Navio
            } else {
                printf(". ");  // Mar
            }
        }
        printf("\n");
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

    return 0;
}
