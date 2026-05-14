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
        
        bool findPlayer(std::string name);
    public:
        PlayerData();
        PlayerData(bool noName) {}
        void sortData(const int& type);
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
        bool checkWin(int which);
};

class Bot {
    private:
        int (*board)[6];
        int copy[7][6];

        struct MoveSequence {
            unsigned int moves;
            bool ilegalMove[7];
        };

        //used only in compute and it's functions
        MoveSequence *moveSequence;
        unsigned int turnsAhead;
        unsigned int size; //size of moveSequence array
        const unsigned int SIZE_INCRAMENT = 10;

        unsigned int move;
        unsigned int Turn;

        unsigned int numFiles;
        
        //functions used in compute
        void reSizeArr();
        bool incramentMoveSequence(long int size);
        void makeMoveSequence(Game& copyOfBoard);
        void resetCopy();

        //functions used in botMove
        bool oneMoveWins(int playerOrBot);
        bool verifyWin(bool playerOrBot);
        int checkFiles();
        void compute();
    public:
        Bot(int (*ptr)[6]);
        ~Bot();
        int botMove(int turn);
        void printMoveSequence();
};