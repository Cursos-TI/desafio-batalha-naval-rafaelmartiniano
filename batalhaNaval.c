#include <stdio.h>

#define BOARD_SIZE 10
#define SHIP_SIZE 3
#define WATER 0
#define SHIP 3

// Função para inicializar o tabuleiro com água
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = WATER;
        }
    }
}

// Função para exibir o tabuleiro
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado
// Retorna 1 se for válido, 0 caso contrário
int isValidPlacement(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int orientation) {
    // Validação de limites
    if (orientation == 0) { // Horizontal
        if (startCol + SHIP_SIZE > BOARD_SIZE) {
            return 0; // Fora dos limites
        }
        // Validação de sobreposição simplificada
        for (int j = 0; j < SHIP_SIZE; j++) {
            if (board[startRow][startCol + j] == SHIP) {
                return 0; // Sobreposição
            }
        }
    } else { // Vertical
        if (startRow + SHIP_SIZE > BOARD_SIZE) {
            return 0; // Fora dos limites
        }
        // Validação de sobreposição simplificada
        for (int i = 0; i < SHIP_SIZE; i++) {
            if (board[startRow + i][startCol] == SHIP) {
                return 0; // Sobreposição
            }
        }
    }
    return 1; // Posicionamento válido
}

// Função para posicionar um navio no tabuleiro
// orientation: 0 para horizontal, 1 para vertical
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int orientation) {
    if (orientation == 0) { // Horizontal
        for (int j = 0; j < SHIP_SIZE; j++) {
            board[startRow][startCol + j] = SHIP;
        }
    } else { // Vertical
        for (int i = 0; i < SHIP_SIZE; i++) {
            board[startRow + i][startCol] = SHIP;
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    // Inicializa o tabuleiro
    initializeBoard(board);

    // Coordenadas para o navio horizontal
    // Exemplo: Linha 2, Coluna 1
    int hShipRow = 2;
    int hShipCol = 1;

    // Coordenadas para o navio vertical
    // Exemplo: Linha 5, Coluna 5
    int vShipRow = 5;
    int vShipCol = 5;

    // Tenta posicionar o navio horizontal
    if (isValidPlacement(board, hShipRow, hShipCol, 0)) {
        placeShip(board, hShipRow, hShipCol, 0);
        printf("Navio horizontal posicionado com sucesso em (%d, %d).\n", hShipRow, hShipCol);
    } else {
        printf("Não foi possível posicionar o navio horizontal em (%d, %d). Verifique os limites ou sobreposição.\n", hShipRow, hShipCol);
    }

    // Tenta posicionar o navio vertical
    if (isValidPlacement(board, vShipRow, vShipCol, 1)) {
        placeShip(board, vShipRow, vShipCol, 1);
        printf("Navio vertical posicionado com sucesso em (%d, %d).\n", vShipRow, vShipCol);
    } else {
        printf("Não foi possível posicionar o navio vertical em (%d, %d). Verifique os limites ou sobreposição.\n", vShipRow, vShipCol);
    }

    // Exibe o tabuleiro com os navios
    printBoard(board);

    return 0;
}
