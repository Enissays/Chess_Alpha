#include "Board.h"

// the chess board initialization
Board::Board()
{
    // initialize the board, positive if white, negative if black, 0 if empty
    /*table = 
    { 
        {-2, -1, 0, 0, 0, 0, 1, 2},
        {-3, -1, 0, 0, 0, 0, 1, 3},
        {-4, -1, 0, 0, 0, 0, 1, 4},
        {-5, -1, 0, 0, 0, 0, 1, 5},
        {-6, -1, 0, 0, 0, 0, 1, 6},
        {-4, -1, 0, 0, 0, 0, 1, 4},
        {-3, -1, 0, 0, 0, 0, 1, 3},
        {-2, -1, 0, 0, 0, 0, 1, 2}
    };*/
    table = 
    { 
        {-2, -1, 0, 0, 0, 0, 1, 2},
        {-3, -1, 0, 0, 0, 0, 1, 3},
        {-4, -1, 0, 1, 0, 0, 1, 4},
        {-5, -1, 0, 0, 0, 0, 1, 5},
        {-6, -1, 0, 0, 0, 0, 1, 6},
        {-4, -1, 0, 0, 0, 0, 1, 4},
        {-3, -1, 0, 0, 0, 0, 1, 3},
        {-2, -1, 0, 0, 0, 0, 1, 2}
    };
}


void Board::switchTurn()
{
    turn = -turn;
}

Board::~Board()
{

}

int Board::getPiece(int x, int y)
{
    return table[x][y];
}

int Board::getTurn()
{
    return turn;
}

void Board::setPiece(int x, int y, int id)
{
    table[x][y] = id;
}

bool Board::checkTurn(int id)
{
    if (id > 0 && turn == 1) {
        return 1;
    }
    else if (id < 0 && turn == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

