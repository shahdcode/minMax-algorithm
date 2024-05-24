#include<iostream>
#include"Backtracking.h"
using namespace std;
/* 
char game::computer='x';
char game::player='o'; */

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout << std::endl;
    }
}

bool isMoveValid(char board[ROWS][COLS], int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '_';
}

int main(){
game tictactoe;
    char board[ROWS][COLS] = {
        { '_', '_', '_' },
        { '_', '_', '_' },
        { '_', '_', '_' }
    };

    cout << "Welcome to Tic Tac Toe!\n";
    printBoard(board);

    while (tictactoe.isGameOver(board) ==0) {
        int playerRow, playerCol;
        cout << "Enter your move (row and column): ";
        cin >> playerRow >> playerCol;

        if (!isMoveValid(board, playerRow, playerCol)) {
            cout << "Invalid move. Try again.\n";
            continue;
            
        }

        board[playerRow][playerCol] = game::player;
        printBoard(board);

        /* std::cout << "  -->> "<< tictactoe.isGameOver(board) << '\n';
 */
        /* if (tictactoe.isGameOver(board)) {
            if (tictactoe.evaluate(board) == -10) {
                cout << "You win!\n";
            }
            else {
                cout << "It's a tie!\n";
            }
            break;
        } */

        

        cout << "Computer's turn:\n";
        game::Move bestMove = tictactoe.findBestMove(board);
        board[bestMove.row][bestMove.col] = game::computer;
        printBoard(board);

        /* if (tictactoe.isGameOver(board)) {
            if (tictactoe.evaluate(board) == 10) {
                std::cout << "Computer wins!\n";
            }
            else {
                std::cout << "It's a tie!\n";
            }
            break;
        } */
        switch (tictactoe.isGameOver(board))
        {
        case 2:
            /* code */
            std::cout << "You Win!\n****HOORAY***\n";
            return 0;
        case 1:
            std::cout << "You Loose!:( ****Try Again***\n";
            return 0;
        case 0:
            
            std::cout << "\nGame still on!!\n";

            break;
        default:
                std::cout << "That's a Tie..play Again!\n\n";
            break;
        }
    }
}