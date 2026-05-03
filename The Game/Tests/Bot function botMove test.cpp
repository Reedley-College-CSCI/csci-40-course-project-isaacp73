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

    std::cout << leMachine.botMove(argc-1) << std::endl;

    // leGame.printBoard();

    delete[] moves;
}