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
            // display the line number in red
            if (j == 0) {
                cout << "\033[31m" << 8 - i << "\033[0m ";
            }
            switch(board.table[j][i]) {
                // display the pieces, print in black all the black pieces
                case 1:
                    cout << "\033[30m" << "P" << "\033[0m";
                    break;
                case 2:
                    cout << "\033[30m" << "R" << "\033[0m";
                    break;
                case 3:
                    cout << "\033[30m" << "N" << "\033[0m";
                    break;
                case 4:
                    cout << "\033[30m" << "B" << "\033[0m";
                    break;
                case 5:
                    cout << "\033[30m" << "Q" << "\033[0m";
                    break;
                case 6:
                    cout << "\033[30m" << "K" << "\033[0m";
                    break;
                case -1:
                    cout << "P";
                    break;
                case -2:
                    cout << "R";
                    break;
                case -3:
                    cout << "N";
                    break;
                case -4:
                    cout << "B";
                    break;
                case -5:
                    cout << "Q";
                    break;
                case -6:
                    cout << "K";
                    break;
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
    return '0' - letter;
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

int main()
{
    Board board;
    displayBoard(board);
    do {
        Pos startPos;
        // Input asks for the start position
        cout << "Enter the start position: ";
        string start;
        cin >> start;
        startPos.x = convertFromLetterToNumber(start[0]);
        startPos.y = 8 - (start[1] - '0');

        // Check the moves for the piece
        Piece piece(board.getPiece(startPos.x, startPos.y), startPos.x, startPos.y);
        piece.getMoves(board);
        
    } while (true);
    return 0;
}