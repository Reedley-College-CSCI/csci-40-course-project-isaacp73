#include "Game tools.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cctype>

bool append(unsigned long long int ending, int turn);
void append(int turn);
bool select(unsigned long long int start, unsigned long long int end, int turn);

/*
1. what turn
2. append mode or select mode (a or s)
Append mode:
3. to end or selected amount (e s)
4. if selected amount how many positions
Select mode:
3. starting position
4. ending position
*/
int main(int argc, char* args[]) {
    if (isalpha(*args[1]) || std::stoi(args[1]) <= 0) {
        std::cout << "Error: first argument must be of type unsigned int\n";
        return 1;
    } 

    if (argc > 5) {
        std::cout << "Error: Too many arguments\n";
        return 1;
    }

    unsigned int mode; //decode arguments into which mode
    if (*args[2] == 'a') { //if append mode
        if (*args[3] == 'e') { //if till end
           mode = 1; 
        }
        else if (*args[3] == 's') { //if select ending point
            mode = 2;
        }
        else { //catch if third argument is invalid
           std::cout << args[3] << " is not a recognized argument\n";
           return 1; 
        }
    }
    else if (*args[2] == 's') { //if select mode
        mode = 3;
    }
    else { //catch if second argument invalid
        std::cout << args[2] << " is not a recognized argument\n";
        return 1;
    }

    if (mode == 2 || mode == 3) {
        std::ifstream dataFile;
        std::string name; //name of file
        name = args[1];
        name.append(".bin");

        dataFile.open(name);
        if (!dataFile.is_open()) {
            std::cout << "Error: file missing: " << name << std::endl;
            return 1;
        }
        dataFile.close();
    }

    switch(mode) { //call appropiate function
        case 1:
            append(std::stoi(args[1]));
            break;
        case 2:
            if (!append(std::stoi(args[4]), std::stoi(args[1]))) return 1;
            break;
        case 3:
            if (!select(std::stoi(args[3]), std::stoi(args[4]), std::stoi(args[1]))) return 1;
            break;
    }

    return 0;
} 

void append(int turn) {
    int bytes; //figure out how many bytes are needed to store the largest posible win postition number
    if (turn <= 2) {
        bytes = 1;
    }
    else if (turn <= 5) {
        bytes = 2;
    }
    else if (turn <= 8) {
        bytes = 3;
    }
    else if (turn <= 11) {
        bytes = 4;
    }
    else if (turn <= 14) {
        bytes = 5;
    }
    else if (turn <= 17) {
        bytes = 6;
    }
    else if (turn <= 19) {
        bytes = 7;
    }
    else if (turn == 20) {
        bytes = 8;
    }

    unsigned long long int lastPos; //the last know positions in the file

    unsigned long long int positions = std::pow(7, turn);

    std::string name; //name of file
    name = std::to_string(turn);
    name.append(".bin");

    std::ifstream dataFile; //get last known win position
    dataFile.open(name, std::ios::binary);
    dataFile.seekg(-3, std::ios::end);
    dataFile.read(reinterpret_cast<char*>(&lastPos), 2);
    dataFile.close();

    std::fstream outFile; //open file
    outFile.open(name, std::ios::app);

    Game board;

    unsigned long long int wins = 0;

    lastPos++; //check the nexr position after the last known win position

    for (unsigned long long int currPos = lastPos; currPos <= positions; currPos++) { //find wins
        board.reSetBoard();
        board.createBoard(turn, currPos);

        system("clear");

        std::cout << "Turn: " << turn << "\tPosition: " << currPos << "/" << positions << "\t wins: " << wins << std::endl;

        if (board.checkWin()) {
            outFile.write(reinterpret_cast<char*>(&currPos), bytes);
            wins++;
        }
    }

    outFile.close();
}

bool append(unsigned long long int positions, int turn) {
    int bytes; //figure out how many bytes are needed to store the largest posible win postition number
    if (turn <= 2) {
        bytes = 1;
    }
    else if (turn <= 5) {
        bytes = 2;
    }
    else if (turn <= 8) {
        bytes = 3;
    }
    else if (turn <= 11) {
        bytes = 4;
    }
    else if (turn <= 14) {
        bytes = 5;
    }
    else if (turn <= 17) {
        bytes = 6;
    }
    else if (turn <= 19) {
        bytes = 7;
    }
    else if (turn == 20) {
        bytes = 8;
    }

    unsigned long long int lastPos; //the last know positions in the file

    std::string name; //name of file
    name = std::to_string(turn);
    name.append(".bin");

    std::ifstream inFile; //open file and get last win postion
    inFile.open(name, std::ios::binary);
    inFile.seekg((0 - bytes), std::ios::end);
    inFile.read(reinterpret_cast<char*>(&lastPos), bytes);
    inFile.close();

    unsigned long long int ending = lastPos + positions;


    if (ending >  pow(7, turn)) {
        std::cout << "Error: too many positions\n" << ending << "\t" << lastPos << std::endl;
        return false;
    }

    std::fstream dataFile; //open file
    dataFile.open(name, std::ios::app);

    Game board; //create Game instance

    unsigned long long int wins = 0;

    lastPos++; //check the next position from the last known win

    for (unsigned long long int currPos = lastPos; currPos <= ending; currPos++) { //look for wins
        board.reSetBoard();
        board.createBoard(turn, currPos);

        system("clear");

        std::cout << "Turn: " << turn << "\tPosition: " << currPos << "/" << ending << "\t wins: " << wins << std::endl;

        if (board.checkWin()) {
            dataFile.write(reinterpret_cast<char*>(&currPos), bytes);
            wins++;
        }
    }

    dataFile.close();

    return true;
}

bool select(unsigned long long int start, unsigned long long int end, int turn) {

    if (start <= 0 || end > pow(7, turn) || start > end) {
        std::cout << "Error: starting, ending, or both positions are invalid\n";
        return false;
    }

    int bytes; //figure out how many bytes are needed to store the largest posible win postition number
    if (turn <= 2) {
        bytes = 1;
    }
    else if (turn <= 5) {
        bytes = 2;
    }
    else if (turn <= 8) {
        bytes = 3;
    }
    else if (turn <= 11) {
        bytes = 4;
    }
    else if (turn <= 14) {
        bytes = 5;
    }
    else if (turn <= 17) {
        bytes = 6;
    }
    else if (turn <= 19) {
        bytes = 7;
    }
    else if (turn == 20) {
        bytes = 8;
    }

    std::string name; //file name
    name = std::to_string(turn);
    name.append(".bin");

    std::fstream dataFile; //open file
    dataFile.open(name, std::ios::app);

    Game board;

    unsigned long long int wins = 0;

    for (unsigned long long int currPos = start; currPos <= end; currPos++) {
        board.reSetBoard();
        board.createBoard(turn, currPos);

        system("clear");

        std::cout << "Turn: " << turn << "\tPosition: " << currPos << "/" << end << "\t wins: " << wins << std::endl;

        if (board.checkWin()) {
            dataFile.write(reinterpret_cast<char*>(&currPos), bytes);
            wins++;
        }
    }

    dataFile.close();

    return true;
}