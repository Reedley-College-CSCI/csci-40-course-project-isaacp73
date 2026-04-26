#include "Objects.h"
#include <iostream>

int  main(int argc, char* args[]) {
    int board[7][6];

    int *moves = new int[argc-1];

    for (int i = 1; i < argc; i++) {
        moves[i-1] = std::stoi(args[i]);
    }

    Game leGame(board);

    bool which = true;

    for (int i = 0; i < (argc-1); i++) {
        leGame.makeMove(moves[i], which);
        which = !which;
    }

    leGame.printBoard();

    Bot leMachine(board);

    if (leMachine.oneMoveWins(1)) {
        std::cout << "Three in a row found\n";
        leMachine.PrintMove();
    }
    else {
        std::cout << "Nothing was found\n";
    }

    delete[] moves;

    return 0;
}