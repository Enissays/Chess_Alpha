#include "Piece.h"

Piece::Piece(int id, int x, int y)
{
    this->id = id;
    pos.x = x;
    pos.y = y;

}

Piece::Piece()
{

}

Piece::~Piece()
{

}

Pos Piece::getPos()
{
    return pos;
}

void Piece::setPos(Pos pos, Board &board)
{
    this->pos = pos;
    board.setPiece(pos.x, pos.y, id);
}

void Piece::addPawnMoves(Pos mv, Board board)
{
    // check if there's at least a piece in front of the pawn
    if (board.table[pos.x][pos.y + (-1*board.turn)] == 0) {
        // check if the pawn is at the starting position
        if (pos.y == 1 || pos.y == 6) {
            // check if there's a piece 2 squares in front of the pawn
            if (board.table[pos.x][pos.y + (-2*board.turn)] == 0) {
                moves.push_back({pos.x, pos.y + (-2*board.turn)});
            }
        }
        moves.push_back({pos.x, pos.y + (-1*board.turn)});
    }

    // check if there's an ennemy piece on the four diagonal squares
    if (pos.x != 0) {
        if (board.table[pos.x - 1][pos.y + (-1*board.turn)] != 0) {
            if (!board.checkTurn(board.table[pos.x - 1][pos.y + (-1*board.turn)])) {
                kills.push_back({pos.x - 1, pos.y + (-1*board.turn)});
            }
        }
    } 
    if (pos.x != 7) {
        if (board.table[pos.x + 1][pos.y + (-1*board.turn)] != 0) {
            if (!board.checkTurn(board.table[pos.x + 1][pos.y + (-1*board.turn)])) {
                kills.push_back({pos.x + 1, pos.y + (-1*board.turn)});
            }
        }
    }
}

void Piece::addRookMoves(Pos mv, Board board)
{
        // Rook

    for (int i = pos.y+1; i < 8; i++) {
        Pos move1 = {pos.x, i};
        if (board.table[move1.x][move1.y] == 0){
            moves.push_back(move1);
        } else 
        {
            if (!board.checkTurn(board.table[move1.x][move1.y])) {
                kills.push_back(move1);
            }
            break;
        }
    }

    for (int i = pos.x+1; i < 8; i++) {
        Pos move1 = {i, pos.y};
        if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
            moves.push_back(move1);
        } else 
        {
            if (!board.checkTurn(board.table[move1.x][move1.y])) {
                kills.push_back(move1);
            }
            break;
        }
    }

    for (int i = pos.x-1; i >= 0 ; i--) {
        Pos move1 = {i, pos.y};
        if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
            moves.push_back(move1);
        } else 
        {
            if (!board.checkTurn(board.table[move1.x][move1.y])) {
                kills.push_back(move1);
            }
            break;
        }
    }

    for (int i = pos.y-1; i >= 0 ; i--) {
        Pos move1 = {pos.x, i};
        if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
            moves.push_back(move1);
        } else {
            if (!board.checkTurn(board.table[move1.x][move1.y])) {
                kills.push_back(move1);
            }
            break;
        }
    }
            
}

void Piece::addKnightMoves(Pos pos, Board board)
{
    moves.push_back({pos.x + 1, pos.y + 2});
    moves.push_back({pos.x + 1, pos.y - 2});
    moves.push_back({pos.x - 1, pos.y + 2});
    moves.push_back({pos.x - 1, pos.y - 2});
    moves.push_back({pos.x + 2, pos.y + 1});
    moves.push_back({pos.x + 2, pos.y - 1});
    moves.push_back({pos.x - 2, pos.y + 1});
    moves.push_back({pos.x - 2, pos.y - 1});

    // remove the moves that are out of the board and the moves that are blocked by other pieces
    for (int i = 0; i < moves.size(); i++) {
    if (moves[i].x < 0 || moves[i].x > 7 || moves[i].y < 0 || moves[i].y > 7) 
    {
            moves.erase(moves.begin() + i);
            i--;
        } else if (board.table[moves[i].x][moves[i].y] != 0) {
            if (board.checkTurn(board.table[moves[i].x][moves[i].y])) kills.push_back(moves[i]);
            moves.erase(moves.begin() + i);
            i--;
        }
    }
}

void Piece::addBishopMoves(Pos pos, Board board)
{
    for (int i = 0; i < 8; i++) {
        Pos move1 = {pos.x + i + 1, pos.y + i + 1};
        if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0 && board.table[move1.x][move1.y] == 0) {
            moves.push_back(move1);
        } else 
        {
            if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            break;
        }
    }

    for (int i = 0; i < 8; i++) {
        Pos move1 = {pos.x + i + 1, pos.y - i - 1};
        if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0 && board.table[move1.x][move1.y] == 0) {
            moves.push_back(move1);
        } else {
            if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            break;
        }
    }

    for (int i = 0; i < 8; i++) {
        Pos move1 = {pos.x - i - 1, pos.y + i + 1};
        if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0 && board.table[move1.x][move1.y] == 0) {
            moves.push_back(move1);
        } else 
        {
            if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            break;
        }
    }

    for (int i = 0; i < 8; i++) {
        Pos move1 = {pos.x - i - 1, pos.y - i - 1};
        if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0 && board.table[move1.x][move1.y] == 0) {
            moves.push_back(move1);
        } else {
            if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            break;
        }
    }
}

void Piece::addQueenMoves(Pos pos, Board board)
{
    addRookMoves(pos, board);
    addBishopMoves(pos, board);
}

void Piece::getMoves(Board board)
{
    int check_id = id;
    if (id < 0) check_id = -id;

    switch(check_id) {
        case 1:
            addPawnMoves(pos, board);
        break;
        case 2:
            // Rook
            addRookMoves(pos, board);
        break;
        case 3:
            // Knight
            addKnightMoves(pos, board);
            break;
        case 4:
            // Bishop
            addBishopMoves(pos, board);
            break;
        case 5:
            // Queen
            addQueenMoves(pos, board);
            break;
        case 6:
            // King

            break;
        default:
            break;
    }
}

bool Piece::checkMove(Pos move, Board board)
{
    for (int i = 0; i < moves.size(); i++) {
        if (moves[i].x == move.x && moves[i].y == move.y) return true;
    }
    return false;
}

int Piece::getId()
{
    return id;
}