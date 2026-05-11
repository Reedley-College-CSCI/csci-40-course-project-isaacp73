#include "Objects.h"
#include <iostream>
#include <cmath>

Bot::Bot(int (*ptr)[6]) {
    board = ptr;
    turnsAhead = 0;
    moveSequence = new MoveSequence[SIZE_INCRAMENT];
    size = SIZE_INCRAMENT;
}

Bot::~Bot() {
    delete[] moveSequence;
}

int Bot::botMove(int turn) {
    Turn = turn;

    if (oneMoveWins(1) && verifyWin(true)) return move; //check if there is a winning move

    if (oneMoveWins(2) && verifyWin(false)) return move; //chekc if a block has to happen

    if (turn == 0) {
        return 4;
    }

    turnsAhead = 0;
    delete[] moveSequence;
    moveSequence = new MoveSequence[SIZE_INCRAMENT];
    size = SIZE_INCRAMENT;

    compute();

    return moveSequence->moves;
}

void Bot::printMoveSequence() {
    for (unsigned int i = 0; i <= turnsAhead; i++) {
        std::cout << i << ": "<< (moveSequence + i)->moves << std::endl; 
    }
}