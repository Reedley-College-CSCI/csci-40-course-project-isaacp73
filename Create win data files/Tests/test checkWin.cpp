#include "Game tools.h"
#include <iostream>

/*
1. Turn
2. Position
*/
int main(int argc, char* arg[]) {
    Game leGame;

    leGame.createBoard(std::stoi(arg[1]), std::stoi(arg[2]));

    leGame.printBoard();

    if (leGame.checkWin()) {
        std::cout << "Win detected\n";
    }
    else {
        std::cout << "No win detected\n";
    }

    return 0;
}