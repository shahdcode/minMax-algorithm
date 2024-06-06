#include "Game.h"


std::vector<std::string> Game::gameGrid = { "_", "_", "_", "_", "_", "_", "_", "_", "_" };
int Game::BranchCount = 0;
int Game::NumberOfIteration = 0;
bool Game::AlgoInUse = 0;

Game::Game()
{
	//gameGrid = { "_", "_", "_", "_", "_", "_", "_", "_", "_" };
}
bool Game::selectedAlgorithm(tgui::Gui& gui) { //0 For Brute Force and 1 for Alpha Beta

	auto RB_BF = gui.get<tgui::RadioButton>("RB-BF");
	
	return !RB_BF->isChecked();

}

void Game::InitGUI(tgui::GuiSFML& gui) ///Keep Adding GUI Elements and Find way to change the 2d Array to a 1d array
{										///YOU GOT THIS YOU JUST WENT TO SLEEP AND NOT A COMA...SA7SA7 KDA
	
	tgui::Label::Ptr Title = tgui::Label::create();
	Title->setText("Tic Tac Toe - BOT");
	Title->setTextSize(28);
	Title->setPosition(470, 40);
	gui.add(Title);

	tgui::SeparatorLine::Ptr titleSep1 = tgui::SeparatorLine::create();
	titleSep1->setPosition(450, 100);
	titleSep1->setWidth(Title->getSize().x + 50);
	gui.add(titleSep1);

	tgui::Label::Ptr Sec1_SH = tgui::Label::create();
	Sec1_SH->setText("Choose Solving Approach:");
	Sec1_SH->setTextSize(16);
	Sec1_SH->setPosition(450, 130);
	gui.add(Sec1_SH);

	tgui::RadioButton::Ptr BruteForce = tgui::RadioButton::create();
	BruteForce->setPosition(460, 155);
	BruteForce->setText("Brute Force Approach");
	BruteForce->setWidgetName("RB-BF");
	BruteForce->setChecked(true);
	gui.add(BruteForce);

	tgui::RadioButton::Ptr AlphaBeta = tgui::RadioButton::create();
	AlphaBeta->setPosition(460, 185);
	AlphaBeta->setText("Alpha-Beta Approach");
	AlphaBeta->setWidgetName("RB-AB");
	gui.add(AlphaBeta);

	tgui::RadioButtonGroup::Ptr AlgoSelectGroup = tgui::RadioButtonGroup::create();
	AlgoSelectGroup->add(BruteForce);
	AlgoSelectGroup->add(AlphaBeta);
	gui.add(AlgoSelectGroup);

	tgui::SeparatorLine::Ptr titleSep2 = tgui::SeparatorLine::create();
	titleSep2->setPosition(450, 220);
	titleSep2->setWidth(Title->getSize().x + 50);
	gui.add(titleSep2);


	tgui::Label::Ptr statHeading = tgui::Label::create("Stats About Last Play by Computer");
	statHeading->setWidgetName("APP-H1");   //Selected Approach heading 1
	statHeading->setPosition(450, 240);
	statHeading->setTextSize(16);
	gui.add(statHeading);

	tgui::Label::Ptr approachSelect = tgui::Label::create("Brute Force");
	approachSelect->setWidgetName("SEL-APP-H1");   //Selected Approach heading 1
	approachSelect->setPosition(460, 270);
	approachSelect->setTextSize(18);
	gui.add(approachSelect);

	tgui::Label::Ptr approachStats = tgui::Label::create();
	approachStats->setWidgetName("SEL-APP-STAT");
	approachStats->setPosition(460, 320);
	approachStats->setTextSize(14);
	gui.add(approachStats);


	tgui::Label::Ptr GameStatus = tgui::Label::create();
	GameStatus->setTextSize(26);
	GameStatus->setPosition(100, 500);
	GameStatus->getRenderer()->setTextStyle(tgui::TextStyle::Bold);
	GameStatus->setWidgetName("SM-GS");		///SM-GS --> Status Message - Game State
	gui.add(GameStatus);

	tgui::ChildWindow::Ptr InfoWindow = tgui::ChildWindow::create("Info About Solving Algorithms");
	InfoWindow->setSize(400, 450);
	InfoWindow->setResizable(false);

	auto InfoLabel1 = tgui::Label::create("Tic Tac Toe Solver");
	InfoLabel1->setTextSize(22);
	InfoLabel1->setPosition(40, 40);
	InfoLabel1->getRenderer()->setTextStyle(tgui::TextStyle::Bold | tgui::TextStyle::Underlined);

	auto InfoPara1 = tgui::Label::create("This is a Tic Tac Toe \"BOT\" than can Play the game tic tac toe against human players and never loose(We hope so).\n\n\nThe Bot Can Play Against Humans Leveraging the MiniMax Algorithm. The Algorithm was implemented in 2 different approches: Good Old Brute Force and an of it Using Alpha beta (Read our Paper -link below- for more Info).\n\n\nThe MiniMax Algorithm finds The Best/Most optimum play for it's turn by Calculating all possible states of the Game from the current State of the Board trying to pick the move that maximizes it's chances of winning and avoiding the paths that can give the opponent an advantage in winning hence minimizing the opponent's chance of winning.\n\n\nThe Brute Force Approach of the minimax Algorithm can find the most efficient play for it's turn with time complexity: O(n^n).\n\n\nThe Alpha Beta pruning Approach implementation on the other hand acheives Lower time complexity although it has the same worst case complexity (O(n^n)) However it never reaches this high complexity as it usually excludes branches/paths early on during the search for the best Path/move for Maximizing it's chance of Winning.\n");
	InfoPara1->setTextSize(16);
	InfoPara1->setSize(320, 300);
	InfoPara1->setPosition(50, 100);
	
	
	InfoWindow->add(InfoLabel1);
	InfoWindow->add(InfoPara1);

	//InfoWindow->loadWidgetsFromFile("InfoSec1-model.txt");
	
	

	
	//gui.add(InfoWindow);

	tgui::Button::Ptr InfoShowButton = tgui::Button::create("More Info!");
	InfoShowButton->setPosition(450, 550);
	InfoShowButton->onClick([InfoWindow, &gui] {
		gui.add(InfoWindow);
		});
	gui.add(InfoShowButton);

	tgui::ChildWindow::Ptr creditsWindow = tgui::ChildWindow::create("Credits to Project Creators");
	creditsWindow->setSize(250, 160);
	creditsWindow->setResizable(false);

	tgui::Label::Ptr CreditsTitle = tgui::Label::create("Project Contributers: ");
	CreditsTitle->setPosition(5, 5);
	CreditsTitle->setTextSize(18);
	creditsWindow->add(CreditsTitle);

	tgui::Label::Ptr Credits = tgui::Label::create("Daniel Michel: 2022/02556\nShahd Emad: 2022/02743 \nSara Diaa: 2022/01921\nHabibba Darwish: 2022/06738\n");
	Credits->setPosition(15, 30);
	creditsWindow->add(Credits);


	tgui::Button::Ptr creditsShowButton = tgui::Button::create("Credits");
	creditsShowButton->setPosition(550, 550);
	creditsShowButton->onClick([creditsWindow, &gui] {
		gui.add(creditsWindow);
		});
	gui.add(creditsShowButton);


	tgui::Button::Ptr ResetGameBtn = tgui::Button::create("Restart Game");
	ResetGameBtn->setPosition(650, 520);
	ResetGameBtn->setSize(120, 70);
	ResetGameBtn->onClick([this,&gui] {
		resetGame();
		setTurnFlag(true);
	});
	gui.add(ResetGameBtn);

}

std::vector<tgui::Button::Ptr> Game::InitGameGrid(tgui::GuiSFML& gui)
{
	std::vector<tgui::Button::Ptr> grid;

	int YLocGrid = 100;
	int XLocGrid = 50;

	for (int i = 1; i <= 9; i++) {

		auto gb = tgui::Button::create();
		gb->setSize(110, 110);
		gb->getRenderer()->setBackgroundColor(sf::Color::White);
		gb->getRenderer()->setBorderColor(sf::Color::Black);
		gb->getRenderer()->setBorders(2);
		gb->setTextSize(40);
		const int map = i - 1;
		gb->onClick([map,this] {
			if (isHumanTurn()) {
				setGridPlayValue(map, PLAYER_O);
				HumanTurn = false;
			}
		});

		gui.add(gb);
		gb->setPosition(XLocGrid, YLocGrid);
		XLocGrid += gb->getSize().x + 10; //Width of GridBox + 10

		grid.push_back(gb);
		if (i % 3 == 0) {
			YLocGrid += gb->getSize().y + 10; //Height of GridBox + 10
			XLocGrid = 50;
		}
	}
	return grid;
}

void Game::updateGrid(std::vector<tgui::Button::Ptr> Grid)
{
	for (int i = 0; i < 9; i++) {

		if (gameGrid[i] == PLAYER_X) {
			Grid[i]->setText("X");
			Grid[i]->setEnabled(false);
		}
		else if (gameGrid[i] == PLAYER_O) {
			Grid[i]->setText("O");
			Grid[i]->setEnabled(false);
		}
		else {
			Grid[i]->setText(" ");
			Grid[i]->setEnabled(true);
		}
	}
}

void Game::uppdateStats(tgui::GuiSFML& gui)
{
	auto statSec = gui.get<tgui::Label>("SEL-APP-H1");
	
	if (!selectedAlgorithm(gui)) {
		statSec->setText("Brute Force Approach in Use.");
	}
	else {
		statSec->setText("Alpha Beta Approach in Use.");
	}

	std::string stats = "Last Play done in " +std::to_string(getIterationCounter()) + " Iterations\n\n" + std::to_string(getVisitedBranches()) + " Branches visited\n";
	//std::cout << "----->" << getIterationCounter() <<" + "<< getVisitedBranches() << '\n';
	//std::cout << stats;
	gui.get<tgui::Label>("SEL-APP-STAT")->setText(stats);

	
}



void Game::setTurnFlag(bool flagVal)
{
	HumanTurn = flagVal;
}

bool Game::isHumanTurn()
{
	return HumanTurn;
}

void Game::setGridPlayValue(int index, std::string player)
{
	gameGrid[index] = player;
}

void Game::resetGame()
{
	for (int i = 0; i < 9; i++) {
		gameGrid[i] = "_";
	}
	
}



//void Game::printBoard()
//{
//	{
//		std::cout << "---------" << '\n';
//		for (int i = 0; i < 3; ++i) {
//			std::cout << "| " << gameGrid[i * 3] << " | " << gameGrid[i * 3 + 1] << " | " << gameGrid[i * 3 + 2] << " |" << '\n';
//			std::cout << "---------\n";
//		}
//	}
//}


int Game::getVisitedBranches()
{
	return BranchCount;
}

void Game::resetBranchCounter()
{
	BranchCount = 0;
}

int Game::getIterationCounter()
{
	return NumberOfIteration;
}

void Game::resetIterationCounter()
{
	NumberOfIteration = 0;
}