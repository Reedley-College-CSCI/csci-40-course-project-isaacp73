#pragma once

class PlayerData {
    private:
        string name;
        unsigned int playerWins;
        unsigned int botwins;
        struct dataStruct {
            string name;
            unsigned int botWins;
            unsigned int playerWins;
        };
    public:
        PlayerData();
        bool findPlayer(string name);
        void newPlayer();
        void displayPlayerData();
        void sortData(const int& type);
};

class Game {
    private:
        int board[7][6];
    public:
        Game(); //initiate the game
        bool makeMove(int move, bool which);
        void printBoard();
        bool checkWin();
        void copyBoard(int copy[7][6]);
};

class Bot {
    private:
        int copyOfBoard[7][6];
        int botMove;
    public:
        void copyBoard(int board[7][6]);
        int botMove();
        bool block(); //checks if the bot has to block any wins
};