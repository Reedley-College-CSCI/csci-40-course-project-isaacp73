#pragma once

class Game {
    private:
        int board[7][6];
    public:
        Game(); //initiate the game
        void reSetBoard();
        bool makeMove(int move, bool which);
        void printBoard();
        bool checkWin();
};