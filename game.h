#ifndef GAME_H 
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>

using namespace std;

class Game 
{

    public:
    int root2;
    int  numOfAvailableMoves, Agentscore, playerscore;
    bool playerboard[13][7];
    bool Agentboard[13][7];
    string dots[13][7];
    string dotsdots[7][6];
    int alpha = -5000, beta= 5000;
    bool availableMove[13][6];
    void update(bool, int,int);
    char initial;
    void setInitial(char);
    bool AgentTurn();
    void initializeboard();
    void Yellow(string ch);
    void insertMove(int n, int v, int h, char ch,bool);
    void printb();
    bool score(int, int );   // this function check if the new move make a closed square, if so it increases the score of the player 
    int evaluatestate(Game); // (Return a state after action a taken in state s)
    bool checkright(int, int );
    bool checkleft(int, int );
    bool checkup(int, int );
    bool checkdown(int, int );
    int numAvailable();
    void decreasenumavailable();
    void assignevl(int, int, bool);
    void assignehl(int,int, bool);
    void insertagentmove(int, int);
    int numavail(int);
    void setrandom(int i);
    int getrand();
};

#endif