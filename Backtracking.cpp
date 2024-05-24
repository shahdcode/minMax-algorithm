#include <iostream>
#include "Backtracking.h"
using namespace std;

char game::player = 'x';
char game::computer = 'o';

int game::evaluate(char board[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        if (board[row][0] == board[row][1] &&
            board[row][1] == board[row][2]) {
            if (board[row][0] == computer)
                return +10;
            else if (board[row][0] == player)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == board[1][col] &&
            board[1][col] == board[2][col]) {
            if (board[0][col] == computer)
                return +10;
            else if (board[0][col] == player)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        if (board[0][0] == computer)
            return +10;
        else if (board[0][0] == player)
            return -10;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        if (board[0][2] == computer)
            return +10;
        else if (board[0][2] == player)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}

int game::isGameOver(char board[ROWS][COLS]) {}

int game::minimax(char board[ROWS][COLS], int depth, int isMaximizer) {}

game::Move game::findBestMove(char board[ROWS][COLS]) {
    int bestVal = INT_MIN;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == '_') {
                board[i][j] = computer;
                int moveVal = minimax(board, 0, false);
                board[i][j] = '_';

                if (moveVal > bestVal) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}
