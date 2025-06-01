#include <stdio.h>
#include <math.h> // Necessário para a função abs() na habilidade Octaedro

#define BOARD_SIZE 10
#define SHIP_SIZE 3
#define SKILL_MATRIX_SIZE 5 // Tamanho fixo para as matrizes de habilidade (ex: 5x5)
#define WATER 0
#define SHIP 3
#define SKILL_EFFECT 5 // Novo valor para representar a área de efeito da habilidade

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
    printf("\nTabuleiro:\n");
    printf("   "); // Espaço para alinhar as colunas
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j); // Números das colunas
    }
    printf("\n");
    printf("  +-");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("--");
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i); // Números das linhas
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Usa caracteres diferentes para melhor visualização
            if (board[i][j] == WATER) {
                printf("~ "); // Água
            } else if (board[i][j] == SHIP) {
                printf("# "); // Navio
            } else if (board[i][j] == SKILL_EFFECT) {
                printf("X "); // Área de Habilidade
            } else {
                printf("%d ", board[i][j]); // Caso tenha outro valor
            }
        }
        printf("\n");
    }
    printf("\n");
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

// --- Funções para Habilidades Especiais ---

// Função para criar a matriz de habilidade Cone
void createConeSkillMatrix(int skillMatrix[SKILL_MATRIX_SIZE][SKILL_MATRIX_SIZE]) {
    for (int i = 0; i < SKILL_MATRIX_SIZE; i++) {
        for (int j = 0; j < SKILL_MATRIX_SIZE; j++) {
            // Lógica para formar um cone apontando para baixo
            // O centro da base seria na linha SKILL_MATRIX_SIZE-1
            // A largura do cone aumenta com a linha
            if (j >= (SKILL_MATRIX_SIZE - 1) / 2 - i &&
                j <= (SKILL_MATRIX_SIZE - 1) / 2 + i) {
                skillMatrix[i][j] = 1;
            } else {
                skillMatrix[i][j] = 0;
            }
        }
    }
    // Exemplo: para SKILL_MATRIX_SIZE = 5
    // Linha 0: (0,2)
    // Linha 1: (1,1), (1,2), (1,3)
    // Linha 2: (2,0), (2,1), (2,2), (2,3), (2,4)
    // ...
}

// Função para criar a matriz de habilidade Cruz
void createCrossSkillMatrix(int skillMatrix[SKILL_MATRIX_SIZE][SKILL_MATRIX_SIZE]) {
    int center = SKILL_MATRIX_SIZE / 2;
    for (int i = 0; i < SKILL_MATRIX_SIZE; i++) {
        for (int j = 0; j < SKILL_MATRIX_SIZE; j++) {
            // Lógica para formar uma cruz com o centro
            if (i == center || j == center) {
                skillMatrix[i][j] = 1;
            } else {
                skillMatrix[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade Octaedro (Losango)
void createOctahedronSkillMatrix(int skillMatrix[SKILL_MATRIX_SIZE][SKILL_MATRIX_SIZE]) {
    int center = SKILL_MATRIX_SIZE / 2;
    for (int i = 0; i < SKILL_MATRIX_SIZE; i++) {
        for (int j = 0; j < SKILL_MATRIX_SIZE; j++) {
            // Lógica para formar um losango (octaedro em 2D)
            // A soma da distância absoluta ao centro deve ser menor ou igual ao centro
            if (abs(i - center) + abs(j - center) <= center) {
                skillMatrix[i][j] = 1;
            } else {
                skillMatrix[i][j] = 0;
            }
        }
    }
}

// Função para sobrepor a matriz de habilidade ao tabuleiro
void applySkillToBoard(int board[BOARD_SIZE][BOARD_SIZE], int skillMatrix[SKILL_MATRIX_SIZE][SKILL_MATRIX_SIZE], int originRow, int originCol) {
    int halfSize = SKILL_MATRIX_SIZE / 2;

    for (int i = 0; i < SKILL_MATRIX_SIZE; i++) {
        for (int j = 0; j < SKILL_MATRIX_SIZE; j++) {
            // Calcula a posição no tabuleiro
            int boardRow = originRow - halfSize + i;
            int boardCol = originCol - halfSize + j;

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (boardRow >= 0 && boardRow < BOARD_SIZE &&
                boardCol >= 0 && boardCol < BOARD_SIZE) {
                // Se a posição na matriz de habilidade for 1, marca no tabuleiro
                if (skillMatrix[i][j] == 1) {
                    // Evita sobrescrever um navio existente se o requisito fosse manter o navio
                    // Neste caso, se a posição é água ou outra habilidade, aplica.
                    // Se a posição já é um navio, o navio continua sendo um navio.
                    if (board[boardRow][boardCol] != SHIP) {
                         board[boardRow][boardCol] = SKILL_EFFECT;
                    }
                }
            }
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int coneSkill[SKILL_MATRIX_SIZE][SKILL_MATRIX_SIZE];
    int crossSkill[SKILL_MATRIX_SIZE][SKILL_MATRIX_SIZE];
    int octahedronSkill[SKILL_MATRIX_SIZE][SKILL_MATRIX_SIZE];

    // Inicializa o tabuleiro
    initializeBoard(board);

    // --- Posicionamento dos Navios ---
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

    // Tenta posicionar os navios
    if (isValidPlacement(board, ship1Row, ship1Col, ship1Orientation)) {
        placeShip(board, ship1Row, ship1Col, ship1Orientation);
        printf("Navio 1 (Horizontal) posicionado com sucesso em (%d, %d).\n", ship1Row, ship1Col);
    } else {
        printf("Não foi possível posicionar o Navio 1 (Horizontal) em (%d, %d). Verifique os limites ou sobreposição.\n", ship1Row, ship1Col);
    }

    if (isValidPlacement(board, ship2Row, ship2Col, ship2Orientation)) {
        placeShip(board, ship2Row, ship2Col, ship2Orientation);
        printf("Navio 2 (Vertical) posicionado com sucesso em (%d, %d).\n", ship2Row, ship2Col);
    } else {
        printf("Não foi possível posicionar o Navio 2 (Vertical) em (%d, %d). Verifique os limites ou sobreposição.\n", ship2Row, ship2Col);
    }

    if (isValidPlacement(board, ship3Row, ship3Col, ship3Orientation)) {
        placeShip(board, ship3Row, ship3Col, ship3Orientation);
        printf("Navio 3 (Diagonal Principal) posicionado com sucesso em (%d, %d).\n", ship3Row, ship3Col);
    } else {
        printf("Não foi possível posicionar o Navio 3 (Diagonal Principal) em (%d, %d). Verifique os limites ou sobreposição.\n", ship3Row, ship3Col);
    }

    if (isValidPlacement(board, ship4Row, ship4Col, ship4Orientation)) {
        placeShip(board, ship4Row, ship4Col, ship4Orientation);
        printf("Navio 4 (Diagonal Secundária) posicionado com sucesso em (%d, %d).\n", ship4Row, ship4Col);
    } else {
        printf("Não foi possível posicionar o Navio 4 (Diagonal Secundária) em (%d, %d). Verifique os limites ou sobreposição.\n", ship4Row, ship4Col);
    }

    // --- Criação e Aplicação das Habilidades Especiais ---

    // Habilidade Cone
    createConeSkillMatrix(coneSkill);
    int coneOriginRow = 0; // Ponto de origem do cone no tabuleiro
    int coneOriginCol = 5;
    printf("\nAplicando habilidade CONE em (%d, %d).", coneOriginRow, coneOriginCol);
    applySkillToBoard(board, coneSkill, coneOriginRow, coneOriginCol);

    // Habilidade Cruz
    createCrossSkillMatrix(crossSkill);
    int crossOriginRow = 5; // Ponto de origem da cruz no tabuleiro
    int crossOriginCol = 2;
    printf("\nAplicando habilidade CRUZ em (%d, %d).", crossOriginRow, crossOriginCol);
    applySkillToBoard(board, crossSkill, crossOriginRow, crossOriginCol);

    // Habilidade Octaedro (Losango)
    createOctahedronSkillMatrix(octahedronSkill);
    int octahedronOriginRow = 8; // Ponto de origem do losango no tabuleiro
    int octahedronOriginCol = 8;
    printf("\nAplicando habilidade OCTAEDRO em (%d, %d).", octahedronOriginRow, octahedronOriginCol);
    applySkillToBoard(board, octahedronSkill, octahedronOriginRow, octahedronOriginCol);

    // Exibe o tabuleiro final com navios e áreas de efeito
    printBoard(board);

    return 0;
}
