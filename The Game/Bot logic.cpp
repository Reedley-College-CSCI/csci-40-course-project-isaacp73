#include "Objects.h"
#include <iostream>
#include <cmath>

Bot::Bot(int (*ptr)[6]) {
    board = ptr;
}

int Bot::botMove(int turn) {

    Turn = turn;

    if (oneMoveWins(1) && verifyWin(true)) return move; //check if there is a winning move

    if (oneMoveWins(2) && verifyWin(false)) return move; //chekc if a block has to happen

    if (turn == 0) {
        move = 4;
        return move;
    }

    return compute();
}

void Bot::PrintMove() {
    std::cout << move << std::endl;
}

