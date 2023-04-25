#include<iostream>
#include<string>
#include<vector>
#include"Piece.h"
#include"Board.h"

using namespace std;

#define RIGHT 1
#define LEFT -1
#define UP -1
#define DOWN 1

/*
Mouvement des pièces + regles
Régles avancés : 
    - Promotion
    - Prise en passant
    - Roque (petit/grand)
    - Clouage
*/



char PieceToLetter(int p)
{
    switch (p) 
    {
        case 1:
            return 'P';
        case 2:
            return 'R';
        case 3:
            return 'N';
        case 4:
            return 'B';
        case 5:
            return 'Q';
        case 6:
            return 'K';
        default:
            return p;
    }
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
        default:
            return 0;
    }
}
void displayBoard(Board board)
{
    // affiche si un en passant est possible
    if (board.en_passant.x != -1) {
        cout << "En passant possible en " << (char)(board.en_passant.x + 97) << 8 - board.en_passant.y << endl;
    }
    else {
        cout << "Pas d'en passant possible" << endl;
    }
    cout << "Tour actuel : " << (board.getTurn() == 1 ? "blanc" : "\033[30m noir \033[0m") << endl << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // display the line number in red
         if (j == 0) {
                cout << "\033[31m" << 8 - i << "\033[0m ";
            }
            int p=board.getPiece(j, i);
            if (p==10) {
                cout << "\033[32m" << "-" << "\033[0m";
            }
            else if (p>=20) {
                cout << "\033[35m" << PieceToLetter(p-20) << "\033[0m";
            }
            else if (p>0) {
                cout << "\033[37m" << PieceToLetter(p) << "\033[0m";
            }
            else if (p<0) {
                cout << "\033[30m" << PieceToLetter(-p) << "\033[0m";
            }

            else {
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





void showMoves(Piece piece, Board board)
{
    // change the piece id to 10 to show the moves
    for (int i = 0; i < piece.moves.size(); i++) {
        board.setPiece(piece.moves[i].x, piece.moves[i].y, 10);
    }

    // add 20 to the piece id that can get eaten
    for (int i = 0; i < piece.kills.size(); i++) {
        board.setPiece(piece.kills[i].x, piece.kills[i].y, board.getTurn()*-1*board.getPiece(piece.kills[i].x, piece.kills[i].y) + 20);
    }
    displayBoard(board);
}

int main()
{
    Board board;
    displayBoard(board);
    do {
        Pos startPos={0,0}, endPos={0,0};
        // Input asks for the start position
        cout << "Pièce de départ : ";
        string start, end;
        cin >> start;
        startPos.x = convertFromLetterToNumber(start[0]);
        startPos.y = 8 - (start[1] - '0');
        
        if (start[0] < 97 || start[0] > 104 || start[1] < 49 || start[1] > 56) {
            cout << "Position invalide" << endl;
            continue;
        }
        
        // Check the moves for the piece
        Piece piece(board.getPiece(startPos.x, startPos.y), startPos.x, startPos.y);
        if (!board.checkTurn(piece.getId()) || piece.getId() == 0) 
        {
            cout << "(Pas de pion vous appartenant.)" << endl;
            continue;
        }
        piece.getMoves(board, false);


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
        if (board.getCheckMate()) 
        {
            cout << "Echec et mat !" << endl;
            break;
        }
    } while (true);
    return 0;
}