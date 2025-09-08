#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

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

    int tabulereiro[10][10];
    int coordNavioHorizontal[2] = {5, 3};
    int coordNavioVertical[2] = {2, 3};
    int coordNavioDiagonalA[2] = {8, 8};
    int coordNavioDiagonalB[2] = {1, 4};
    char colunas[10] = "ABCDEFGHIJ";

    // valida posição do navio
    if (coordNavioHorizontal[1] + 2 > 10 || coordNavioHorizontal[1] - 2 < 0)
    {
        printf("\nPosição do navio ultrapssou limites horizontais\n");
        return 0;
    }

    if (coordNavioVertical[0] + 2 > 10 || coordNavioVertical[0] - 2 < 0)
    {
        printf("\nPosição do navio ultrapssou limites verticais\n");
        return 0;
    }

    if (coordNavioDiagonalA[0] + 2 > 10 && coordNavioDiagonalA[1] + 2 > 0)
    {
        printf("\nPosição do navio ultrapssou limites\n");
        return 0;
    }

    // verifica colisão
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (coordNavioHorizontal[1] + i == coordNavioVertical[1] && coordNavioHorizontal[0] == coordNavioVertical[0] + j)
            {
                printf("\nOs navios colidiram\n");
                return 0;
            }

            if ((coordNavioDiagonalA[0] + i == coordNavioVertical[0] + j && coordNavioVertical[1] == coordNavioDiagonalA[1] + i) ||
                (coordNavioDiagonalB[0] + i == coordNavioVertical[0] + j && coordNavioVertical[1] == coordNavioDiagonalB[1] + i))
            {
                printf("\nOs navios colidiram\n");
                return 0;
            }

            if ((coordNavioDiagonalA[0] + i == coordNavioHorizontal[0] && coordNavioHorizontal[1] + j == coordNavioDiagonalA[1] + i) ||
                (coordNavioDiagonalB[0] + i == coordNavioHorizontal[0] && coordNavioHorizontal[1] + j == coordNavioDiagonalB[1] + i))
            {
                printf("\nOs navios colidiram\n");
                return 0;
            }
        }
    }

    // popular tabulereiro
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabulereiro[i][j] = 0;
        }
    }

    // posiciona navios no tabulereiro
    for (int i = 0; i < 3; i++)
    {
        tabulereiro[coordNavioHorizontal[0] - 1][(coordNavioHorizontal[1] - 1) + i] = 1;
        tabulereiro[(coordNavioVertical[0] - 1) + i][coordNavioVertical[1] - 1] = 1;
        tabulereiro[(coordNavioDiagonalA[0] - 1) + i][(coordNavioDiagonalA[1] - 1) + i] = 3;
        tabulereiro[(coordNavioDiagonalB[0] - 1) + i][(coordNavioDiagonalB[1] - 1) + i] = 3;
    }

    // monta colunas
    printf("   ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c ", colunas[i]);
    }

    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1); // alinhamento
        for (int j = 0; j < 10; j++)
        {
            printf(" %d ", tabulereiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
