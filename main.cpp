// CSCI-40 Final Project
// Author: [Isaac Pulido]

/* 
 * Description:
 *
*/

#include <iostream>
#include <string>
#include <cstdlib>
// #include "Game functions.h"
#include "Player data.h"
// #include "Bot functions.h"
using namespace std;

void twoPlayer();
void singlePlayer();
void displayData();

int main() {
    while (true) {
        int userIn;

        cout << "Select single(1) or two plater(2):\t";
        cin >> userIn;

        if (userIn == 1) {
            system("cls");
            cout << "Get ready to loose to my bot.\n";
            singlePlayer();
            break;
        } 
        else if (userIn == 2) {
            system("cls");
            cout << "I know you're scared of my bot, it's ok\n";
            twoPlayer();
            break;
        }
        else if (userIn == 3) {
            displayData();
        }
        else {
            system("cls");
            cout << "Oops, something went wrong, that's an invalid input try again!\n";
            cin.clear();
            cin.ignore();
        }
    }
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
}

void twoPlayer() {
    string player1;
    string player2;

    cin.ignore();
    getPlayerName(player1, player2);

    int index;

   if (findPlayer(player1, index)) {
        cout << "Weclome back player 1. Here are your player stats:\n";
        displayPlayerData(index);
    }
    else {
        newPlayer(player1);
        cout << "Weclome " + player1 + ". Your stats will be kept tack of and saved.\n";
    }

    if (findPlayer(player2, index)) {
        cout << "Weclome back player 2. Here are your player stats:\n";
        displayPlayerData(index);
    }
    else {
        newPlayer(player2);
        cout << "Weclome " + player2 + ". Your stats will be kept tack of and saved.\n";
    }
}



void displayData() {

}