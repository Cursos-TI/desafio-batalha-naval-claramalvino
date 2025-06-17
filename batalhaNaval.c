#include <stdio.h>
#include <stdlib.h> // Para abs()

#define TAM 10

// Tipos de navios
#define NAVIO_DIAGONAL 7
#define NAVIO_HORIZONTAL 4
#define NAVIO_VERTICAL 3

// Habilidades
#define HABILIDADE_CONE 5
#define HABILIDADE_CRUZ 6
#define HABILIDADE_OCTAEDRO 8

// Símbolos
#define SIMBOLO_DIAGONAL 'D'
#define SIMBOLO_HORIZONTAL 'H'
#define SIMBOLO_VERTICAL 'V'
#define SIMBOLO_CONE 'C'
#define SIMBOLO_CRUZ 'X'
#define SIMBOLO_OCTAEDRO 'O'
#define SIMBOLO_AGUA '0'

// Parâmetros
#define ALTURA 3
#define RAIO_OCTAEDRO 3

// Matrizes
int tabuleiro[TAM][TAM];
int tabuleiroCone[TAM][TAM];
int tabuleiroCruz[TAM][TAM];
int tabuleiroOctaedro[TAM][TAM];
char letraslinha[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

// Posiciona os navios
void posiciona_navios() {
    int i, j;
    for (i = 0; i < 3; i++) {
        tabuleiro[i][i] = NAVIO_DIAGONAL;
    }
    for (i = 0; i < 3; i++) {
        tabuleiro[i][TAM - 1 - i] = NAVIO_DIAGONAL;
    }
    for (j = 1; j < 4; j++) {
        tabuleiro[5][j] = NAVIO_HORIZONTAL;
    }
    for (i = 7; i < 10; i++) {
        tabuleiro[i][5] = NAVIO_VERTICAL;
    }
}

// Cone
void aplica_habilidade_cone(int baseX, int baseY) {
    int i, j;
    for (i = 0; i <= ALTURA; i++) {
        for (j = -i; j <= i; j++) {
            int x = baseX + i;
            int y = baseY + j;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                tabuleiroCone[x][y] = HABILIDADE_CONE;
            }
        }
    }
}

// Cruz
void aplica_habilidade_cruz() {
    int i;
    for (i = 0; i < TAM; i++) {
        tabuleiroCruz[5][i] = HABILIDADE_CRUZ;
        tabuleiroCruz[i][4] = HABILIDADE_CRUZ;
    }
}

// Octaedro
void aplica_habilidade_octaedro(int centroX, int centroY, int raio) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (abs(i - centroX) + abs(j - centroY) <= raio) {
                tabuleiroOctaedro[i][j] = HABILIDADE_OCTAEDRO;
            }
        }
    }
}

// Cabeçalho
void imprime_cabecalho() {
    printf("  ");
    int j;
    for (j = 0; j < TAM; j++)
        printf(" %d", j);
    printf("\n");
}

// Impressões
void imprime_tabuleiro(int matriz[TAM][TAM], int tipo, char simbolo) {
    imprime_cabecalho();
    int i;
    for (i = 0; i < TAM; i++) {
        printf(" %c ", letraslinha[i]);
        int j;
        for (j = 0; j < TAM; j++) {
            if (matriz[i][j] == tipo)
                printf(" %c", simbolo);
            else
                printf(" %c", SIMBOLO_AGUA);
        }
        printf("\n");
    }
}

// Navios
void imprime_tabuleiro_navios() {
    imprime_cabecalho();
    int i;
    for (i = 0; i < TAM; i++) {
        printf(" %c ", letraslinha[i]);
        int j; 
        for (j = 0; j < TAM; j++) {
            switch (tabuleiro[i][j]) {
                case NAVIO_DIAGONAL: printf(" %c", SIMBOLO_DIAGONAL); break;
                case NAVIO_HORIZONTAL: printf(" %c", SIMBOLO_HORIZONTAL); break;
                case NAVIO_VERTICAL: printf(" %c", SIMBOLO_VERTICAL); break;
                default: printf(" %c", SIMBOLO_AGUA);
            }
        }
        printf("\n");
    }
}

// Main
int main() {
    posiciona_navios();

    aplica_habilidade_cone(2, 5);
    aplica_habilidade_cruz(6, 6);
    aplica_habilidade_octaedro(4, 4, RAIO_OCTAEDRO);

    printf("=== TABULEIRO DE NAVIOS ===\n");
    imprime_tabuleiro_navios();

    printf("\n=== HABILIDADE CONE ===\n");
    imprime_tabuleiro(tabuleiroCone, HABILIDADE_CONE, SIMBOLO_CONE);

    printf("\n=== HABILIDADE CRUZ ===\n");
    imprime_tabuleiro(tabuleiroCruz, HABILIDADE_CRUZ, SIMBOLO_CRUZ);

    printf("\n=== HABILIDADE OCTAEDRO ===\n");
    imprime_tabuleiro(tabuleiroOctaedro, HABILIDADE_OCTAEDRO, SIMBOLO_OCTAEDRO);

    return 0;
}

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

