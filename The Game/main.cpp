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
void displayData();

int main() {
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
        else if (userIn == 3) {
            displayData();
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
    string player;

    cin.ignore();
    getPlayerName(player);

    int index;

    if (findPlayer(player, index)) {
        cout << "Welcome back " + player + ". Are you ready to loose to my machine?\n";
    }
    else {
        newPlayer(player);
        cout << "Welcome " + player + ". Are you ready for your first time loosing to my machine?\n";
    }

        int board[7][6];

    initGamePos(board);

    bool whoseTurn = true;

    int turn = 0;

    while (!checkWin(board)) {
        int move;
        generateBoard(board);

        if (whoseTurn) {
            cout << "The bot is thinking...\n";

            if (turn > 10) {
                move = botMove(board, turn);
            }
            else {
                move = botMove(board, turn, true);
            }

            makeMove(move, true, board);
        }
        else {
            cout << player + ": ";
            cin >> move;

            if (!makeMove(move, false, board)) {
                system("cls");
                cout << "invalid move\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else {
                whoseTurn = !whoseTurn;
            }
        }

        turn++;

        system("cls");
    }

    if (!whoseTurn) {
        system("cls");
        cout << "The machine has won. You suck.\n";
    } 
    else {
        system("cls");
        cout << "You have won against the machine. Good job.\n";
        updatePlayerData(player, true);
    }
}

void twoPlayer() {
    PlayerData player1;
    PlayerData player2;

    
}



void displayData() {

}