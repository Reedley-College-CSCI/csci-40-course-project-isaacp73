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
    system("clear");
    while (true) {
        int userIn;

        cout << "Select single(1) or two plater(2) (or -99 to exit):\t";
        cin >> userIn;

        if (userIn == 1) {
            system("clear");
            cout << "Get ready to loose to my bot.\n";
            singlePlayer();
        } 
        else if (userIn == 2) {
            system("clear");
            cout << "I know you're scared of my bot, it's ok\n";
            twoPlayer();
        }
        else if (userIn == -99) {
            break;
        }
        else {
            system("clear");
            cout << "Oops, something went wrong, that's an invalid input try again!\n";
            cin.clear();
            cin.ignore();
        }
    }
    system("clear");
    cout << "Thanks for playing. See you later!\n";
    return 0;
}

void singlePlayer() {
    PlayerData player;

    int board[7][6];

    Game leGame(board);

    Bot leMachine(board);

    bool which = true;
    unsigned int piece = 1;
    unsigned int Turn = 0;

    int playerMove;

    while (!leGame.checkWin(piece)) {
        leGame.printBoard();
        leMachine.printMoveSequence();

        if (which) {
            leGame.makeMove(leMachine.botMove(Turn), which);
        }
        else {
            do {
                cout << player.printName() << ":\t";
                cin >> playerMove;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (!leGame.makeMove(playerMove, which));
        }

        which ? piece = 1 : piece = 2;

        which = !which;

        Turn++;

        system("clear");
    }

    if (!which) {
        system("clear");
        leGame.printBoard();
        cout << "The machines have won\n" + player.printName() + " you have failed humanity\n";
    } 
    else {
        system("clear");
        leGame.printBoard();
        cout << player.printName() + " has won\n" + "You've beat the Machine...this time\n";
        player.updateData(true);
    }
}

void twoPlayer() {
    PlayerData player1;
    PlayerData player2;

    int board[7][6];

    Game leGame(board);

    bool which = true;
    int piece = 1;

    int move;

    while (!leGame.checkWin(piece)) {
        leGame.printBoard();

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

        which ? piece = 1 : piece = 2;

        which = !which;

        system("clear");
    }

    if (!which) {
        system("clear");
        leGame.printBoard();
        cout << player1.printName() + " has won\n" + player2.printName() + " you suck\n";
        player1.updateData(false);
    } 
    else {
        system("clear");
        leGame.printBoard();
        cout << player2.printName() + " has won\n" + player1.printName() + " you suck\n";
        player2.updateData(false);
    }
}