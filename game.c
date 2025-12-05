#include <stdio.h>

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

// Check winner
int checkWin(char board[3][3]) {
    // Rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return 1;

    // Columns
    for (int j = 0; j < 3; j++)
        if (board[0][j] == board[1][j] &&
            board[1][j] == board[2][j] &&
            board[0][j] != ' ')
            return 1;

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return 1;

    return 0;
}

// Check draw
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;  // Still empty space
    return 1;
}

int main() {
    char board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
    int row, col, player = 1;
    char mark;

    printf("\n=== TIC TAC TOE ===\n");
    printf("Player 1 = X\nPlayer 2 = O\n");

    while(1) {
        printBoard(board);

        // Player turn
        player = (player % 2 == 1) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d turn (%c)\n", player, mark);

        printf("Enter row (0-2): ");
        scanf("%d", &row);

        printf("Enter column (0-2): ");
        scanf("%d", &col);

        // Invalid move
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("\nInvalid move! Try again.\n");
            continue;
        }

        board[row][col] = mark;

        // Check win
        if (checkWin(board)) {
            printBoard(board);
            printf(" Player %d WINS!\n", player);
            break;
        }

        // Check draw
        if (checkDraw(board)) {
            printBoard(board);
            printf("Game Draw!\n");
            break;
        }

        player++;
    }

    printf("=== GAME OVER ===\n");
    return 0;
}
