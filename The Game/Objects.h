#pragma once
#include <string>
#include <iostream>

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
        int copy[7][6];
        unsigned int move;
        unsigned int Turn;
        unsigned int numFiles;
        //in Bot algorithms.cpp
        int compute();
        int checkFiles();
        bool oneMoveWins(int playerOrBot);
        bool verifyWin(bool playerOrBot);
        bool findWin();
        void generateBoard(unsigned long long int position, unsigned int turn);
    public:
        Bot(int (*ptr)[6]);
        void PrintMove();
        int botMove(int turn);
};