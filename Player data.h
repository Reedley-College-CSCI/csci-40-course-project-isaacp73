#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void getPlayerName(string &player1, string &player2) { //get two players names
    do { //collect player1's name
        cout << "Player 1, what is your name?\n";
        getline(cin, player1);
        system("cls");
    } while (userConfirmation("You entered " + player1 + " is this correct?(Y/N)\n"));

    do { //collect player2's name
        cout << "Player 2, what is your name?\n";
        getline(cin, player2);
        system("cls");
    } while (userConfirmation("You entered " + player2 + " is this correct?(Y/N)\n"));
}

void getPlayerName(string &player) { //get single players name
    do {
        cout << "What is your name?\n";
        getline(cin, player);
        system("cls");
    } while (userConfirmation("You entered " + player + " is this correct?(Y/N)\n"));
}

bool userConfirmation(const string& message) { // Function to get user confirmation (Y/N)
    char response;
    do {
        cout << message;
        cin >> response;
        response = toupper(response);
        if (response != 'Y' && response != 'N') {
            system("clear"); // Clear the console for better readability
            cout << "Invalid input. Please enter 'Y' for Yes or 'N' for No." << endl;
        }
    } while (response != 'Y' && response != 'N');
    return response == 'Y';
}

struct playerData {
    string name;
    unsigned int botWins;
    unsigned int playerWins;
};

bool returningPlayerCheck(string name) { //check if there is a returning player

}

void newPlayer(string name) { //Add new player to data file
    playerData player;

    player.name = name;
    player.botWins = 0;
    player.playerWins = 0;

    fstream playerData;

    playerData.open("playerData.txt", ios::app);

    playerData << player.name << " " << player.botWins << " " << player.playerWins << endl;

    playerData.close();
}

void updatePlayerData(string name) {

}

void displayPlayerData(string name) { //prints a players data
    
}

