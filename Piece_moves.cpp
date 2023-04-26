#include"Piece.h"

void Piece::addPawnMoves(Pos mv, Board board, bool checks)
{
    if (!checks) 
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
    

    // check if the en passant square is in the pawn's range
    if (board.en_passant_killed.x == pos.x + 1 || board.en_passant_killed.x == pos.x - 1) {
        if (board.en_passant_killed.y == pos.y + (-1*board.turn)) {
            kills.push_back({board.en_passant_killed.x, board.en_passant_killed.y});
        }
    }
    }

    // check if there's an ennemy piece on the four diagonal squares
    if (pos.x != 0) {
        if (board.table[pos.x - 1][pos.y + (-1*board.turn)] != 0) {
            if (!board.checkTurn(board.table[pos.x - 1][pos.y + (-1*board.turn)])) {
                if (checks) moves.push_back({pos.x - 1, pos.y + (-1*board.turn)});
                else
                kills.push_back({pos.x - 1, pos.y + (-1*board.turn)});
            }
        }
    }
    if (pos.x != 7) {
        if (board.table[pos.x + 1][pos.y + (-1*board.turn)] != 0) {
            if (!board.checkTurn(board.table[pos.x + 1][pos.y + (-1*board.turn)])) {
                if (checks) moves.push_back({pos.x + 1, pos.y + (-1*board.turn)});
                else
                kills.push_back({pos.x + 1, pos.y + (-1*board.turn)});
            }
        }
    }
}

void Piece::addRookMoves(Pos mv, Board board, bool checks)
{
        // Rook

    for (int i = pos.y+1; i < 8; i++) {
        Pos move1 = {pos.x, i};
        if (board.table[move1.x][move1.y] == 0){
            moves.push_back(move1);
        } else 
        {

            if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            if (checks) moves.push_back(move1);
            break;
        }
    }

    for (int i = pos.x+1; i < 8; i++) {
        Pos move1 = {i, pos.y};
        if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
            moves.push_back(move1);
        } 
        else 
        {
            if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            if (checks) moves.push_back(move1);
            break;
        }
    }

    for (int i = pos.x-1; i >= 0 ; i--) {
        Pos move1 = {i, pos.y};
        if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
            moves.push_back(move1);
        } 
        else 
        {
            if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            if (checks) moves.push_back(move1);
            
            break;
        }
    }

    for (int i = pos.y-1; i >= 0 ; i--) {
        Pos move1 = {pos.x, i};
        if (board.table[move1.x][move1.y] == 0 && move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) {
            moves.push_back(move1);
        } else {
            if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            if (checks) moves.push_back(move1);
            break;
        }
    }
            
}

void Piece::addKnightMoves(Pos pos, Board board, bool checks)
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
    } else if (!checks && board.table[moves[i].x][moves[i].y] != 0) {
            if (board.checkTurn(board.table[moves[i].x][moves[i].y])) kills.push_back(moves[i]);
            moves.erase(moves.begin() + i);
            i--;
        }
    }
}

void Piece::addBishopMoves(Pos pos, Board board, bool checks)
{
    for (int i = 0; i < 8; i++) {
        Pos move1 = {pos.x + i + 1, pos.y + i + 1};
        if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0 && board.table[move1.x][move1.y] == 0) {
            moves.push_back(move1);
        } 
            else 
        {
            if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) 
            {
                if (checks) moves.push_back(move1);
                else if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            }
            break;
        }
    }

    for (int i = 0; i < 8; i++) {
        Pos move1 = {pos.x + i + 1, pos.y - i - 1};
        if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0 && board.table[move1.x][move1.y] == 0) {
            moves.push_back(move1);
        } else {
            if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) 
            {
                if (checks) moves.push_back(move1);
                else if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            }
            break;
        }
    }

    for (int i = 0; i < 8; i++) {
        Pos move1 = {pos.x - i - 1, pos.y + i + 1};
        if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0 && board.table[move1.x][move1.y] == 0) {
            moves.push_back(move1);
        } 
            else 
        {
            if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) 
            {
                if (checks) moves.push_back(move1);
                else if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            }
            break;
        }
    }

    for (int i = 0; i < 8; i++) {
        Pos move1 = {pos.x - i - 1, pos.y - i - 1};
        if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0 && board.table[move1.x][move1.y] == 0) {
            moves.push_back(move1);
        } else {
            if (move1.x <= 7 && move1.x >= 0 && move1.y <= 7 && move1.y >= 0) 
            {
                if (checks) moves.push_back(move1);
                else if (!board.checkTurn(board.table[move1.x][move1.y])) kills.push_back(move1);
            }
            break;
        }
    }
}

void Piece::addQueenMoves(Pos pos, Board board, bool checks)
{
    addRookMoves(pos, board, checks);
    addBishopMoves(pos, board, checks);
}

void Piece::addKingMoves(Pos pos, Board board, bool checks)
{
    moves.push_back({pos.x + 1, pos.y + 1});
    moves.push_back({pos.x + 1, pos.y - 1});
    moves.push_back({pos.x - 1, pos.y + 1});
    moves.push_back({pos.x - 1, pos.y - 1});
    moves.push_back({pos.x + 1, pos.y});
    moves.push_back({pos.x - 1, pos.y});
    moves.push_back({pos.x, pos.y + 1});
    moves.push_back({pos.x, pos.y - 1});

    // remove the moves that are out of the board and the moves that are blocked by other pieces
    for (int i = 0; i < moves.size(); i++) {
        if (moves[i].x < 0 || moves[i].x > 7 || moves[i].y < 0 || moves[i].y > 7) 
        {
            moves.erase(moves.begin() + i);
            i--;
        } else if (board.table[moves[i].x][moves[i].y] != 0) {
            if (!board.checkTurn(board.table[moves[i].x][moves[i].y])) kills.push_back(moves[i]);
            moves.erase(moves.begin() + i);
            i--;
        }
    }

    if (!checks) 
    {
        vector<Pos> all_moves = getAllMovesE(board);
        for (int i = 0; i < all_moves.size(); i++) {
            for (int j = 0; j < moves.size(); j++) {
                if (all_moves[i].x == moves[j].x && all_moves[i].y == moves[j].y) {
                    moves.erase(moves.begin() + j);
                    j--;
                }
            }
        }
        // remove the kill moves that can be accessed by other pieces
        for (int i = 0; i < kills.size(); i++) {
            for (int j = 0; j < all_moves.size(); j++) {
                if (all_moves[j].x == kills[i].x && all_moves[j].y == kills[i].y) {
                    kills.erase(kills.begin() + i);
                    i--;
                    break;
                }
            }
        }
    }
    
    // Add king castling moves if the way is clear
    if (board.table[5][pos.y] == 0 && board.table[6][pos.y] == 0 && (board.getTurn() == 1 ? board.petit_roque_B : board.petit_roque_N)) {
        moves.push_back({6, pos.y});
    }
    if (board.table[3][pos.y] == 0 && board.table[2][pos.y] == 0 && board.table[1][pos.y] == 0 && (board.getTurn() == 1 ? board.grand_roque_B : board.grand_roque_N)) {
        moves.push_back({2, pos.y});
    }
}