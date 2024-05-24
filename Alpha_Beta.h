#ifndef ALPHA_BETA_H
#define ALPHA_BETA_H
// Define the size of the Tic Tac Toe board
#define ROWS 3
#define COLS 3
#include<vector>
using namespace std;
class alpha_beta
{
	class Move {
	public:
		int row;
		int col;
	};

public:
	const int MAX = 1000;
	const int MIN = -1000;
	const int BOARD_SIZE = 3;
	const char EMPTY = ' ';
	const char PLAYER_X = 'X';
	const char PLAYER_O = 'O';
	vector<vector<char>> board;
	static char player;
	static char computer;
	int values[9] = { 0 };
	// Function to evaluate the current state of the game
	int evaluate(const vector<vector<char>>& board, char player);

	// Function to check if the game is over
	int checkWin(const vector<vector<char>>& board, char player);

	// Minimax function
	int minimax(int depth, int nodeIndex, bool maximizingPlayer, int alpha, int beta);

	// Function to find the best move for the computer using Minimax
	Move findBestMove(vector<char>& board);

	void printBoard(const vector<vector<char>>& board);
};

