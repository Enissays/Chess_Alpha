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
    bool checkMove(Pos, Board);

    // Function for each type of piece that adds the possible moves to the vector
    void addPawnMoves(Pos, Board);
    void addRookMoves(Pos, Board);
    void addKnightMoves(Pos, Board);
    void addBishopMoves(Pos, Board);
    void addQueenMoves(Pos, Board);
    void addKingMoves(Pos, Board);
    void getMoves(Board);

private:
    Pos pos;
    int id;
    std::vector <Pos> moves;
    std::vector <Pos> kills;

};

#include"Piece.cpp"
#endif