#pragma once
#include "Game.h"
#include <limits>

///To add A Diff Setting create A Flag and Add it's Supporting Functions and Use the Flag for Calling the MiniMax Function from the findBestMove method.


class BotPlayer : public Game
{
private:
	class Move {
	public:
		int row;
		int col;
	};


public:
	bool isDraw();
	//int evaluate(char board[ROWS][COLS]);



	// Function to check if the game is over
	int isGameOver();

	// Brute Force Approach Functions
	int minimaxBrute(int depth, bool isMaximizer);
	int findBestMoveBrute();

	// Alpha Beta Approach Functions
	int minimaxAlphaBeta(int depth, int alpha, int beta, bool maximizingPlayer);
	int findBestMoveAlphaBeta();


	void checkGameState(tgui::GuiSFML& gui);

};

