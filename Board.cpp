#include "Board.h"

// the chess board initialization
Board::Board()
{
    // initialize the board, positive if white, negative if black, 0 if empty
    table = {
        {-2, -3, -4, -5, -6, -4, -3, -2},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {2, 3, 4, 5, 6, 4, 3, 2}
    };
}

void Board::switchTurn()
{
    turn *= -1;
}

Board::~Board()
{

}

int Board::getPiece(int x, int y)
{
    return table[x][y];
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