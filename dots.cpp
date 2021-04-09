#include <iostream>
#include <stdlib.h>

using namespace std;

char c;
string dots[7][7];
bool player1board[7][7];
bool player2board[7][7];

void initializeboard();
void Yellow(string ch);
void insertMove(int v, int h, char ch);
void printb();

int main(int argc, char **argv)
{
    char ch;
    int m1, m2, row;

    Yellow("Enter your initial: ");

    cin >> c;
    cout << endl;

    initializeboard();

    while (ch != 'V' && ch != 'v' && ch != 'H' && ch != 'h')
    {
        cout << "\nEnter V if you want to enter virtical move, H for hirozantal move: ";
        cin >> ch;
        cout << ch;
    }

    while (true)
    {
        if (ch == 'H' || ch == 'h')
        {
            cout << "\nEnter your move codinates X-Y ,and the raw number\n ex: 0 1 1 : ";
            cin >> m1 >> m2 >> row;

            if (m1 < 7 && m2 < 7 && row < 7)
            {
                m1--;
                m2--;
                row--;
                insertMove(m2, row, ch);
                break;
            }
        }
        if (ch == 'v' || ch == 'V')
        {
            cout << "\nEnter your move codinates X-Y ,and the column number[1-6]\n ex: 0 1 1 : ";
            cin >> m1 >> m2 >> row;

            if (m1 < 8 && m2 < 8 && row < 7)
            {
                //m1--;
                m2--;
                row--;
                insertMove(m2, row, ch);
                break;
            }
        }
    }

    printb();

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
    cout << "    1    2    3    4    5    6    7\n";
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
    cout << "\n\n ?????????????\n\n";
    if (ch == 'V' || ch == 'v')
    {
        dots[v][h] = '/0';
        dots[v][h] = "    |";
        cout << "Inserted -> " << dots[h][v] << endl;
    }
    if (ch == 'h' || ch == 'H')
    {
        dots[h][v] = "__";
    }
}
void printb()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {

            cout << dots[i][j];
        }
        cout << endl;
    }
}