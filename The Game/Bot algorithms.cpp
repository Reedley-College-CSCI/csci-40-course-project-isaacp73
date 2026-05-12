#include "Objects.h"
#include <iostream>
#include <cmath>

bool Bot::oneMoveWins(int playerOrBot) { //1 is bot 2 is player
    // check for 3 in a row horizantally
    for (int y = 0; y < 6; y++) { //incrament through every row
        int inARow  = 0;
        for (int x = 0; x < 6; x++) { //increment accross the row
            if (board[x][y] == playerOrBot && board[x][y] == board[x + 1][y]) { //check if theres is a piece and it matches one next to it
                inARow++;
                if (inARow == 2) { //if there has been 2 times where they have matched that means there are two in a row
                    if (x-2 >= 0 && board[x - 2][y] == 0) { //check left bound and if its an open space to the left
                        move = x-1;
                        return true;
                    }
                    if (x+2 < 7 && board[x+2][y] == 0) { //check right bound and if its an open space to the right
                        move = x + 3;
                        return true;
                    }
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
            if (board[x][y] == playerOrBot && board[x][y] == board[x][y + 1]) { //check if there is a piece and if that piece matches the one under it
                inAColumn++;
                if (inAColumn == 2) { //if there has been 2 times where they have matched that means there are three in a column
                    if (y-2 >= 0 && board[x][y-2] == 0) { //check if its clear on top
                        move = x+1;
                        return true;
                    }
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

bool Bot::verifyWin(bool playerOrBot) {//true is the bot false is the player

    Game boardCopy(copy); //create Game object with the copy

    //copy board
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 7; x++) {
            copy[x][y] = board[x][y];
        }
    }

    if (!boardCopy.makeMove(move, playerOrBot)) return false; //check if the move is illegal

    return boardCopy.checkWin(playerOrBot);
}

int Bot::checkFiles() {
    return 0;
}

void Bot::resetCopy() {
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 6; y++) {
            copy[x][y] = board[x][y];
        }
    }
}

void Bot::reSizeArr() {
    MoveSequence *tempArr;
    unsigned int oldSize = size;
    tempArr = new MoveSequence[oldSize];

    for (unsigned int i = 0; i < oldSize; i++) {
        *(tempArr + i) = *(moveSequence + i);
    }

    delete[] moveSequence;

    size += SIZE_INCRAMENT;

    moveSequence = new MoveSequence[size];

    for (unsigned int i = 0; i < oldSize; i++) {
        *(moveSequence + 1) = *(tempArr + i);
    }

    delete[] tempArr;
}

bool Bot::incramentMoveSequence(long int size) {
    (moveSequence + size)->moves++;

    if ((moveSequence + size)->moves > 7) {
        (moveSequence + size)->moves = 1;
        while ((moveSequence + size)->ilegalMove[((moveSequence + size)->moves) - 1])  (moveSequence + size)->moves++;

        if (size == 0) return true;
        if (incramentMoveSequence(size - 1)) return true;
    }

    return false;
}

void Bot::makeMoveSequence(Game& copyOfBoard) {
    bool which = true;
    for (unsigned int i = 0; i < turnsAhead; i++) {
        copyOfBoard.makeMove((moveSequence + i)->moves, which);
        which = !which;
    }
}
 
void Bot::compute() {
    Game CopyOfBoard(copy);

    moveSequence->moves = 1;
    bool which = true;
    int piece;

    resetCopy();

    while (turnsAhead + Turn <= 42) {
        resetCopy();
        makeMoveSequence(CopyOfBoard);

        if (!CopyOfBoard.makeMove((moveSequence + turnsAhead)->moves, which)) { //make move and catch illegal moves
            (moveSequence + turnsAhead)->ilegalMove[(moveSequence + turnsAhead)->moves - 1] = true;
            incramentMoveSequence(turnsAhead);
        }
        else {
            (moveSequence + turnsAhead)->ilegalMove[(moveSequence + turnsAhead)->moves - 1] = false;
            which ? piece = 1 : piece = 2;

            if (CopyOfBoard.checkWin(piece) && which == true) {
                return;
            }

            if (incramentMoveSequence(turnsAhead)) {
                turnsAhead++;
                which = !which;
                if (turnsAhead == size) reSizeArr();
                (moveSequence + turnsAhead)->moves = 1;
            } 
        }
    }
}