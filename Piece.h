#ifndef PIECE_H
#define PIECE_H

#pragma once
#include<vector>
#include"Board.h"


class Piece
{
public:
    Piece(int, int, int);
    Piece();
    ~Piece();
    Pos getPos();
    int getId();
    void setPos(Pos, Board&);
    bool checkMove(Pos, Board);

    // Function for each type of piece that adds the possible moves to the vector
    void addPawnMoves(Pos, Board);
    void addRookMoves(Pos, Board);
    void addKnightMoves(Pos, Board);
    void addBishopMoves(Pos, Board);
    void addQueenMoves(Pos, Board);
    void addKingMoves(Pos, Board);
    void getMoves(Board);
    void showMoves(Board);

    // Function to get all moves of a board
    vector<Pos> getAllMovesE(Board);
private:
    Pos pos;
    int id;
    std::vector <Pos> moves;
    std::vector <Pos> kills;
    friend void showMoves(Piece, Board);
    friend class Board;
};

#include"Piece.cpp"
#endif