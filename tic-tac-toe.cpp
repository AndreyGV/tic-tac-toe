#include <iostream>

using namespace std;

char field[3][3];

int i = 0;
int e = 0;

int playerCounter = 1;
int moveCounter = 0;

void FieldPrint();
void FieldCreation();
void InputCharacter(int playerCount);
bool CheckForWin();


int main()
{  
    int newMatch;

    FieldCreation();
    cout << "match begins" << endl << "first player starts with X" << endl;
    while (true)
    {
        InputCharacter(playerCounter);
        if (CheckForWin() == true)
        {
            if (playerCounter == 1) cout << "player 1 won";
            else cout << "player 2 won";
            break;
        }

        if (playerCounter == 1) playerCounter = 2;
        else playerCounter = 1;

        moveCounter++;

        if (moveCounter == 9)
        {
            cout << "it's a draw";
            break;
              
        }
    }

    playerCounter = 1;
    cout << " do you want to play again?" << endl << " type in 1 if you want to play again and 0, if you want to quit" << endl;
    cin >> newMatch;
    if (newMatch == 1) main();
    else cout << "good bye";
}

void FieldCreation()
{
    int counter = 0;
    char numbers[] = { '1','2','3','4','5','6','7','8','9' };

    while (i < 3)
    {
        while (e < 3)
        {
            field[i][e] = (char)numbers[counter];
            e++;
            counter++;
        }
        e = 0;
        i++;
    }
    FieldPrint();
}

void InputCharacter(int playerCounter)
{   
    char currentCharacter;
    bool isTaken = false;

    if (playerCounter == 1)
    {
        cout << "It's players 1 move" << endl << "insert X: ";
    }
    else
    {
        cout << "It's players 2 move" << endl << "insert O: ";
    }

    cin >> currentCharacter;

    if (currentCharacter > '0' && currentCharacter < '10')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int e = 0; e < 3; e++)
            {
                if (field[i][e] == currentCharacter)
                {
                    if (playerCounter == 1)
                    {
                        field[i][e] = 'X';
                    }
                    else
                    {
                        field[i][e] = 'O';
                    }
                    FieldPrint();
                    isTaken = true;
                }
            }
        }
    }
    else
    {
        cout << "wrong character" << endl;
        InputCharacter(playerCounter);
    }
    if (isTaken == false)
    {
        cout << "wrong position" << endl;
        InputCharacter(playerCounter);
    }
}

void FieldPrint()
{
    e = 0;
    i = 0;
    cout << "-----------" << endl;

    while (i < 3)
    {
        while (e < 3)
        {
            cout << ' ' << field[i][e] << ' ';
            if (e != 2)
            {
                cout << "|";
            }
            e++;
        }
        cout << endl << "-----------" << endl;
        e = 0;
        i++;
    }
}

void WhoWon(char firstPlace)
{

}

bool CheckForWin()
{
    e = 0;
    i = 0;

    bool isWon = false;


    while(i < 3)
    {
        if (field[i][0] == field[i][1] && field[i][0] == field[i][2])
        {
            //WhoWon(field[i][0]);
            isWon = true;
        }
        while (e < 3)
        {
            if (field[0][e] == field[1][e] && field[0][e] == field[2][e])
            {
                //WhoWon(field[0][e]);
                isWon = true;
            }
            e++;
        }
        i++;
    }
    if ((field[0][0] == field[1][1] && field[0][0] == field[2][2]) || (field[0][2] == field[1][1] && field[0][2] == field[2][0]))
    {
        //WhoWon(field[1][1]);
        isWon = true;
    }
    return isWon;
}



