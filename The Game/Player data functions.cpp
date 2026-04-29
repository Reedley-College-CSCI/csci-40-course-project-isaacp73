#include "Objects.h"
#include <iostream>
#include <string>
#include <fstream>
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

PlayerData::PlayerData() {
    bool cont;

    cin.clear();
    cin.ignore();

    do {
        cont = false;

        cout << "What is your name? (Capitalization matters. Only First name, no whitespace.)\n";
        getline(cin, name);
        system("cls");

        if (checkString(name)) {
            cout << "Bruh..I said no whitespace. TRY AGAIN!\n";
            cont = true;
        }
    } while (cont || !userConfirmation("You entered " + name + " is this correct?(Y/N)\n"));

    int index;

    if (findPlayer(name)) {
        cout << "Welcome back " + name + ".\n";
        displayPlayerData();
    }
    else {
        newPlayer();
        cout << "Welcome " + name + ". Your name has been saved.\n";
    }
}

bool PlayerData::findPlayer(string name) { //look for player in player saved data
    sortData(1); //sort data by name

    fstream dataFile;
    dataFile.open("playerData.txt", ios::in);

    int numberOfSavedPlayers = 0;
    int arraySize = 10;
    dataStruct *data = new dataStruct[arraySize]; //dynamically allocates array of structs to store player data
    
    while (dataFile >> data[numberOfSavedPlayers].name && dataFile >> data[numberOfSavedPlayers].botWins >> data[numberOfSavedPlayers].playerWins) {
        numberOfSavedPlayers++;
        if (numberOfSavedPlayers > arraySize) { //if array gets full reallocate bigger one
            dataStruct *temp = new dataStruct[arraySize];

            for (int i = 0; i < arraySize; i++) {
                temp[i] = data[i];
            }

            delete[] data;

            arraySize += 10;

            data = new dataStruct[arraySize];

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
        botwins = data[middle].botWins;
        playerWins = data[middle].playerWins;

        delete[] data;

        return true;
    }
    
    delete[] data;

    return false;
}

void PlayerData::newPlayer() { //Add new player to data file
    dataStruct player;

    player.name = name;
    player.botWins = 0;
    player.playerWins = 0;

    playerWins = 0;
    botwins = 0;

    fstream playerData;

    playerData.open("playerData.txt", ios::app);

    playerData.seekp(0, ios::end);

    playerData << player.name << " " << player.botWins << " " << player.playerWins << endl;

    playerData.close();
}

/*
1 = by name
2 = by bot wins
3 = by player wins
*/
void PlayerData::sortData(const int& type) {
    fstream dataFile;

    dataFile.open("playerData.txt", ios::in);

    int numberOfSavedPlayers = 0;

    int arraySize = 10;

    dataStruct *data = new dataStruct[arraySize]; //dynamically allocates array of structs to store player data

    //fetch all data from file
    while (dataFile >> data[numberOfSavedPlayers].name && dataFile >> data[numberOfSavedPlayers].botWins >> data[numberOfSavedPlayers].playerWins) {
        numberOfSavedPlayers++;
        if (numberOfSavedPlayers > arraySize) { //if array gets full reallocate bigger one
            dataStruct *temp = new dataStruct[arraySize];

            for (int i = 0; i < arraySize; i++) {
                temp[i] = data[i];
            }

            delete[] data;

            arraySize += 10;

            data = new dataStruct[arraySize];

            for (int i = 0; i < (arraySize - 10); i++) {
                data[i] = temp[i];
            }

            delete[] temp;
        }
    }

    if (type == 1) { //sort by names
        dataStruct temp;

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
    else if (type == 2) { //sort by botWins highscore
        dataStruct temp;

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
    else if (type == 3) { //score by playerwins highscore
        dataStruct temp;

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

void PlayerData::displayPlayerData() {
    cout << "Name: " + name << "\t\tBot wins: " << botwins << "\t\tPlayer wins: " << playerWins << endl; 
}

void PlayerData::updateData(bool botOrPlayerWin) { //true is bot win false is player win
    if(botOrPlayerWin) {
        botwins++;
    }
    else {
        playerWins++;
    }

    sortData(1);

    fstream dataFile;

    dataFile.open("playerData.txt", ios::in);

    int arrSize = 10;

    dataStruct *playerData = new dataStruct[arrSize];

    unsigned int i = 0;
    while (dataFile >> playerData[i].name >> playerData[i].botWins >> playerData[i].playerWins) { //grab all data
        i++;
        if (i > arrSize) { //make data array bigger if full
            dataStruct *temp = new dataStruct[arrSize]; //create temp array

            for (int j = 0; j < arrSize; j++) { //copy to temp
                temp[j] = playerData[i];
            }

            delete[] playerData;
            arrSize += 10;
            playerData = new dataStruct[arrSize];

            for (int j = 0; j < (arrSize - 10); j++) { //copy back to bigger player data array
                playerData[i] = temp[j];
            }

            delete[] temp;
        }
    }

    dataFile.close();

    int beg = 0;
    int end = i - 1;
    int middle = i / 2;

    while (playerData[middle].name != name && end > beg) {
        if (playerData[middle].name > name) {
            end = middle - 1;
            middle = (end - beg) / 2 + beg;
        }
        else {
            beg = middle + 1;
            middle = (end - beg) / 2 + beg;
        }
    }

    playerData[middle].botWins = botwins;
    playerData[middle].playerWins = playerWins;

    dataFile.open("playerData.txt", ios::out);

    for (int j = 0; j < i; j++) { //output data
        dataFile << playerData[j].name + " " + to_string(playerData[j].botWins) + " " + to_string(playerData[j].playerWins) << endl;
    }

    dataFile.close();

    delete[] playerData;
}