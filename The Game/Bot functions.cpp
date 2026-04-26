#include "Objects.h"
#include <iostream>
#include <cmath>

Bot::Bot(int (*ptr)[6]) {
    board = ptr;
}

int Bot::compute() {
    
}

int Bot::checkFiles() {
    return 0;
}

int Bot::botMove(int turn) {

    Turn = turn;

    if (oneMoveWins(1) && checkIfWin(true)) return move; //check if there is a winning move

    if (oneMoveWins(2) && checkIfWin(false)) return move; //chekc if a block has to happen

    if (turn == 0) {
        return 4;
    }

    return compute();
}

void Bot::PrintMove() {
    std::cout << move << std::endl;
}

bool Bot::oneMoveWins(int playerOrBot) { //1 is bot 2 is player
    // check for 3 in a row horizantally
    for (int y = 0; y < 6; y++) { //incrament through every row
        int inARow  = 0;
        for (int x = 0; x < 6; x++) { //increment accross the row
            if (board[x][y] == playerOrBot) { //check if theres is a piece
                if (board[x][y] == board[x + 1][y]) { //if that piece matches the one next to it
                    inARow++;
                    if (inARow == 2) { //if there has been 2 times where they have matched that means there are two in a row
                        if (x-2 >= 0) { //check left bound
                            if (board[x - 2][y] == 0) { //check if its an open space to the left
                                move = x-1;
                                return true;
                            }
                        }
                        if (x+2 < 7) { //check right bound
                            if (board[x+2][y] == 0) { //check if its an open space to the right
                                move = x + 3;
                                return true;
                            }
                        }
                    }
                }
                else { //if there is a differtent piece blocking the win
                    inARow = 0; //reset counter to 0
                }
            }
            else { //catches if there is a blank space blocking the win
                inARow = 0;
            }
        }
    }

    // check for 3 in a row virtically
    for (int x = 0; x < 7; x++) { //incrament through every column
        int inAColumn  = 0;
        for (int y = 0; y < 5; y++) { //incrament down the column
            if (board[x][y] == playerOrBot) { //check if there is a piece
                if (board[x][y] == board[x][y + 1]) { //check if that piece matches the one under it
                    inAColumn++;
                    if (inAColumn == 2) { //if there has been 2 times where they have matched that means there are three in a column
                        if (y-2 >= 0) { //check upper bound
                            if (board[x][y-2] == 0) {
                                move = x+1;
                                return true;
                            }
                        }
                    }
                }
                else { //if there is a differtent piece blocking the win
                    inAColumn = 0; //reset counter to 0
                }
            }
            else {
                inAColumn = 0; //catches if there is a blank space blocking the win
            }
        }
    }

    //check top side diagnals
    for (int i = 0; i < 7; i++){
        int x = i;
        int y = 0;
        int inADiag = 0;
        if (i < 3) { //first three diagnals to the right
            while (x < 6 && y < 5) {
                if (board[x][y] == board[x + 1][y + 1] && board[x][y] != 0 && board[x][y] == playerOrBot) { //looks at the one diagnial from it and compares as long as its not a zero
                    inADiag++;
                }
                else { //if blocked by a diffrent piece or blank space resets counter
                    inADiag = 0;
                }
                if (inADiag == 2) { //catch 3 in a row
                    if (x+2 < 7 && y+2 < 6) { //check bottom right bound
                        if (board[x+2][y+2] == 0) {
                            move = x+3;
                            return true;
                        }
                    }
                    if (x-2 >= 0 && y-2 >= 0) { //check top left bound
                        if (board[x-2][y-2] == 0) { 
                            move = x-1;
                            return true;
                        }
                    }
                } 
                x++;
                y++;
            }
        }
        else if (i > 3) { //last three diagnal to the left
            while (x > 0 && y < 5) {
                if (board[x][y] == board[x - 1][y + 1] && board[x][y] != 0 && board[x][y] == playerOrBot) {//looks at the one diagnial from it and compares as long as its not a zero
                    inADiag++;
                }
                else { //if blocked by a diffrent piece or blank space resets counter
                    inADiag = 0;
                }
                if (inADiag == 2) { //catch 3 in a row
                    if (x-2 > 0 && y+2 < 6) { //check bottom left bound
                        if (board[x-2][y+2] == 0) {
                            move = x-1;
                            return true;
                        }
                    }
                    if (x+2 < 7 && y-2 > 0){ //check top right bound
                        if (board[x+2][y-2] == 0) {
                            move = x+3;
                            return true;
                        }
                    }
                } 
                x--;
                y++;
            }
        }
        else { //middle two dagnals
            while (x > 0 && y < 3) { //left facing
                if (board[x][y] == board[x - 1][y + 1] && board[x][y] != 0 && board[x][y] == playerOrBot) {//looks at the one diagnial from it and compares as long as its not a zero
                    inADiag++;
                }
                else { //if blocked by a diffrent piece or blank space resets counter
                    inADiag = 0;
                }
                if (inADiag == 2) { //catch 3 in a row
                    if (x-2 > 0 && y+2 < 6) { //check bottom left bound
                        if (board[x-2][y+2] == 0) {
                            move = x-1;
                            return true;
                        }
                    }
                    if (x+2 < 7 && y-2 > 0){ //check top right bound
                        if (board[x+2][y-2] == 0) {
                            move = x+3;
                            return true;
                        }
                    }
                }
                x--;
                y++;
            }
            y = 0;
            x = i;
            while (x < 6 && y < 3) { //right facing
                if (board[x][y] == board[x + 1][y + 1] && board[x][y] != 0 && board[x][y] == playerOrBot) { //looks at the one diagnial from it and compares as long as its not a zero
                    inADiag++;
                }
                else { //if blocked by a diffrent piece or blank space resets counter
                    inADiag = 0;
                }
                if (inADiag == 2) { //catch 3 in a row
                    if (x+2 < 7 && y+2 < 6) { //check bottom right bound
                        if (board[x+2][y+2] == 0) {
                            move = x+3;
                            return true;
                        }
                    }
                    if (x-2 > 0 && y-2 > 0) { //check top left bound
                        if (board[x-2][y-2] == 0) { 
                            move = x-1;
                            return true;
                        }
                    }
                }
                x++;
                y++;
            }
        }
    }

    //check for last three diagnals
    for (int i = 2; i < 5; i++) {
        int x = i;
        int y = 5;
        int inADiag = 0;
        while (x > 0 && y > 0) { //left facing
            if (board[x][y] == board[x - 1][y - 1] && board[x][y] != 0 && board[x][y] == playerOrBot) {//looks at the one diagnial from it and compares as long as its not a zero
                inADiag++;
            }
            else { //if blocked by a diffrent piece or blank space resets counter
                inADiag = 0;
            }
            if (inADiag == 2) { //catch 3 in a row
                if (x-2 >= 0 && y-2 >= 0) { //check top left bound
                    if (board[x-2][y-2] == 0) {
                        move = x-1;
                        return true;
                    }
                }
                if (x+2 < 7 && y+2 < 6){ //check bottom right bound
                    if (board[x+2][y+2] == 0) {
                        move = x+3;
                        return true;
                    }
                }
            }
            x--;
            y--;
        }
        x = i;
        y = 5;
        while (x < 6 && y > 0) { //right facing
            if (board[x][y] == board[x + 1][y - 1] && board[x][y] != 0 && board[x][y] == playerOrBot) {//looks at the one diagnial from it and compares as long as its not a zero
                inADiag++;
            }
            else { //if blocked by a diffrent piece or blank space resets counter
                inADiag = 0;
            }
            if (inADiag == 2) { //catch 3 in a row
                if (x+2 < 7 && y-2 >= 0) { //check top right bound
                    if (board[x+2][y-2] == 0) {
                        move = x+3;
                        return true;
                    }
                }
                if (x-2 > 0 && y+2 < 6) { //check bottom left bound
                    if (board[x-2][y+2] == 0) { 
                        move = x-1;
                        return true;
                    }
                }
            }
            x++;
            y--;
        }
    }
    return false;
}

bool Bot::checkIfWin(bool playerOrBot) {//true is the bot false is the player
    //copy board
    int copy[7][6];
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 7; x++) {
            copy[x][y] = board[x][y];
        }
    }

    
    Game boardCopy(copy); //create Game object with the copy

    if (boardCopy.makeMove(move, playerOrBot)) return true; //check if the move leads to a win

    return false;
}