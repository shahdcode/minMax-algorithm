// backtracking.h

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
	int checkWin(const vector<vector<int>>& board, int player)

	// Minimax function
	int minimax(int depth, int nodeIndex,bool maximizingPlayer, int values[], int alpha, int beta)

	// Function to find the best move for the computer using Minimax
	Move findBestMove(char board[ROWS][COLS]);

	void printBoard(const vector<vector<int>>& board)
};


#endif /* BACKTRACKING_H */
