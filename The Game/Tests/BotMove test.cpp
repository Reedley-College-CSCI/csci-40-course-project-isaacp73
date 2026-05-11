#include "Objects.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
    int arr[7][6];

    Game leGame(arr);

    bool which = true;
    
    for (int i = 1; i < argc; i++) {
        leGame.makeMove(stoi(args[i]), which);
        which = !which;
    }

    leGame.printBoard();

    Bot leMachine(arr);

    leGame.makeMove(leMachine.botMove(argc - 1), true);

    leMachine.PrintMove();

    leGame.printBoard();

    return 0;
}