#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cctype>

using namespace std;

char c;
string dots[7][7];
int turn, numOfAvailableMoves, player1score, player2score;
bool player1board[7][7];
bool player2board[7][7];

int whoseTurn(int v, int h, char ch);
void initializeboard();
void Yellow(string ch);
void insertMove(int v, int h, char ch);
void printb();
bool score(int i, int j);   // this function check if the new move make a closed square, if so it increases the score of the player

int main(int argc, char **argv)
{
    char ch;
    int m1, m2, row;

    Yellow("Enter your initial: ");

    cin >> c;
    cout << endl;
    numOfAvailableMoves = 84;
    player1score = 0;
    player2score = 0;

    initializeboard();
    

    while(numOfAvailableMoves != 0)
    {
        while (ch != 'V' && ch != 'v' && ch != 'H' && ch != 'h')
        {
            cout << "\nEnter V if you want to enter virtical move, H for hirozantal move: ";
            cin >> ch;
            //cout << ch;
        }
        turn =1;

        if (ch == 'H' || ch == 'h')
        {
            cout << "\nEnter your move codinates X-Y ,and the raw number[1-7]\n ex: 1 2 1 : ";
            cin >> m1 >> m2 >> row;

            if (m1 < 7 && m2 < 7 && row < 7)
            {
                m1--;
                m2--;
                row--;
                insertMove(m2, row, ch);
                printb();
            }
        }
        if (ch == 'v' || ch == 'V')
        {
            cout << "\nEnter your move codinates X-Y ,and the column number[1-7]\n ex: 1 2 1 : ";
            cin >> m1 >> m2 >> row;

            if (m1 < 8 && m2 < 8 && row < 7)
            {
                m2--;
                row--;
                insertMove(m2, row, ch);
                printb();
                turn = whoseTurn(m2, row, ch);
            }
        }
    }


    /* Needed Functions:

1- WHOSE turn
    return whose player turn is it
2- score
    return the score of both players
3- did the player move make a win
    3.1 if won put thier initial
    3.2 increase the score
    3.3 extend his turn by 1
4- a way of displaying the color of the opposite player moves
5- counting # available moves
6- dicleare who won

    */
    

    return 0;
}

void initializeboard()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            dots[i][j] = "    .";
            player1board[i][j] = false;
            player2board[i][j] = false;
        }
    }

    cout << "Game Board\n\n";
    cout << "      1    2    3    4    5    6    7\n";
    for (int i = 0; i < 7; i++)
    {
        cout << "\n"
             << i + 1 << " ";
        for (int j = 0; j < 7; j++)
        {
            cout << dots[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void Yellow(string ch)
{
    cout << "\x1B[33m"
         << ch
         << "\033[0m";
}
void insertMove(int v, int h, char ch)
{
    if (ch == 'V' || ch == 'v')
    {
        dots[v][h] = '/0';
        dots[v][h] = "|    ";
        if(turn == 1)
        {
            player1board[v][h]= true;
        }
        else{
            player2board[v][h]= true;
        }
    }
    if (ch == 'h' || ch == 'H')
    {
        dots[h][v] = "_____";
        if(turn == 1)
        {
            player1board[h][v]= true;
        }
        else{
            player2board[h][v]= true;
        }
    }
}
void printb()
{
    cout << "Game Board\n\n";
    cout << "      1    2    3    4    5    6    7\n";
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 7; j++)
        {
            if(player1board[i][j] == true)
            {
                Yellow(dots[i][j]);
            }
            else{
                cout << dots[i][j];
            }
            
        }
        cout << endl;
    }
    cout<<"\nYour score: "<< player1score << "\tAgent score: "<< player2score << endl;
}
int whoseTurn(int v, int h, char ch)
{
    
}
bool score(int i, int j)
{
    //int temp
    string temp;
    if (turn == 1)
    {
        if(i == 0) // if the move is on the top
        {
            if( player1board[j][i] == true && player1board[j][j] == true && player1board[i][i+1] == true )
            {
                player1score++;
                if(dots[j][i] == "|    ")
                {
                    temp = "| ";
                    temp += c;
                    temp = " ";
                    dots[j][i] = temp;
                }
                return true;

            }
        }
        if(i==6)  // if the move is in the bottom
        {
            
        }
        if(j == 0)  // if the move is on the left
        {}
        if (j == 6) // if the move is on the right
        {}
        else{

        }

    }
    return false;
}