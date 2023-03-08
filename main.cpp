#include<iostream>
#include<string>
#include<vector>
#include"Board.h"
#include"Piece.h"

using namespace std;

void displayBoard(Board board)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch(board.table[i][j]) {
                case 0:
                    cout << " ";
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
                case -1:
                    cout << "p";
                    break;
                case -2:
                    cout << "r";
                    break;
                case -3:
                    cout << "n";
                    break;
                case -4:
                    cout << "b";
                    break;
                case -5:
                    cout << "q";
                    break;
                case -6:
                    cout << "k";
                    break;
            }
        }
        cout << endl;
    }
}

int main()
{
    Board board;
    displayBoard(board);
    do 
    {
        // get input of the piece to move
        cout << "Saisir les coordonnées de la pièce a bouger : ";
        int x, y;
        cin >> x >> y;
        Pos pos = {x, y};
        Piece piece = Piece(board.getPiece(x, y));
        
    } while (true);
    return 0;
}