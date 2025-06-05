#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com água (valor 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais definidas no código
    // Navio Horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Navio Vertical
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Verificações de limites e sobreposição antes de posicionar os navios

    // Valida navio horizontal
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposição no navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa o limite do tabuleiro.\n");
    }

    // Valida navio vertical
    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposição no navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical ultrapassa o limite do tabuleiro.\n");
    }

    // Exibe o tabuleiro final
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
