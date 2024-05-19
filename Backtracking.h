// backtracking.h

#ifndef BACKTRACKING_H
#define BACKTRACKING_H

// Define the size of the Tic Tac Toe board
#define ROWS 3
#define COLS 3

// Structure to hold the move coordinates


class game {

	class Move {
	public:
		int row;
		int col;
	};

public:
	static char player;
	static char computer;
	// Function to evaluate the current state of the game
	int evaluate(char board[ROWS][COLS]);

	// Function to check if the game is over
	int isGameOver(char board[ROWS][COLS]);

	// Minimax function
	int minimax(char board[ROWS][COLS], int depth, int isMaximizer);

	// Function to find the best move for the computer using Minimax
	Move findBestMove(char board[ROWS][COLS]);
};


#endif /* BACKTRACKING_H */
