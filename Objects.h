#pragma once
#include <string>

class PlayerData {
    private:
        std::string name;
        unsigned int playerWins;
        unsigned int botwins;
        struct dataStruct {
            std::string name;
            unsigned int botWins;
            unsigned int playerWins;
        };
    public:
        PlayerData();
        bool findPlayer(std::string name);
        void newPlayer();
        void displayPlayerData();
        void sortData(const int& type);
};

class Game {
    private:
        int (*board)[6];
    public:
        Game(int (*ptr)[6]); //initiate the game
        bool makeMove(int move, bool which);
        void printBoard();
        bool checkWin();
};

class Bot {
    private:
        int (*board)[6];
        int move;
    public:
        Bot(int (*ptr)[6]);
        void PrintMove();
        int botMove();
        bool oneMoveWins(int playerOrBot);
        bool checkIfWin(bool playerOrBot);
};