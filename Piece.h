#ifndef PIECE_H
#define PIECE_H

#pragma once
#include<vector>
#include"Board.h"
struct Pos
{
    int x;
    int y;
};

class Piece
{
public:
    Piece(int);
    Piece();
    ~Piece();
    Pos getPos();
    void setPos(Pos);
    std::vector <Pos> getMoves(Board);
    bool checkMove(Pos, Board);
private:
    Pos pos;
    int id;

};

#include"Piece.cpp"
#endif