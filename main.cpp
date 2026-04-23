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
// #include "Game functions.h"
// #include "Player data.h"
// #include "Bot functions.h"
using namespace std;

void twoPlayer();
void singlePlayer();

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
            singlePlayer();
            break;
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

void twoPlayer() {
    cout << "Entered two player mode\n";
}

void singlePlayer() {
    cout << "Entered single player mode\n";
}