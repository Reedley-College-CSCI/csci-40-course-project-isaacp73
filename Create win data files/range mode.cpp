#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

void creatBoard(Game &board, unsigned long long int pos, int turn) {
    int *moves = new int[turn + 1];

    bool bot = true;

    moves[0] = 4;

    int P;
    unsigned long long int nextPos;
    unsigned long long int currPos = pos;

    for (int i = turn; i > 0; i--) { //determine the series of moves
        P = currPos / 7;
        currPos % 7 != 0 ? nextPos = P + 1 : nextPos = P;

        moves[i] = (currPos - (nextPos * 7 - 6)) + 1;

        currPos = nextPos;
    }

    for (int i = 0; i <= turn; i++) { //make all the moves on the board
        board.makeMove(moves[i], bot);
        bot = !bot;
    }

    delete[] moves;
}

void append(unsigned long long int ending, int turn);
void append(int turn);
void select(unsigned long long int start, unsigned long long int end, int turn);

/*
1. what turn
2. append mode or select mode (-a or -s)
Append mode:
3. to end or selected amount (-e -s)
4. if selected amount how many positions
Select mode:
3. starting position
4. ending position
*/
int main(int argc, char* args[]) {
    std::string arg2 = args[2];

    if (arg2.at(1) == 'a') { //if append mode
        std::string arg3 = args[3];
        if (arg3.at(1) == 'e') { //if till end
            append(std::stoi(args[1]));
        }
        else if (arg3.at(1) == 's') { //if select
            append(std::stoi(args[4]), std::stoi(args[1]));
        }
    }
    else if (arg2.at(1) == 's') {
        select(std::stoi(args[3]), std::stoi(args[4]), std::stoi(args[1]));
    }
} 

void append(int turn) {
    int bytes;
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

    std::string name;
    name = std::to_string(turn);
    name.append(".bin");

    std::fstream dataFile;
    dataFile.open(name, std::ios::binary);

    dataFile.seekg(bytes, std::ios::end);
    dataFile.read(reinterpret_cast<char*>(&lastPos), bytes);

    dataFile.close();
    dataFile.open(name, std::ios::app);

    Game board;

    unsigned long long int wins = 0;

    for (unsigned long long int currPos = lastPos; currPos <= positions; currPos++) {
        board.reSetBoard();
        creatBoard(board, currPos, turn);

        system("clear");

        std::cout << "Turn: " << turn << "\tPosition: " << currPos << "/" << positions << "\t wins: " << wins << std::endl;

        if (board.checkWin()) {
            dataFile.write(reinterpret_cast<char*>(&currPos), bytes);
            wins++;
        }
    }

    dataFile.close();
}

void append(unsigned long long int ending, int turn) {
    int bytes;
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

    std::string name;
    name = std::to_string(turn);
    name.append(".bin");

    std::fstream dataFile;
    dataFile.open(name, std::ios::binary);

    dataFile.seekg(bytes, std::ios::end);
    dataFile.read(reinterpret_cast<char*>(&lastPos), bytes);

    dataFile.close();
    dataFile.open(name, std::ios::app);

    Game board;

    unsigned long long int wins = 0;

    for (unsigned long long int currPos = lastPos; currPos <= ending; currPos++) {
        board.reSetBoard();
        creatBoard(board, currPos, turn);

        system("clear");

        std::cout << "Turn: " << turn << "\tPosition: " << currPos << "/" << ending << "\t wins: " << wins << std::endl;

        if (board.checkWin()) {
            dataFile.write(reinterpret_cast<char*>(&currPos), bytes);
            wins++;
        }
    }

    dataFile.close();
}

void select(unsigned long long int start, unsigned long long int end, int turn) {
    int bytes;
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

    std::string name;
    name = std::to_string(turn);
    name.append(".bin");

    std::fstream dataFile;
    dataFile.open(name, std::ios::app);

    Game board;

    unsigned long long int wins = 0;

    for (unsigned long long int currPos = start; currPos <= end; currPos++) {
        board.reSetBoard();
        creatBoard(board, currPos, turn);

        system("clear");

        std::cout << "Turn: " << turn << "\tPosition: " << currPos << "/" << end << "\t wins: " << wins << std::endl;

        if (board.checkWin()) {
            dataFile.write(reinterpret_cast<char*>(&currPos), bytes);
            wins++;
        }
    }

    dataFile.close();
}