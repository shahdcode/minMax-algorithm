#include "Backtracking.h"



bool game::isDraw(char board[][COLS]){
    for(int i=0; i<ROWS;i++){
        for(int j=0; j<COLS; j++){
            if(board[i][j] == '_') return false;
        }
    }
    return true;
}

short game::playerToNumber(char player){
     switch (player)
        {
        case 'X':
            return 2;
            break;
        case 'O':
            return 1;
            break;
        default:
            return 0;
            break;
        }
}
std::pair<bool, int> game::checkIndex(char board[][COLS], std::pair<int,int>index, direction dir){
    int player = playerToNumber(board[index.first][index.second]);
        if(dir==direction::row){
            for(int i=index.first; i<ROWS-1;i++){
                if(board[0][i] != board[0][i+1]){
                    return std::make_pair(false, 0);
                }
            }         
        }
        else if(dir == direction::col){
            for(int i=index.second; i < COLS-1; i++){
                if(board[i][0] != board[i+1][0]){
                    return std::make_pair(false, 0);
                }
            }        
        }
        else if(dir == direction::diagonal){
            for(int i=index.first, j =index.second; i < ROWS-1 && j < COLS-1; i++, j++){
                if(board[i][j] != board[i+1][j+1]){
                    return std::make_pair(false, 0);
                }
            }
        }
        else{
            for(int i=index.first, j =index.second; i > 0 && j < COLS-1; i--, j++){
                if(board[i][j] != board[i-1][j+1]){
                    return std::make_pair(false, 0);
                }
                }
            
        }
        return std::make_pair(true, player);
}

int game::isGameOver(char board[ROWS][COLS]){           ////Add condition for Draw

    /*
        Player X: 2
        Player O: 1
        Draw: -1
        Game Not Over: 0
    */
    //check draw
    if(isDraw(board)) return -1;
    for(int i=0; i < ROWS; i ++){
        std::pair <bool,int> result = checkIndex(board, std::make_pair(i,0),direction::row);
        if(result.first) return result.second;
        
        result=checkIndex(board,std::make_pair(0,i),direction::col);
        if(i%4==0){
            result =checkIndex(board, std::make_pair(0,i),direction::diagonal);
             if(result.first) return result.second;
           
        
        }
        else{
            result =checkIndex(board, std::make_pair(0,i),direction::antiDiagonal);
            if(result.first) return result.second;
        }
        
    }
    return 0;
    
}


int game::minimax(char board[ROWS][COLS], int depth, bool isMaximizer){
    switch (isGameOver(board))
    {
    case 2:
        return 10+depth;
    case 1:
        return depth-10;
    case -1:             ////Check for number equivilant to Draw Condition
        return 0;

    }

    if(isMaximizer){        /////Change Hard Coded X and O to game::player and game::Computer
        int BestScore = INT_MIN;
        for(int i =0; i< ROWS; i++){
            for(int j=0; j < COLS; j++){
                if(board[i][j] == ' '){
                    board[i][j] = 'X';
                    int score = minimax(board, depth++, false);
                    board[i][j]=' ';
                    if(score > BestScore) BestScore = score;

                }
            }
        }
        return BestScore;
    }
    else{
        int BestScore = INT_MAX;
        for(int i=0; i < ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(board[i][j] == ' '){
                    board[i][j] = 'O';
                    int score = minimax(board, depth++, true);
                    board[i][j] = ' ';
                    if(score < BestScore) BestScore = score;
                }
            }
        }
        return BestScore;

    }


}



int game::evaluate(char board[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        if (board[row][0] == board[row][1] &&
            board[row][1] == board[row][2]) {
            if (board[row][0] == computer)
                return +10;
            else if (board[row][0] == player)
                return -10;
        }
    }

    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == board[1][col] &&
            board[1][col] == board[2][col]) {
            if (board[0][col] == computer)
                return +10;
            else if (board[0][col] == player)
                return -10;
        }
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        if (board[0][0] == computer)
            return +10;
        else if (board[0][0] == player)
            return -10;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        if (board[0][2] == computer)
            return +10;
        else if (board[0][2] == player)
            return -10;
    }

    return 0;
}


game::Move game::findBestMove(char board[ROWS][COLS]) {
    int bestVal = INT_MIN;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == '_') {
                board[i][j] = computer;
                int moveVal = minimax(board, 0, false);
                board[i][j] = '_';

                if (moveVal > bestVal) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}