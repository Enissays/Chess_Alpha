#ifndef BOARD_H
#define BOARD_H

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
};

#include"Board.cpp"
#endif