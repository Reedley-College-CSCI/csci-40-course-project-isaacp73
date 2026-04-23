#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void getPlayerName(string &player1, string &player2) { //get two players names
    do { //collect player1's name
        cout << "Player 1, what is your name? (Capitalization matters)\n";
        getline(cin, player1);
        system("cls");
    } while (userConfirmation("You entered " + player1 + " is this correct?(Y/N)\n"));

    do { //collect player2's name
        cout << "Player 2, what is your name? (Capitalization matters)\n";
        getline(cin, player2);
        system("cls");
    } while (userConfirmation("You entered " + player2 + " is this correct?(Y/N)\n"));
}

void getPlayerName(string &player) { //get single players name
    do {
        cout << "What is your name? (Capitalization matters)\n";
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

    playerData.seekp(0, ios::end);

    playerData << player.name << " " << player.botWins << " " << player.playerWins << endl;

    playerData.close();
}

void updatePlayerData(string name, bool botOrPlayerWin) {

}

void displayPlayerData(string name) { //prints a players data
    
}

void sortData(const int& sortOptions) {
    fstream dataFile;

    dataFile.open("playerData.txt", ios::in);

    int numberOfSavedPlayers = 0;

    int arraySize = 10;

    playerData *data = new playerData[arraySize]; //dynamically allocates array of structs to store player data

    int trash;
    dataFile >> trash;

    //fetch all data from file
    while (getline(dataFile, data[numberOfSavedPlayers].name) && dataFile >> data[numberOfSavedPlayers].botWins >> data[numberOfSavedPlayers].playerWins) {
        numberOfSavedPlayers++;
        if (numberOfSavedPlayers > arraySize) { //if array gets full reallocate bigger one
            playerData *temp = new playerData[arraySize];

            for (int i = 0; i < arraySize; i++) {
                *(data + i) = *(temp + i);
            }

            delete[] data;

            arraySize += 10;

            data = new playerData[arraySize];

            for (int i = 0; i < (arraySize - 10); i++) {
                *(temp + i) = *(data + i);
            }

            delete[] temp;
        }
    }

    if (sortOptions == 1) { //sort by names
        playerData temp;

        for (int i = 0; i < (numberOfSavedPlayers - 1); i++) {
            for (int j = i + 1; i < numberOfSavedPlayers; i++) {
                if (data[i].name > data[j].name) {
                    temp = data[i];

                    data[i] = data[j];

                    data[j] = temp;
                }
            }
        } 
    }
    else if (sortOptions == 2) { //sort by botWins highscore
        playerData temp;

        for (int i = 0; i < (numberOfSavedPlayers - 1); i++) {
            for (int j = i + 1; i < numberOfSavedPlayers; i++) {
                if (data[i].botWins < data[j].botWins) {
                    temp = data[i];

                    data[i] = data[j];

                    data[j] = temp;
                }
            }
        } 
    }
    else if (sortOptions == 3) { //score by playerwins highscore
        playerData temp;

        for (int i = 0; i < (numberOfSavedPlayers - 1); i++) {
            for (int j = i + 1; i < numberOfSavedPlayers; i++) {
                if (data[i].playerWins < data[j].playerWins) {
                    temp = data[i];

                    data[i] = data[j];

                    data[j] = temp;
                }
            }
        } 
    }

    dataFile.out; //switch to output mode

    dataFile << sortOptions << endl; //output how the file is sorted

    for (int i = 0; i < numberOfSavedPlayers; i++) { //output data
        dataFile << data[i].name + "\n" + to_string(data[i].botWins) + " " + to_string(data[i].playerWins) << endl;
    }

    dataFile.close();
}