#include<iostream>
#include<string>
#include<vector>
#include"Board.h"
#include"Piece.h"

using namespace std;

#define RIGHT 1
#define LEFT -1
#define UP -1
#define DOWN 1



void displayBoard(Board board)
{
    cout << "Tour actuel : " << (board.getTurn() == 1 ? "blanc" : "\033[30m noir \033[0m") << endl << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // display the line number in red
            if (j == 0) {
                cout << "\033[31m" << 8 - i << "\033[0m ";
            }
            switch(board.table[j][i]) {
                // display the pieces, print in black all the black pieces
                case -1:
                    cout << "\033[30m" << "P" << "\033[0m";
                    break;
                case -2:
                    cout << "\033[30m" << "R" << "\033[0m";
                    break;
                case -3:
                    cout << "\033[30m" << "N" << "\033[0m";
                    break;
                case -4:
                    cout << "\033[30m" << "B" << "\033[0m";
                    break;
                case -5:
                    cout << "\033[30m" << "Q" << "\033[0m";
                    break;
                case -6:
                    cout << "\033[30m" << "K" << "\033[0m";
                    break;
                case 1:
                    cout << "P";
                    break;
                case 2:
                    cout << "R";
                    break;
                case 3:
                    cout << "N";
                    break;
                case 4:
                    cout << "B";
                    break;
                case 5:
                    cout << "Q";
                    break;
                case 6:
                    cout << "K";
                    break;
                case 10:
                    cout << "-";
                    break;
                default:
                    cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
    // display the column letters in blue
    cout << "\033[34m" << "  a b c d e f g h" << "\033[0m" << endl;
}

int convertFromLetterToNumber(char letter)
{
    return letter - 97;
}

int LetterToPiece(char letter)
{
    switch (letter) 
    {
        case 'P':
            return 1;
        case 'R':
            return 2;
        case 'N':
            return 3;
        case 'B':
            return 4;
        case 'Q':
            return 5;
        case 'K':
            return 6;
        case 'p':
            return -1;
        case 'r':
            return -2;
        case 'n':
            return -3;
        case 'b':
            return -4;
        case 'q':
            return -5;
        case 'k':
            return -6;
        default:
            return 0;
    }
}

void showMoves(Piece piece, Board board)
{
    // change the piece id to 10 to show the moves
    for (int i = 0; i < piece.moves.size(); i++) {
        board.setPiece(piece.moves[i].x, piece.moves[i].y, 10);
    }
    displayBoard(board);
}

int main()
{
    Board board;
    displayBoard(board);
    do {
        Pos startPos, endPos;
        // Input asks for the start position
        cout << "Pièce de départ : ";
        string start, end;
        cin >> start;
        startPos.x = convertFromLetterToNumber(start[0]);
        startPos.y = 8 - (start[1] - '0');

        
        // Check the moves for the piece
        Piece piece(board.getPiece(startPos.x, startPos.y), startPos.x, startPos.y);
        if (!board.checkTurn(piece.getId()) || piece.getId() == 0) 
        {
            cout << "(Pas de pion vous appartenant.)" << endl;
            continue;
        }
        piece.getMoves(board);
        if (start[2] == '-') showMoves(piece, board);
        
        cout << "-> ";
        cin >> end;
        endPos.x = convertFromLetterToNumber(end[0]);
        endPos.y = 8 - (end[1] - '0');

        if (!piece.checkMove(endPos, board)) {
            cout << "Déplacement invalide (Conseil : Ajouter un - a la fin de votre pion vous montrera tous les déplacements possible)" << endl;
            continue;
        }
        piece.setPos(endPos, board);
        board.setPiece(startPos.x, startPos.y, 0);
        board.switchTurn();
        displayBoard(board);
    } while (true);
    return 0;
}