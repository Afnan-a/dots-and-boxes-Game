#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <ncurses.h>
#include "game.h"
#include <vector>
#include <map>
//#include<bits/stdc++.h>

using namespace std;


int minimax(Game b2, vector<int> &, vector<int> &,vector<int> &, int depth, bool max);
void findActions(Game b, vector<int> &x, vector<int> &y);
int maximum;
int indext;

int main()
{
    Game b1;
    char c;
    int n,x,y, num = 85;

    vector<int> x1;
    vector<int> y1;
    //map<int,int> actions;

    /*cout << "Enter your initial: ";
    cin >> c;
    b1.setInitial(c); */
    b1.initializeboard();
    
    /*cout<< "Your Turn!" << endl;
    cout << "Enter 'v' and row number for virtical move OR 'h' and column number for horizontal move and two dots to connect EX: v 1 1 2: \n";
    cin >> c >> n >> x >> y;
    b1.insertMove(n,x,y,c,false);
    b1.decreasenumavailable();*/
    //b1.AgentTurn() = false;

    while(num > 0)
    {
        if(b1.AgentTurn() == 0)
        {
            cout<< "Your Turn!" << endl;
            cout << "Enter 'v' and row number for virtical move OR 'h' and column number for horizontal move and two dots to connect EX: v 1 1 2: \n";
            cin >> c >> n >> x >> y;
            b1.insertMove(n,x,y,c,false);
            b1.decreasenumavailable();
           // b1.setrandom(5);
          //  cout << "MAX: " << maximum <<"  indext:  "<< b1.getrand() << endl;
        }
        else
        {
            Game b2 = b1;  // copy object
            findActions(b2,x1,y1);
            vector<int> a(y1.size());
            minimax(b2, x1, y1,a, 3, true);
            b1.insertagentmove(x1.at(indext), y1.at(indext));
          cout << "MAX: " << maximum <<"  indext:  "<< indext << endl;
           // b2.printb();
        }
        b1.printb();
        num--;
    }    
    

    return 0;
}

int minimax(Game b, vector<int> &x, vector<int> &y,vector<int> &a, int depth, bool maxx)
{
    int bestmove, heuristic,x2,y2;
      

    if(depth ==0 || b.numAvailable() == 0)
    {
        // heuristic = b.evaluatestate(b);
        return (b.Agentscore - b.playerscore);
    }


    for(int i =0; i < y.size(); i++)
    {
        Game b2 = b;
        x2 = x.front(); y2 =  y.front();
        b2.update(maxx, x2,y2);
        y.erase(y.begin());
        x.erase(x.begin());
        
        if(maxx)
        {
           a.at(i)= minimax(b2, x, y,a, depth-1 , false);
        }
        else
        {
            a.at(i) = minimax(b2, x, y,a, depth-1 , true);
        }
        x.push_back(x2); y.push_back(y2);
    }

    maximum = -200;
    for(int i =0; i < a.size(); i++)
    {
        if(maximum < a.at(i))
        {
            maximum = a.at(i);
            indext = i;
        }
    }
}

void findActions(Game b, vector<int> &x, vector<int> &y)
{
    x.clear();
    y.clear();
    vector<int> pairs;
    int num =84;
    for(int i =0; i< 13; i++)
    {
        for(int j =0; j<7; j++)
        {
           if(!b.Agentboard[i][j] && !b.playerboard[i][j])
            {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
}