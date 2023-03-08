#include "Piece.h"

Piece::Piece(int id)
{
    this->id = id;
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

void Piece::setPos(Pos pos)
{
    this->pos = pos;
}

std::vector <Pos> Piece::getMoves(Board board)
{
    std::vector <Pos> moves;
    switch(id) {
        case 1:
            // Pawn
            // Si le pion est sur la ligne 2 ou 7, il peut avancer de 2 cases
            if (pos.y == 1 || pos.y == 6) {
                Pos move1 = {pos.x, pos.y + 1*board.turn};
                Pos move2 = {pos.x, pos.y + 2*board.turn}; 
                // Vérifie si les cases sont vides
                if (board.table[move1.x][move1.y] == 0) {
                    moves.push_back(move1);
                    moves.push_back(move2);
                }
            } else {
                // Sinon, il ne peut avancer que d'une case
                Pos move1 = {pos.x, pos.y + 1*board.turn};
                // Vérifie si la case est vide
                if (board.table[move1.x][move1.y] == 0 ) moves.push_back(move1);
            }
            break;
        case 2:
            // Rook
            for (int i = pos.y; i < 8; i++) {
                Pos move1 = {pos.x, i};
                if (board.table[move1.x][move1.y] == 0) {
                    moves.push_back(move1);
                } else break;
            }

            for (int i = pos.x; i < 8; i++) {
                Pos move1 = {i, pos.y};
                if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
                    moves.push_back(move1);
                } else break;
            }

            for (int i = pos.x; i >= 0 ; i--) {
                Pos move1 = {i, pos.y};
                if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
                    moves.push_back(move1);
                } else break;
            }

            for (int i = pos.y; i >= 0 ; i--) {
                Pos move1 = {pos.x, i};
                if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
                    moves.push_back(move1);
                } else break;
            }
            
            break;
        case 3:
            // Knight
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
                if (moves[i].x < 0 || moves[i].x > 7 || moves[i].y < 0 || moves[i].y > 7) {
                    moves.erase(moves.begin() + i);
                    i--;
                } else if (board.table[moves[i].x][moves[i].y] != 0) {
                    moves.erase(moves.begin() + i);
                    i--;
                }
            }

            break;
        case 4:
            // Bishop
            for (int i = 0; i < 8; i++) {
                Pos move1 = {pos.x + i, pos.y + i};
                if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
                    moves.push_back(move1);
                } else break;
            }

            for (int i = 0; i < 8; i++) {
                Pos move1 = {pos.x + i, pos.y - i};
                if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
                    moves.push_back(move1);
                } else break;
            }

            for (int i = 0; i < 8; i++) {
                Pos move1 = {pos.x - i, pos.y + i};
                if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
                    moves.push_back(move1);
                } else break;
            }

            for (int i = 0; i < 8; i++) {
                Pos move1 = {pos.x - i, pos.y - i};
                if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
                    moves.push_back(move1);
                } else break;
            }
            break;
        case 5:
            // Queen

            break;
        case 6:
            // King

            break;
        default:
            break;
    }
    return moves;
}

bool Piece::checkMove(Pos move, Board board)
{
    std::vector <Pos> moves = getMoves(board);
    for (int i = 0; i < moves.size(); i++) {
        if (moves[i].x == move.x && moves[i].y == move.y) return true;
    }
    return false;
}