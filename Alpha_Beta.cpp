#include "alpha_beta.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;



int alpha_beta::minimax(int depth, int nodeIndex, bool maximizingPlayer, int alpha, int beta)
{
    // Evaluate the current board state directly
    int score = evaluate(board, player); // Adjust parameters accordingly

    if (depth == 3)
        return score;

    if (maximizingPlayer)
    {
        int best = MIN;

        for (int i = 0; i < 2; i++)
        {
            int val = minimax(depth + 1, nodeIndex * 2 + i, false, alpha, beta);
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
            int val = minimax(depth + 1, nodeIndex * 2 + i, true, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha)
                break;
        }
        return best;
    }
}

void alpha_beta::printBoard(const vector<vector<char>>& board)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
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

int alpha_beta::checkWin(const vector<vector<char>>& board, char player)
{

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
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
int alpha_beta::evaluate(const vector<vector<char>>& board, char player) {
    char winner = checkWin(board, player);
    if (winner == PLAYER_X) {
        return 1;
    }
    else if (winner == PLAYER_O) {
        return -1;
    }
    else {
        return 0;
    }
}

alpha_beta::Move alpha_beta::findBestMove(vector<char>& board) {
    int best_score = numeric_limits<int>::min();
    Move best_move = { -1, -1 };

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        if (board[i] == EMPTY) {
            board[i] = player;
            int move_score = minimax(0, i, false, MIN, MAX);
            board[i] = EMPTY;

            if (move_score > best_score) {
                best_score = move_score;
                best_move = { i / BOARD_SIZE, i % BOARD_SIZE };
            }
        }
    }
    return best_move;
}