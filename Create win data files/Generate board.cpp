#include "Game tools.h"
#include <iostream>

/*
1. turn
2. position
*/
int main(int argc, char* args[]) {
    Game leGame;

    leGame.createBoard(std::stoi(args[1]), std::stoi(args[2]));

    leGame.printBoard();

    return 0;
}