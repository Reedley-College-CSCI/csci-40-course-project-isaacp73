// CSCI-40 Final Project
// Author: [Isaac Pulido]

/* 
 * Description:
 *
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "Objects.h"
using namespace std;

void twoPlayer();
void singlePlayer();

int main() {
    system("cls");
    while (true) {
        int userIn;

        cout << "Select single(1) or two plater(2) (or -99 to exit):\t";
        cin >> userIn;

        if (userIn == 1) {
            system("cls");
            cout << "Get ready to loose to my bot.\n";
            singlePlayer();
        } 
        else if (userIn == 2) {
            system("cls");
            cout << "I know you're scared of my bot, it's ok\n";
            twoPlayer();
        }
        else if (userIn == -99) {
            break;
        }
        else {
            system("cls");
            cout << "Oops, something went wrong, that's an invalid input try again!\n";
            cin.clear();
            cin.ignore();
        }
    }
    system("cls");
    cout << "Thanks for playing. See you later!\n";
    return 0;
}

void singlePlayer() {
    cout << "IN PROGRESS: COMING SOON.\n";
}

void twoPlayer() {
    PlayerData player1;
    PlayerData player2;

    int board[7][6];

    Game leGame(board);

    bool which = true;

    int move;

    while (!leGame.checkWin()) {
        leGame.printBoard();
        bool goodInput;

        if (which) {
            do {
                cout << player1.printName() << ":\t";
                cin >> move;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (!leGame.makeMove(move, which));
        }
        else {
            do {
                cout << player2.printName() << ":\t";
                cin >> move;
                
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (!leGame.makeMove(move, which));
        }

        which = !which;

        system("cls");
    }

    if (!which) {
        system("cls");
        leGame.printBoard();
        cout << player1.printName() + " has won\n" + player2.printName() + " you suck\n";
        player1.updateData(false);
    } 
    else {
        system("cls");
        leGame.printBoard();
        cout << player2.printName() + " has won\n" + player1.printName() + " you suck\n";
        player2.updateData(false);
    }
}