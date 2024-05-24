#include "Alpha_Beta.h"
#include<cmath>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX = 1000;
const int MIN = -1000;
const int BOARD_SIZE = 3;
const int EMPTY = 0;
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';


int minimax(int depth, int nodeIndex,
    bool maximizingPlayer,int values[], int alpha,int beta)
{
    if (depth == 3)
        return values[nodeIndex];

    if (maximizingPlayer)
    {
        int best = MIN;

        for (int i = 0; i < 2; i++)
        {

            int val = minimax(depth + 1, nodeIndex * 2 + i,
                false, values, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);

            if (beta <= alpha)
                break;
        }
        return best;
    }
    else
    {
        int best = MAX;


        for (int i = 0; i < 2; i++)
        {
            int val = minimax(depth + 1, nodeIndex * 2 + i,
                true, values, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha)
                break;
        }
        return best;
    }
}

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY)
                cout << "_ ";
            else if (board[i][j] == PLAYER_X)
                cout << "X ";
            else
                cout << "O ";
        }
        cout << endl;
    }
}

int checkWin(const vector<vector<int>>& board, int player) {

    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return player;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return player;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return player;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return player;

    return EMPTY;
}