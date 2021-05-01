#include "game.h"

// prints the current board
void Game::printb()
{
    int number =1;
    cout << "Game Board\n\n";
    cout << "1    2    3    4    5    6    7\n";
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if(playerboard[i][j] == true && Agentboard[i][j] == false)
            {
                    Yellow(dots[i][j]);
            }
            else{
                    cout << dots[i][j];
            }      
        }
        if(i%2 == 0)
        {
            cout <<number;
            number++;
        }
        cout << endl;
    }
    cout<<"\nYour score: "<< playerscore << "\tAgent score: "<< Agentscore << endl;
}

bool Game::AgentTurn() 
{
    int Agentlines =0, playerlines =0;
    for (int i =0; i < 13; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            if(Agentboard[i][j])
            {
                Agentlines++;
            }   
            if(playerboard[i][j])
            {
                playerlines++;
            } 
        }
    } 

    Agentlines = Agentlines - Agentscore;
    playerlines = playerlines - playerscore;

    if(playerlines < Agentlines)
    {
        return false;
    }
    return true;
}

void Game::update(bool Agentplaying, int y, int n)
{
    if(Agentplaying)
        {
            Agentboard[y][n]= true;
            availableMove[y][n]= false;
            if (score(y,n))
            {
                Agentscore++;
            }
            
        }
    else{
        playerboard[y][n]= true;
        availableMove[y][n]= false;
        if (score(y,n))
        {
            playerscore++;
        }
    }
}

bool Game::score(int i, int j)
{
    // if the move was on the left edge, chech towards the right
    if( i%2 != 0)
    {
        if(i%2 != 0 && j ==0)
        {
            if(checkright(i,j))
            {
                //cout << "BUG !!!!!!!/n";
                return true;
            } 
            return false;
        }
        else if(i%2 != 0 && j == 6)
        {
            if(checkleft(i,j))
            { //cout << " BUG !!!!!!!/n";  
                return true;
            } 
            return false;
        }
        else{
            if(checkleft(i,j) || checkright(i,j) )
            {//cout << "BUG !!!!!!!/n";
                return true;
            }
            return false;
        } 
    }

    if (i == 0)
    {
        if(checkdown(i,j))
        {//cout << "BUG !!!!!!!/n";
            return true;
        } 
        return false;
    }
    else if (i == 12)
    { 
        if(checkup(i,j))
        {//cout << "BUG !!!!!!!/n";
            return true;
        } 
        return false;
    }
    else{
        if(checkup(i,j) || checkdown(i,j))
        {//cout << "@@@@@@@@@@@@@ BUG !!!!!!!/n";
            return true;
        }
        return false;
    }  
       
}

bool Game::checkright(int i, int j)
{
    if( (playerboard[i-1][j] || Agentboard[i-1][j]) && (playerboard[i][j+1] || Agentboard[i][j+1]) && (playerboard[i+1][j] || Agentboard[i+1][j]))
    {
        return true;
    }
    return false;
}
bool Game::checkleft(int i, int j)
{
    //cout << "Left Checked\n";
    if( (playerboard[i-1][j-1] || Agentboard[i-1][j-1]) && (playerboard[i][j-1] || Agentboard[i][j-1]) && (playerboard[i+1][j-1] || Agentboard[i+1][j-1]))
    {
        //cout << "Left scored\n";
        return true;
    }
    return false;

}
bool Game::checkdown(int i, int j)
{
    if((playerboard[i+2][j] || Agentboard[i+2][j]) && (playerboard[i+1][j] || Agentboard[i+1][j]) && (playerboard[i+1][j+1] || Agentboard[i+1][j+1]))
    {
        return true;
    }
    return false;
}
bool Game::checkup(int i, int j)
{
    if((playerboard[i-2][j] || Agentboard[i-2][j]) && (playerboard[i-1][j] || Agentboard[i-1][j]) && (playerboard[i-1][j+1] || Agentboard[i-1][j+1]))
    {
        return true;
    }
    return false;
}
void Game::assignevl(int x , int n, bool Agentplaying)
{
    dots[x][n] = "|    ";
    update(Agentplaying,x,n);   
}

void Game::assignehl(int x,int n, bool Agentplaying)
{
    dots[x][n] = "+----";
    update(Agentplaying,x,n);
} 

void Game::insertMove(int n, int x, int y, char ch, bool Agentplaying)
{
    if (ch == 'V' || ch == 'v')
    {
        if (x==1&& y==2)
        {
            assignevl(x,n-1, Agentplaying);
        }
        else if (y ==3)
        {
            assignevl(y,n-1, Agentplaying);
        }
        else if (y == 4)
        {
            assignevl(y+1,n-1, Agentplaying);
        }
        else if (y ==5)
        {
            assignevl(y+2,n-1, Agentplaying);  
        }
        else if (y ==6)
        {
            assignevl(y+3,n-1, Agentplaying);  
        }
        else{
            assignevl(y+4,n-1, Agentplaying);
        } 
        
        
    }
    
    if (ch == 'h' || ch == 'H')
    {
        if (n == 1)
        {
            assignehl(n-1,x-1, Agentplaying);
        }
        else if (n == 2)
        {
            assignehl(n,x-1, Agentplaying);
        }
        else if (n == 3)
        {
            assignehl(n+1,x-1, Agentplaying);
        }
        else if (n == 4)
        {
            assignehl(n+2,x-1, Agentplaying);
        }
        else if (n == 5)
        {
            assignehl(n+3,x-1, Agentplaying);  
        }
        else if (n == 6)
        {
            assignehl(n+4,x-1, Agentplaying);  
        }
        else{
            assignehl(n+5,x-1, Agentplaying); 
        } 
    }
}

void Game::Yellow(string ch)
{
    cout << "\x1B[33m"
         << ch
         << "\033[0m";
}

void Game::initializeboard()
{
    Agentscore = 0;
    playerscore = 0;
    
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if((i%2) == 0 || i == 0 )
            {
                if(j==6)
                {
                    playerboard[i][j] = true;
                    Agentboard[i][j] = true;
                }
                else{
                    playerboard[i][j] = false;
                    Agentboard[i][j] = false;
                }
                dots[i][j] = "+    "; 
            }
            else
            {
                dots[i][j] = "     ";
                playerboard[i][j] = false;
                Agentboard[i][j] = false;
            }
            availableMove[i][j] = true;
        }



    }
    int number= 1;
    cout << "Game Board\n\n";
    cout << "1    2    3    4    5    6    7\n";
    
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            //cout << "------->"<<i<<endl;
            cout << dots[i][j];
            //cout << i <<" - "<<j<< endl;
        }
        if(i%2 == 0)
        {
            cout <<number;
            number++;
        }
        cout << endl;
    }
    cout << endl;
}

void Game::setInitial(char c){
    initial = c;
}

int Game::numAvailable()
{
    int num;
    for(int i =0; i< 13; i++)
    {
        for(int j =0; j<7; j++)
        {
           if(!Agentboard[i][j] && !playerboard[i][j])
            {
                num++;
            }
        }
    }
    return num;
}

int Game::evaluatestate(Game b)
{
    return Agentscore-playerscore;
}

void Game::insertagentmove(int x, int y )
{
    if(x%2 == 0)
    {
        assignehl(x,y, true);
    }
    else
    {
        assignevl(x,y,true);
    }
}

void Game::setrandom(int i)
{
    this->root2 = i;
}
int Game::getrand()
{
    return this->root2 ;
}

void Game::decreasenumavailable()
{
    numOfAvailableMoves = numOfAvailableMoves -1;
}