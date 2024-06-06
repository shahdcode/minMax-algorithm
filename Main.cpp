#define NOMINMAX

#include <Windows.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include "Game.h"
#include "BotPlayer.h"

///Comment To Fix Commit Message! LuL



int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
	sf::RenderWindow window(sf::VideoMode(800,600), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);
	tgui::GuiSFML gui{window};

	Game *TicTacToe = new Game();
	BotPlayer *botPlayer = new BotPlayer();

	sf::RectangleShape Backgrnd(sf::Vector2f(window.getSize().x, window.getSize().y));
	Backgrnd.setFillColor(sf::Color::White);

	TicTacToe->InitGUI(gui);
	TicTacToe->setTurnFlag(true);

	
	std::vector<tgui::Button::Ptr> grid = TicTacToe->InitGameGrid(gui);
	
	sf::RectangleShape GridBoxBackground(sf::Vector2f(360, 360));
	GridBoxBackground.setPosition(sf::Vector2f(45, 95));
	GridBoxBackground.setFillColor(sf::Color::Black);

	int BranchesVisited=0, numberOfIterations=0;
	

	while (window.isOpen())
	{
		sf::Event eventHandle;
		while (window.pollEvent(eventHandle))
		{
			gui.handleEvent(eventHandle);
			if (eventHandle.type == sf::Event::Closed) {
				window.close();
			}
			
		}

		botPlayer->checkGameState(gui);

		if (!TicTacToe->isHumanTurn() && botPlayer->isGameOver() == 0) {

			botPlayer->resetBranchCounter();
			botPlayer->resetIterationCounter();

			int BestMove;
			if (TicTacToe->selectedAlgorithm(gui)) {			
				BestMove = botPlayer->findBestMoveAlphaBeta();

			}
			else {	
				BestMove = botPlayer->findBestMoveBrute();
			}
			BranchesVisited = botPlayer->getVisitedBranches();
			numberOfIterations = botPlayer->getIterationCounter();
			

			TicTacToe->setGridPlayValue(BestMove, TicTacToe->PLAYER_X);
			TicTacToe->setTurnFlag(true);

		
		}

		//int PlayerMove;
		//std::cin >> PlayerMove;
		//TicTacToe.setGridPlayValue(PlayerMove, TicTacToe.PLAYER_O);



		
		
		TicTacToe->updateGrid(grid);
		TicTacToe->uppdateStats(gui);

		

		window.clear();
		window.draw(Backgrnd);
		window.draw(GridBoxBackground);
		gui.draw();
		
		window.display();


	}


}