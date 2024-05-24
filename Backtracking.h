// backtracking.h

#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <utility>
#include <iostream>

// Define the size of the Tic Tac Toe board
#define ROWS 3
#define COLS 3

// Structure to hold the move coordinates
enum direction{
        row=1,
        col,
        diagonal,
        antiDiagonal
    };


class game {



	

public:
	class Move {
	public:
		int row;
		int col;
	};
	
	bool isDraw(char board[][COLS]);
	short playerToNumber(char player);
	std::pair<bool, int> checkIndex(char board[][COLS], std::pair<int,int>, direction dir);



	

	static const char player='x';
	static const char computer='o';
	// Function to evaluate the current state of the game
	int evaluate(char board[ROWS][COLS]);

	// Function to check if the game is over
	int isGameOver(char board[ROWS][COLS]);

	// Minimax function
	int minimax(char board[ROWS][COLS], int depth, bool isMaximizer);

	// Function to find the best move for the computer using Minimax
	Move findBestMove(char board[ROWS][COLS]);


};


#endif /* BACKTRACKING_H */
