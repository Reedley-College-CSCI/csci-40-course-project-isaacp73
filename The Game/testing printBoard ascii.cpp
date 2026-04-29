#include <iostream>
#include "Objects.h"

int main(int argc, char* args[]) {
    int board[7][6];
    Game leGame(board);

    bool which = true;
    for (int i = 1; i < argc; i++) {
        leGame.makeMove(std::stoi(args[i]), which);
        which = !which;
    }

    leGame.printBoard();

    return 0;
}