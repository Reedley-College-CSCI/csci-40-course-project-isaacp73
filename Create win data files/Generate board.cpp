#include "Game.h"
#include <iostream>

void moveSequence(int turn, unsigned long long int pos, int *moves) {

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
}

/*
1. turn
2. position
*/
int main(int argc, char* arg[]) {
    Game board;

    int *moves = new int[std::stoi(arg[1]) + 1];

    moveSequence(std::stoi(arg[1]), std::stoi(arg[2]), moves);

    bool which = true;
    for (int i = 0; i < std::stoi(arg[1]); i++) {
        board.makeMove(moves[i], which);
        which = !which;
    }

    board.printBoard();

    delete[] moves;

    return 0;
}