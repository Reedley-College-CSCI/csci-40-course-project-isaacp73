#include "Game tools.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

/*
1. Turn
*/
int main(int argc, char* arg[]) {
    unsigned long long int positions = pow(7, std::stoi(arg[1]));

    int bytes;
    if (std::stoi(arg[1]) <= 2) {
        bytes = 1;
    }
    else if (std::stoi(arg[1]) <= 5) {
        bytes = 2;
    }
    else if (std::stoi(arg[1]) <= 8) {
        bytes = 3;
    }
    else if (std::stoi(arg[1]) <= 11) {
        bytes = 4;
    }
    else if (std::stoi(arg[1]) <= 14) {
        bytes = 5;
    }
    else if (std::stoi(arg[1]) <= 17) {
        bytes = 6;
    }
    else if (std::stoi(arg[1]) <= 19) {
        bytes = 7;
    }
    else if (std::stoi(arg[1]) == 20) {
        bytes = 8;
    }

    std::string name;
    name = arg[1];
    name.append(".bin");

    std::ofstream dataFile;
    dataFile.open(name, std::ios::binary);

    Game board;

    unsigned long long int wins = 0;

    for (unsigned long long int currPos = 1; currPos <= positions; currPos++) {
        board.reSetBoard();
        board.createBoard(std::stoi(arg[1]), currPos);

        system("clear");

        std::cout << "Turn: " << arg[1] << "\tPosition: " << currPos << "/" << positions << "\t wins: " << wins << std::endl;

        if (board.checkWin()) {
            dataFile.write(reinterpret_cast<char*>(&currPos), bytes);
            wins++;
        }
    }

    dataFile.close();
} 