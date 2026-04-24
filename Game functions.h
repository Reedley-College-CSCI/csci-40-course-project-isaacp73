#include <iostream>

int makeMove(int board[7][6], int move, bool whichPlayer) {

}

void initGamePos(int gamePosition[7][6]) { //initiate gamePos array
    for (int y = 0; y < 6; y++) { //incroment the y cord
        for (int x = 0; x < 7; x++) { //increment the x cord
            gamePosition[x][y] = 0; //sets every value to 0 initially
        }
    }
}

bool checkWin(int board[7][6]) {
    
}

void generateBoard(int board[7][6]) { //initial generation of empty board
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 7; x++) {
            std::cout << board[x][y];
        }
        std::cout << std::endl;
    }
}