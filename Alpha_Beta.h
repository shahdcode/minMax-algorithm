#ifndef ALPHA_BETA_H
#define ALPHA_BETA_H
// Define the size of the Tic Tac Toe board
#define ROWS 3
#define COLS 3
#include <vector>
#include <iostream>
#include <limits>

using namespace std;
class alpha_beta
{
public:
	const string EMPTY = "-";
	const string PLAYER_X = "X";
	const string PLAYER_O = "O";
	int BranchCount = 0;

	void printBoard(const vector<string> &board);
	string checkWinner(const vector<string>& board);
	int evaluate(const vector<string>& board);
	int minimax(vector<string>& board, int depth, int alpha, int beta, bool maximizingPlayer);
	int findBestMove(vector<string>& board);
};

#endif