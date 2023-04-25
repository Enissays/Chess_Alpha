#ifndef BOARD_H
#define BOARD_H

#include"Piece.h"

#pragma once
struct Pos
{
    int x;
    int y;
};

#include <algorithm>
#include<vector>
#include <utility>

using namespace std;
class Piece;
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
    bool getCheckMate();
private:
    // The board
    vector<vector<int>> table;
    int turn = 1;
    friend class Piece;
    friend void displayBoard(Board);
    friend void showMoves(Board);
    bool petit_roque_B = 1;
    bool grand_roque_B = 1;
    bool petit_roque_N = 1;
    bool grand_roque_N = 1;

    bool n_check=false;
    bool b_check=false;

    Pos en_passant = { -1,-1 };
    Pos en_passant_killed = { -1,-1 };
    int en_passant_id = 0;
    int count = 0;

    bool checkMate = false;
};

#include"Board.cpp"
#endif