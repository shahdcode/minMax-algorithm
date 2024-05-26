#include "alpha_beta.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void alpha_beta::printBoard(const vector<string>& board) {
    cout << "---------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| " << board[i * 3] << " | " << board[i * 3 + 1] << " | " << board[i * 3 + 2] << " |" << endl;
        cout << "---------" << endl;
    }
}

string alpha_beta::checkWinner(const vector<string>& board) {
    vector<vector<int>> winning_combinations = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columns
        {0, 4, 8}, {2, 4, 6}  // diagonals
    };

    for (const auto& combination : winning_combinations) {
        if (board[combination[0]] == board[combination[1]] && board[combination[1]] == board[combination[2]] && board[combination[0]] != EMPTY)
            return board[combination[0]];
    }

    if (find(board.begin(), board.end(), EMPTY) == board.end())
        return "tie";

    return "";
}

int alpha_beta::evaluate(const vector<string>& board) {
    string winner = checkWinner(board);

    if (winner == PLAYER_X)
        return 1;
    else if (winner == PLAYER_O)
        return -1;
    else
        return 0;
}

int alpha_beta::minimax(vector<string>& board, int depth, int alpha, int beta, bool maximizingPlayer) {
    BranchCount++;
    string winner = checkWinner(board);
    if (winner != "" || depth == 0)
        return evaluate(board);

    if (maximizingPlayer) {
        int maxEval = -numeric_limits<int>::max();
        for (int i = 0; i < 9; ++i) {
            if (board[i] == EMPTY) {
                board[i] = PLAYER_X;
                int evalScore = minimax(board, depth - 1, alpha, beta, false);
                board[i] = EMPTY;
                maxEval = max(maxEval, evalScore);
                alpha = max(alpha, evalScore);
                if (beta <= alpha)
                    break;
            }
        }
        return maxEval;
    }
    else {
        int minEval = numeric_limits<int>::max();
        for (int i = 0; i < 9; ++i) {
            if (board[i] == EMPTY) {
                board[i] = PLAYER_O;
                int evalScore = minimax(board, depth - 1, alpha, beta, true);
                board[i] = EMPTY;
                minEval = min(minEval, evalScore);
                beta = min(beta, evalScore);
                if (beta <= alpha)
                    break;
            }
        }
        return minEval;
    }
}

int alpha_beta::findBestMove(vector<string>& board) {
    int bestScore = -numeric_limits<int>::max();
    int bestMove = -1;

    for (int i = 0; i < 9; ++i) {
        if (board[i] == EMPTY) {
            board[i] = PLAYER_X;
            int moveScore = minimax(board, 9, -numeric_limits<int>::max(), numeric_limits<int>::max(), false);
            board[i] = EMPTY;

            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

