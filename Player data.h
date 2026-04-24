#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool userConfirmation(const string& message) { // Function to get user confirmation (Y/N)
    char response;
    do {
        cout << message;
        cin >> response;
        response = toupper(response);
        if (response != 'Y' && response != 'N') {
            system("cls"); // Clear the console for better readability
            cout << "Invalid input. Please enter 'Y' for Yes or 'N' for No." << endl;
        }
    } while (response != 'Y' && response != 'N');

    system("cls");
    cin.ignore();
    return response == 'Y';
}

bool checkString(const string& name) { //check if name has whitespace
    for (int i = 0; i < name.size(); i++) {
        if (name.at(i) == ' ') return true;
    }
    return false;
}

void getPlayerName(string& player1, string& player2) { //get two players names
    bool cont;

    do { //collect player1's name
        cont = false;

        cout << "Player 1, what is your name? (Capitalization matters. Only First name, no whitespace.)\n";
        getline(cin, player1);
        system("cls");

        if (checkString(player1)) {
            cout << "Bruh..I said no whitespace. TRY AGAIN!\n";
            cont = true;
        }

    } while (cont || !userConfirmation("You entered " + player1 + " is this correct?(Y/N)\n"));

    do { //collect player2's name
        cont = false;

        cout << "Player 2, what is your name? (Capitalization matters. Only First name, no whitespace.)\n";
        getline(cin, player2);
        system("cls");

        if (checkString(player2)) {
            cout << "Bruh..I said no whitespace. TRY AGAIN!\n";
            cont = true;
        }

    } while (cont || !userConfirmation("You entered " + player2 + " is this correct?(Y/N)\n"));
}

void getPlayerName(string& player) { //get single players name
    bool cont;

    do {
        cont = false;

        cout << "What is your name? (Capitalization matters. Only First name, no whitespace.)\n";
        getline(cin, player);
        system("cls");

        if (checkString(player)) {
            cout << "Bruh..I said no whitespace. TRY AGAIN!\n";
            cont = true;
        }
    } while (cont || !userConfirmation("You entered " + player + " is this correct?(Y/N)\n"));
}

struct playerData {
    string name;
    unsigned int botWins;
    unsigned int playerWins;
};

/*
1 = by name
2 = by bot wins
3 = by player wins
*/
void sortData(const int& sortOptions) {
    fstream dataFile;

    dataFile.open("playerData.txt", ios::in);

    int numberOfSavedPlayers = 0;

    int arraySize = 10;

    playerData *data = new playerData[arraySize]; //dynamically allocates array of structs to store player data

    //fetch all data from file
    while (dataFile >> data[numberOfSavedPlayers].name && dataFile >> data[numberOfSavedPlayers].botWins >> data[numberOfSavedPlayers].playerWins) {
        numberOfSavedPlayers++;
        if (numberOfSavedPlayers > arraySize) { //if array gets full reallocate bigger one
            playerData *temp = new playerData[arraySize];

            for (int i = 0; i < arraySize; i++) {
                temp[i] = data[i];
            }

            delete[] data;

            arraySize += 10;

            data = new playerData[arraySize];

            for (int i = 0; i < (arraySize - 10); i++) {
                data[i] = temp[i];
            }

            delete[] temp;
        }
    }

    if (sortOptions == 1) { //sort by names
        playerData temp;

        for (int i = 0; i < (numberOfSavedPlayers - 1); i++) {
            for (int j = i + 1; j < numberOfSavedPlayers; j++) {
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
            for (int j = i + 1; j < numberOfSavedPlayers; j++) {
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
            for (int j = i + 1; j < numberOfSavedPlayers; j++) {
                if (data[i].playerWins < data[j].playerWins) {
                    temp = data[i];

                    data[i] = data[j];

                    data[j] = temp;
                }
            }
        } 
    }

    dataFile.close();

    dataFile.open("playerData.txt", ios::out);

    for (int i = 0; i < numberOfSavedPlayers; i++) { //output data
        dataFile << data[i].name + " " + to_string(data[i].botWins) + " " + to_string(data[i].playerWins) << endl;
    }

    dataFile.close();

    delete[] data;
}

bool findPlayer(string name, int& index) { //look for player in player saved data
    sortData(1); //sort data by name

    fstream dataFile;
    dataFile.open("playerData.txt", ios::in);

    int numberOfSavedPlayers = 0;
    int arraySize = 10;
    playerData *data = new playerData[arraySize]; //dynamically allocates array of structs to store player data
    
    while (dataFile >> data[numberOfSavedPlayers].name && dataFile >> data[numberOfSavedPlayers].botWins >> data[numberOfSavedPlayers].playerWins) {
        numberOfSavedPlayers++;
        if (numberOfSavedPlayers > arraySize) { //if array gets full reallocate bigger one
            playerData *temp = new playerData[arraySize];

            for (int i = 0; i < arraySize; i++) {
                temp[i] = data[i];
            }

            delete[] data;

            arraySize += 10;

            data = new playerData[arraySize];

            for (int i = 0; i < (arraySize - 10); i++) {
                data[i] = temp[i];
            }

            delete[] temp;
        }
    }
    

    dataFile.close();

    int beg = 0;
    int end = numberOfSavedPlayers - 1;
    int middle = numberOfSavedPlayers / 2;

    while (data[middle].name != name && end > beg) {
        if (data[middle].name > name) {
            end = middle - 1;
            middle = (end - beg) / 2 + beg;
        }
        else {
            beg = middle + 1;
            middle = (end - beg) / 2 + beg;
        }
    }

    if (data[middle].name == name) {
        index = middle;
        return true;
    }
    else {
        return false;
    }

    delete[] data;
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

void displayPlayerData(int index) { //prints a players data
    sortData(1);

    fstream dataFile;
    dataFile.open("playerData.txt", ios::in);

    int numberOfSavedPlayers = 0;
    int arraySize = 10;
    playerData *data = new playerData[arraySize]; //dynamically allocates array of structs to store player data

    while (dataFile >> data[numberOfSavedPlayers].name && dataFile >> data[numberOfSavedPlayers].botWins >> data[numberOfSavedPlayers].playerWins) {
        numberOfSavedPlayers++;
        if (numberOfSavedPlayers > arraySize) { //if array gets full reallocate bigger one
            playerData *temp = new playerData[arraySize];

            for (int i = 0; i < arraySize; i++) {
                temp[i] = data[i];
            }

            delete[] data;

            arraySize += 10;

            data = new playerData[arraySize];

            for (int i = 0; i < (arraySize - 10); i++) {
                data[i] = temp[i];
            }

            delete[] temp;
        }
    }

    dataFile.close();

    cout << "Name: " + data[index].name << "\t\tWins against humans: " << data[index].playerWins << "\t\tWins against the mechine: " << data[index].botWins << endl;

    delete[] data;
}

void displayPlayerData(bool all) {
    
}

void updatePlayerData(string name, bool botOrPlayerWin) {

}