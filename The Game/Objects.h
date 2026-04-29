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
        void newPlayer();
        void sortData(const int& type);
        bool findPlayer(std::string name);
    public:
        PlayerData();
        void displayPlayerData();
        void updateData(bool botOrPlayerWin);
        std::string printName() {
            return name;
        }
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
        int Turn;
    public:
        Bot(int (*ptr)[6]);
        void PrintMove();
        int botMove(int turn);
        int compute();
        int checkFiles();
        bool oneMoveWins(int playerOrBot);
        bool checkIfWin(bool playerOrBot);
};