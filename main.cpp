#include<iostream>
#include<vector>
#include<limits>
#include <cmath>
#include<algorithm>
#include"Backtracking.h"
#include"Alpha_Beta.h"
using namespace std;


int main(){
    alpha_beta a;
     vector<string> board(9, a.EMPTY);
    while (true) {
        a.printBoard(board);
        string winner = a.checkWinner(board);

        if (!winner.empty()) {
            if (winner == "tie")
                cout << "It's a tie!" << endl;
            else
                cout << "Player " << winner << " wins!" << endl;
            break;
        }

        if (count(board.begin(), board.end(), a.EMPTY) % 2 == 1) {
            int move;
            cout << "Your move (0-8): ";
            cin >> move;
            if (board[move] == a.EMPTY)
                board[move] = a.PLAYER_O;
            else
                cout << "Invalid move! Try again." << endl;
        }
        else {
            a.BranchCount = 0;
            int move = a.findBestMove(board);
            board[move] = a.PLAYER_X;
            cout << "Number of visited branches: " << a.BranchCount << endl;
        }
    }

}

// char game::computer='x';
// char game::player='o';

// void printBoard(char board[ROWS][COLS]) {
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {
//             cout << board[i][j] << " ";
//         }
//         cout << std::endl;
//     }
// }

// bool isMoveValid(char board[ROWS][COLS], int row, int col) {
//     return row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '_';
// }

// int main(){
// game tictactoe;
//     char board[ROWS][COLS] = {
//         { '_', '_', '_' },
//         { '_', '_', '_' },
//         { '_', '_', '_' }
//     };

//     cout << "Welcome to Tic Tac Toe!\n";
//     printBoard(board);

//     while (true) {
//         int playerRow, playerCol;
//         cout << "Enter your move (row and column): ";
//         cin >> playerRow >> playerCol;

//         if (!isMoveValid(board, playerRow, playerCol)) {
//             cout << "Invalid move. Try again.\n";
//             continue;
//         }

//         board[playerRow][playerCol] = game::player;
//         printBoard(board);

//         if (tictactoe.isGameOver(board)) {
//             if (tictactoe.evaluate(board) == -10) {
//                 cout << "You win!\n";
//             }
//             else {
//                 cout << "It's a tie!\n";
//             }
//             break;
//         }

//         cout << "Computer's turn:\n";
//         game::Move bestMove = tictactoe.findBestMove(board);
//         board[bestMove.row][bestMove.col] = game::computer;
//         printBoard(board);

//         if (tictactoe.isGameOver(board)) {
//             if (tictactoe.evaluate(board) == 10) {
//                 std::cout << "Computer wins!\n";
//             }
//             else {
//                 std::cout << "It's a tie!\n";
//             }
//             break;
//         }
//     }
// }


