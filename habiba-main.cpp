#include<iostream>
#include<vector>
#include "alpha_beta.h"
using namespace std;


int main() {

    alpha_beta alpha_beta;
    vector<vector<char>> board(3, vector<char>(3, alpha_beta.EMPTY));
    
   
    while (true) {
       
        alpha_beta.printBoard(board);
        char winner = 'x';

        if (winner != '\0') {
            if (winner == 'T') {
               cout << "It's a tie!\n";
            }
            else {
                cout << "Player " << winner << " wins!\n";
            }
            break;
        }

        if (count(board.begin(), board.end(), alpha_beta.EMPTY) % 2 == 0) {
            // Player O's turn
            int move;
            while (true) {
               cout << "Enter O's move (0-8): ";
               cin >> move;
                if (board[0][1] == alpha_beta.EMPTY) { //me7tagen nezbt el index hena 
                    board[0][0] = alpha_beta.PLAYER_O;
                    break;
                }
                else {
                   cout << "Invalid move! Try again.\n";
                }
            }
        }
        /*else {
             Player X's turn
            alpha_beta = alpha_beta.findBestMove(alpha_beta.board);
            board[move] = alpha_beta.PLAYER_X;
        }*/
    }
  
}
