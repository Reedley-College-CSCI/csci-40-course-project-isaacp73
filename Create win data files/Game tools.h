#pragma once

class Game {
    private:
        int board[7][6];
        unsigned long long int *positions;
        unsigned int *moveSequence;
        bool makeMove(int move, bool which);
    public:
        Game();
        void reSetBoard();
        void createBoard(unsigned int turn, unsigned long long int position);
        void printBoard();
        bool checkWin();
};