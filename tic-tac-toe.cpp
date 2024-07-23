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


int main()
{  
    FieldCreation();
    cout << "match begins" << endl << "first player starts with X" << endl;
    while (moveCounter < 9)
    {
        InputCharacter(playerCounter);
        if (playerCounter == 1) playerCounter = 2;
        else playerCounter = 1;
        moveCounter++;
    }
    
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

    if (playerCounter == 1)
    {
        cout << "It's players 1 move" << endl << "insert X: ";
    }
    else
    {
        cout << "It's players 2 move" << endl << "insert 0: ";
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
                }
            }
        }
    }
    else
    {
        cout << "wrong character" << endl;
        InputCharacter(playerCounter);
    }
}

void FieldPrint()
{
    e = 0;
    i = 0;

    while (i < 3)
    {
        while (e < 3)
        {
            cout << field[i][e];
            if (e != 2)
            {
                cout << " | ";
            }
            e++;
        }
        e = 0;
        cout << endl;
        i++;
    }
}

void CheckfForWin()
{
    e = 0;
    i = 0;

    char f, s, t;


    while(i < 3)
    {
        while (e < 3)
        {
            
            e++;
        }
        i++;
    }
}

