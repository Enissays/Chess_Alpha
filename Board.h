#ifndef BOARD_H
#define BOARD_H

#pragma once

struct Pos
{
    int x;
    int y;
};

#include<vector>
#include <utility>

// The chess board
class Board
{
public:
    Board();
    ~Board();
    void switchTurn();
    int getTurn();
    int getPiece(int, int);
    void setPiece(int, int, int);
    bool checkTurn(int);
private:
    // The board
    std::vector<std::vector<int>> table;
    int turn = 1;
    friend class Piece;
    friend void displayBoard(Board);
    friend void showMoves(Board);
    std::pair<int, Pos> p_one_pieces[16];
};

#include"Board.cpp"
#endif