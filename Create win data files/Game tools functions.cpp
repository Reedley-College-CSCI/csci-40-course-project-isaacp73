#include <iostream>
#include "Game tools.h"

bool Game::makeMove(int move, bool which) { //true is 1 and false is 2
    if (move > 7 || move < 1) {
        return false;
    }
    if (which) { //if the bot is making a move 
        for (int i = 5; i >= 0; i--) { //incrament up the column that is being played
            if (board[move - 1][i] != 0 && i == 0) return false; //will catch if the whole column is full and return false to siginify an illigal move
            if (board[move - 1][i] != 0) continue; //check if the position in the column is taken

            board[move - 1][i] = 1; //when an open position is found will set it to 2 representing a player piece
            break;
        }
    }
    else { //if the player is making a move
        for (int i = 5; i >= 0; i--) { //incrament up the column that is being played
            if (board[move - 1][i] != 0 && i == 0) return false; //will catch if the whole column is full and return false to siginify an illigal move
            if (board[move - 1][i] != 0) continue; //check if the position in the column is taken

            board[move - 1][i] = 2; //when an open position is found will set it to 2 representing a player piece
            break;
        }
    }
    return true;
}

Game::Game() { //initiate gamePos array
    for (int y = 0; y < 6; y++) { //incroment the y cord
        for (int x = 0; x < 7; x++) { //increment the x cord
            board[x][y] = 0; //sets every value to 0 initially
        }
    }
}

bool Game::checkWin() {
    // check for horizantal wins
    for (int y = 0; y < 6; y++) { //incrament through every row
        int inARow  = 0;
        for (int x = 0; x < 6; x++) { //increment accross the row
            if (board[x][y] == 1) { //check if theres is a piece
                if (board[x][y] == board[x + 1][y]) { //if that piece matches the one next to it
                    inARow++;
                    if (inARow == 3) { //if there has been 3 times where they have matched that means there are four in a row
                        return true;
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

    // check for virtical win
    for (int x = 0; x < 7; x++) { //incrament through every column
        int inAColumn  = 0;
        for (int y = 0; y < 5; y++) { //incrament down the column
            if (board[x][y] == 1) { //check if there is a piece
                if (board[x][y] == board[x][y + 1]) { //if that piece matches the one under to it
                    inAColumn++;
                    if (inAColumn == 3) { //if there has been 3 times where they have matched that means there are four in a column
                        return true;
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
                if (board[x][y] == board[x + 1][y + 1] && board[x][y] != 0 && board[x][y] == 1) { //looks at the one diagnial from it and compares as long as its not a zero
                    inADiag++;
                }
                else { //if blocked by a diffrent piece or blank space resets counter
                    inADiag = 0;
                }
                if (inADiag == 3) return true; //catch a win
                x++;
                y++;
            }
        }
        else if (i > 3) { //last three diagnal to the left
            while (x > 0 && y < 5) {
                if (board[x][y] == board[x - 1][y + 1] && board[x][y] != 0 && board[x][y] == 1) {//looks at the one diagnial from it and compares as long as its not a zero
                    inADiag++;
                }
                else { //if blocked by a diffrent piece or blank space resets counter
                    inADiag = 0;
                }
                if (inADiag == 3) return true; //catch a win
                x--;
                y++;
            }
        }
        else { //middle two dagnals
            while (x > 0 && y < 3) { //left facing
                if (board[x][y] == board[x - 1][y + 1] && board[x][y] != 0 && board[x][y] == 1) {//looks at the one diagnial from it and compares as long as its not a zero
                    inADiag++;
                }
                else { //if blocked by a diffrent piece or blank space resets counter
                    inADiag = 0;
                }
                if (inADiag == 3) return true; //catch a win
                x--;
                y++;
            }
            y = 0;
            x = i;
            while (x < 6 && y < 3) { //right facing
                if (board[x][y] == board[x + 1][y + 1] && board[x][y] != 0 && board[x][y] == 1) { //looks at the one diagnial from it and compares as long as its not a zero
                    inADiag++;
                }
                else { //if blocked by a diffrent piece or blank space resets counter
                    inADiag = 0;
                }
                if (inADiag == 3) return true; //catch a win
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
            if (board[x][y] == board[x - 1][y - 1] && board[x][y] != 0 && board[x][y] == 1) {//looks at the one diagnial from it and compares as long as its not a zero
                inADiag++;
            }
            else { //if blocked by a diffrent piece or blank space resets counter
                inADiag = 0;
            }
            if (inADiag == 3) return true; //catch a win
            x--;
            y--;
        }
        x = i;
        y = 5;
        while (x < 6 && y > 0) { //right facing
            if (board[x][y] == board[x + 1][y - 1] && board[x][y] != 0 && board[x][y] == 1) {//looks at the one diagnial from it and compares as long as its not a zero
                inADiag++;
            }
            else { //if blocked by a diffrent piece or blank space resets counter
                inADiag = 0;
            }
            if (inADiag == 3) return true; //catch a win
            x++;
            y--;
        }
    }
    return false;
}

void Game::printBoard() { //initial generation of empty board
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 7; x++) {
            std::cout << board[x][y];
        }
        std::cout << std::endl;
    }
}

void Game::reSetBoard() {
    for (int y = 0; y < 6; y++) { //incroment the y cord
        for (int x = 0; x < 7; x++) { //increment the x cord
            board[x][y] = 0; //sets every value to 0 initially
        }
    }
}

void positionSequence(int turn, unsigned long long int pos, unsigned long long int *positions) {
    int P;

    positions[0] = pos;

    for (int i = 1; i < turn; i++) { //determine the series of moves
        P = positions[i-1] / 7;
        positions[i-1] % 7 != 0 ? positions[i] = P + 1 : positions[i] = P;
    }
}

void calcMoves(unsigned long long int *positions, unsigned int *moveSequence, unsigned int turn) {
    for (int i = 0; i < turn; i++) {
        moveSequence[i] = positions[i] - 7 * (positions[i]/7);

        if (moveSequence[i] == 0) moveSequence[i] = 7;
    }
}

void Game::createBoard(unsigned int turn, unsigned long long int position) {
    positions = new unsigned long long int[turn];
    moveSequence = new unsigned int[turn];

    positionSequence(turn, position, positions);
    calcMoves(positions, moveSequence, turn);

    bool which = true;

    // for (int i = 0; i < turn; i++) { //for testing: prints moveSequence
    //     std::cout << moveSequence[i] << std::endl;
    // }

    // for (int i = 0; i < turn; i++) { //for testing: prints out positions
    //     std::cout << positions[i] << std::endl;
    // }

    Game::makeMove(4, which);
    which = !which;

    for (int i = turn - 1; i >= 0; i--) {
        Game::makeMove(moveSequence[i], which);
        which = !which;
    }

    delete[] positions;
    delete[] moveSequence;
}