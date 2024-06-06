#pragma once
#include <TGUI/TGUI.hpp>
#include <vector>

class Game
{
private:
	bool HumanTurn = true;
protected:
	 static std::vector<std::string> gameGrid;
	 static bool AlgoInUse;


	 
public:
	static int BranchCount;
	static int NumberOfIteration;


	const std::string PLAYER_O = "O";
	const std::string EMPTY = "_";
	const std::string PLAYER_X = "X";

	Game();
	void InitGUI(tgui::GuiSFML& gui);
	std::vector<tgui::Button::Ptr> InitGameGrid(tgui::GuiSFML& gui);
	void updateGrid(std::vector<tgui::Button::Ptr> Grid);
	bool selectedAlgorithm(tgui::Gui& gui);
	void uppdateStats(tgui::GuiSFML& gui);
	void setTurnFlag(bool flagVal);
	bool isHumanTurn();
	void setGridPlayValue(int index, std::string player);
	void resetGame();
	
	int getVisitedBranches();
	void resetBranchCounter();
	int getIterationCounter();
	void resetIterationCounter();


	void printBoard();
};

