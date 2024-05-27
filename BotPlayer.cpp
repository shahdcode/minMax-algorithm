#include "BotPlayer.h"



int BotPlayer::isGameOver()
{
    std::vector<std::vector<int>> winning_combinations = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columns
        {0, 4, 8}, {2, 4, 6}  // diagonals
    };

    for (const auto& combination : winning_combinations) {
        if (gameGrid[combination[0]] == gameGrid[combination[1]] && gameGrid[combination[1]] == gameGrid[combination[2]] && gameGrid[combination[0]] != EMPTY)
            return gameGrid[combination[0]] == "X" ? 2 : 1;
    }

    if (find(gameGrid.begin(), gameGrid.end(), EMPTY) == gameGrid.end())
        return -1;

    return 0;
}

int BotPlayer::minimaxBrute(int depth, bool isMaximizer)
{
    BranchCount++;
    short gameState = isGameOver();
    switch (gameState)
    {
    case 2:
        return 10 - depth;
    case 1:
        return depth - 10;
    case -1:             ////Check for number equivilant to Draw Condition
        return 0;

    }

    if (isMaximizer) {        /////Change Hard Coded X and O to game::player and game::Computer
        int BestScore = INT_MIN;
        
            for (int i = 0; i < 9; i++) {
                NumberOfIteration++;
                if (gameGrid[i] == EMPTY) {
                    gameGrid[i] = PLAYER_X;
                    int score = minimaxBrute(depth + 1, false);
                    gameGrid[i] = EMPTY;
                    BestScore = std::max(BestScore, score);

                }
            }
        
        return BestScore;
    }
    else {
        int BestScore = INT_MAX;
        for (int i = 0; i < 9; i++) {
            NumberOfIteration++;
           if (gameGrid[i] == EMPTY) {
                gameGrid[i] = PLAYER_O;
                int score = minimaxBrute(depth + 1, true);
                gameGrid[i] = EMPTY;
                BestScore = std::min(BestScore, score);
                
           }
        }
        return BestScore;

    }


}

int BotPlayer::findBestMoveBrute()
{
    int bestScore = INT_MIN;
    int bestMove = -1;

    for (int i = 0; i < 9; ++i) {
        NumberOfIteration++;
        if (gameGrid[i] == EMPTY) {
            gameGrid[i] = PLAYER_X;
            int moveScore = minimaxBrute(0,false);
            gameGrid[i] = EMPTY;

            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    
    return bestMove;
}

int BotPlayer::minimaxAlphaBeta(int depth, int alpha, int beta, bool maximizingPlayer)
{
    BranchCount++;
    short gameState = isGameOver();
    switch (gameState)
    {
    case 2:
        return  10 ;
    case 1:
        return -10;
    case -1:             ////Check for number equivilant to Draw Condition
        return 0;
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        for (int i = 0; i < 9; ++i) {
            NumberOfIteration++;
            if (gameGrid[i] == EMPTY) {
                gameGrid[i] = PLAYER_X;
                int evalScore = minimaxAlphaBeta(depth - 1, alpha, beta, false);
                gameGrid[i] = EMPTY;
                maxEval = std::max(maxEval, evalScore);
                alpha = std::max(alpha, evalScore);
                if (beta <= alpha)
                    break;
            }
        }
        return maxEval;
    }
    else {
        int minEval = INT_MAX;
        for (int i = 0; i < 9; ++i) {
            NumberOfIteration++;
            if (gameGrid[i] == EMPTY) {
                gameGrid[i] = PLAYER_O;
                int evalScore = minimaxAlphaBeta(depth - 1, alpha, beta, true);
                gameGrid[i] = EMPTY;
                minEval = std::min(minEval, evalScore);
                beta = std::min(beta, evalScore);
                if (beta <= alpha)
                    break;
            }
        }
        return minEval;
    }
}

int BotPlayer::findBestMoveAlphaBeta()
{
    std::cout << "Finding Best Move!\n";
    int bestScore = INT_MIN;
    int bestMove = -1;

    for (int i = 0; i < 9; ++i) {
        NumberOfIteration++;
        if (gameGrid[i] == EMPTY) {
            gameGrid[i] = PLAYER_X;
            int moveScore = minimaxAlphaBeta(9, INT_MIN, INT_MAX, false);
            gameGrid[i] = EMPTY;

            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    std::cout << "Found Best Move at " << bestMove << '\n';
    return bestMove;
}

void BotPlayer::checkGameState(tgui::GuiSFML& gui)
{

    int gameState = isGameOver();
    auto Label = gui.get<tgui::Label>("SM-GS");
    if (gameState == 2) {
        Label->setText("The Computer Won...You Loose:(");

    }
    else if (gameState == 1) {
        Label->setText("You WON...Wait How is this possible");

    }
    else if (gameState == -1) {
        Label->setText("It's a Draw...");

    }
    else {
        Label->setText("");
    }
}
