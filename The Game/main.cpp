// CSCI-40 Final Project
// Author: [Isaac Pulido]

/* 
 * Description:
 *
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#include <fstream>
#include "Objects.h"
using namespace std;

void twoPlayer();
void singlePlayer();
void dataMode();
void displayData();

int main() {
    system("clear");
    while (true) {
        int userIn;

        cout << "Select single(1) or two plater(2). (or 3 to view leader boards or -99 to exit):\t";
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
        else if (userIn == 3) {
            system("clear");
            displayData();
            
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

bool userConfirm(const std::string& message) { // Function to get user confirmation (Y/N)
    char response;
    do {
        std::cout << message;
        std::cin >> response;
        response = toupper(response);
        if (response != 'Y' && response != 'N') {
            system("clear"); // Clear the console for better readability
            std::cout << "Invalid input. Please enter 'Y' for Yes or 'N' for No." << std::endl;
        }
    } while (response != 'Y' && response != 'N');

    system("clear");
    std::cin.ignore();
    return response == 'Y';
}

void displayData() {
    ifstream dataFile;
    dataFile.open("playerData.txt");

    try {
        if (!dataFile.is_open()) throw "file_missing";
    }
    catch (const char* m) {
        cout << "Error: " << m << endl;

        if (userConfirm("Do you want to create the file and return? (Y/N)\n")) {
            ofstream newFile;
            newFile.open("playerData.txt");

            newFile.is_open() ? cout << "File created successfully\n" : cout << "File could not be created\n";

            newFile.close();
            return;
        }
        else {
            cout << "File will be created when later\n";
            return;
        }
    }

    struct data {
        string name;
        unsigned int botWins;
        unsigned int playerWins;
    };

    const unsigned int ARR_SIZE_INCRAMENT = 10;
    unsigned int arrSize = ARR_SIZE_INCRAMENT;
    unsigned int players = 0;

    data *playerData = new data[arrSize];

    try {
        if (!(dataFile >> playerData->name >> playerData->botWins >> playerData->playerWins)) throw "file_empty";
    }
    catch (const char* m){
        cout << "Error: " << m << endl
            << "The program will now return\n";
        return;
    }

    PlayerData player(true);

    player.sortData(2);

    dataFile.seekg(0, ios::beg);

    int i = 0;

    while (dataFile >> (playerData + i)->name >> (playerData + i)->botWins >> (playerData + i)->playerWins && i < 10) i++;

    cout << "Bot win leader board\n" << string(20, '-') << endl;
    
    for (int j = 0; j < i; j++) {
        cout << fixed << left << setw(17) << (playerData + j)->name << (playerData + j)->botWins << endl;
    }

    cout << endl << endl;

    player.sortData(3);

    dataFile.close();

    dataFile.open("playerData.txt");

    i = 0;

    while (dataFile >> (playerData + i)->name >> (playerData + i)->botWins >> (playerData + i)->playerWins && i < 10) i++;

    cout << "Player win leader board\n" << string(20, '-') << endl;
    
    for (int j = 0; j < i; j++) {
        cout << fixed << left << setw(17) << (playerData + j)->name << (playerData + j)->playerWins << endl;
    }

    cout << endl << endl;

    delete[] playerData;
    dataFile.close();
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

    player1.displayPlayerData();

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