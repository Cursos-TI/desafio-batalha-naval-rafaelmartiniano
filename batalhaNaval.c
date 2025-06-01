#include <stdio.h>

#define BOARD_SIZE 10
#define SHIP_SIZE 3
#define WATER 0
#define SHIP 3

// Enum para representar as orientações dos navios
typedef enum {
    HORIZONTAL,
    VERTICAL,
    DIAGONAL_PRINCIPAL, // Canto superior esquerdo para inferior direito (linha e coluna aumentam)
    DIAGONAL_SECUNDARIA  // Canto superior direito para inferior esquerdo (linha aumenta, coluna diminui)
} ShipOrientation;

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
int isValidPlacement(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, ShipOrientation orientation) {
    // Validação de limites e sobreposição
    for (int k = 0; k < SHIP_SIZE; k++) {
        int currentRow = startRow;
        int currentCol = startCol;

        switch (orientation) {
            case HORIZONTAL:
                currentCol = startCol + k;
                break;
            case VERTICAL:
                currentRow = startRow + k;
                break;
            case DIAGONAL_PRINCIPAL:
                currentRow = startRow + k;
                currentCol = startCol + k;
                break;
            case DIAGONAL_SECUNDARIA:
                currentRow = startRow + k;
                currentCol = startCol - k; // Coluna diminui
                break;
        }

        // Verifica se a posição está dentro dos limites do tabuleiro
        if (currentRow < 0 || currentRow >= BOARD_SIZE ||
            currentCol < 0 || currentCol >= BOARD_SIZE) {
            return 0; // Fora dos limites
        }

        // Verifica sobreposição
        if (board[currentRow][currentCol] == SHIP) {
            return 0; // Sobreposição
        }
    }
    return 1; // Posicionamento válido
}

// Função para posicionar um navio no tabuleiro
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, ShipOrientation orientation) {
    for (int k = 0; k < SHIP_SIZE; k++) {
        int currentRow = startRow;
        int currentCol = startCol;

        switch (orientation) {
            case HORIZONTAL:
                currentCol = startCol + k;
                break;
            case VERTICAL:
                currentRow = startRow + k;
                break;
            case DIAGONAL_PRINCIPAL:
                currentRow = startRow + k;
                currentCol = startCol + k;
                break;
            case DIAGONAL_SECUNDARIA:
                currentRow = startRow + k;
                currentCol = startCol - k;
                break;
        }
        board[currentRow][currentCol] = SHIP;
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    // Inicializa o tabuleiro
    initializeBoard(board);

    // Navios a serem posicionados (tamanho fixo 3)
    // Coordenadas iniciais e orientação
    int ship1Row = 0;
    int ship1Col = 0;
    ShipOrientation ship1Orientation = HORIZONTAL;

    int ship2Row = 4;
    int ship2Col = 8;
    ShipOrientation ship2Orientation = VERTICAL;

    int ship3Row = 1;
    int ship3Col = 1;
    ShipOrientation ship3Orientation = DIAGONAL_PRINCIPAL;

    int ship4Row = 2;
    int ship4Col = 7;
    ShipOrientation ship4Orientation = DIAGONAL_SECUNDARIA;

    // Tenta posicionar o primeiro navio (Horizontal)
    if (isValidPlacement(board, ship1Row, ship1Col, ship1Orientation)) {
        placeShip(board, ship1Row, ship1Col, ship1Orientation);
        printf("Navio 1 (Horizontal) posicionado com sucesso em (%d, %d).\n", ship1Row, ship1Col);
    } else {
        printf("Não foi possível posicionar o Navio 1 (Horizontal) em (%d, %d). Verifique os limites ou sobreposição.\n", ship1Row, ship1Col);
    }

    // Tenta posicionar o segundo navio (Vertical)
    if (isValidPlacement(board, ship2Row, ship2Col, ship2Orientation)) {
        placeShip(board, ship2Row, ship2Col, ship2Orientation);
        printf("Navio 2 (Vertical) posicionado com sucesso em (%d, %d).\n", ship2Row, ship2Col);
    } else {
        printf("Não foi possível posicionar o Navio 2 (Vertical) em (%d, %d). Verifique os limites ou sobreposição.\n", ship2Row, ship2Col);
    }

    // Tenta posicionar o terceiro navio (Diagonal Principal)
    if (isValidPlacement(board, ship3Row, ship3Col, ship3Orientation)) {
        placeShip(board, ship3Row, ship3Col, ship3Orientation);
        printf("Navio 3 (Diagonal Principal) posicionado com sucesso em (%d, %d).\n", ship3Row, ship3Col);
    } else {
        printf("Não foi possível posicionar o Navio 3 (Diagonal Principal) em (%d, %d). Verifique os limites ou sobreposição.\n", ship3Row, ship3Col);
    }

    // Tenta posicionar o quarto navio (Diagonal Secundária)
    if (isValidPlacement(board, ship4Row, ship4Col, ship4Orientation)) {
        placeShip(board, ship4Row, ship4Col, ship4Orientation);
        printf("Navio 4 (Diagonal Secundária) posicionado com sucesso em (%d, %d).\n", ship4Row, ship4Col);
    } else {
        printf("Não foi possível posicionar o Navio 4 (Diagonal Secundária) em (%d, %d). Verifique os limites ou sobreposição.\n", ship4Row, ship4Col);
    }

    // Exibe o tabuleiro com os navios
    printBoard(board);

    return 0;
}
