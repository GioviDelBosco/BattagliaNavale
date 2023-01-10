#include <string>
#include <iostream>
#include <sstream>
#include "FieldAttacco.h"

using namespace std;

FieldAttacco::FieldAttacco()
{
    attackField[12][12];
}
void FieldAttacco::printGrigliaVuotaAttacco(int LINE, int COL)
{
    // matrice[12]x[12]
    cout << "Campo Attacco" << endl;
    cout << "\t";
    for (int col = 0; col < COL; col++)
    {
        cout << col + 1 << "\t";
    }
    cout << endl;
    // stampa righe senza J,K

    for (int i = 0; i < LINE; i++)
    {
        if (i == 9)
        {
            char NoJ = (char)(i + 67);
            cout << NoJ << "\t";
        }
        else if (i == 10)
        {
            char NoK = (char)(i + 67);
            cout << NoK << "\t";
        }
        else if (i == 11)
        {
            char JumpL = (char)(i + 67);
            cout << JumpL << "\t";
        }
        else
        {
            char IndexLine = (char)(i + 65);
            cout << IndexLine << "\t";
        }

        for (int c = 0; c < COL; c++)
        {
            cout << "    |   ";
        }
        cout << endl;
    }
    cout << "\n";
}
void FieldAttacco::stampaCampoAttacco(char (&attackField)[12][12])
{
    cout << "Campo Attacco" << endl;
    cout << "\t";
    for (int col = 0; col < COLatk; col++)
    {
        cout << col + 1 << "\t";
    }
    cout << endl;
    // stampa righe senza J,K

    for (int i = 0; i < LINEatk; i++)
    {
        if (i == 9)
        {
            char NoJ = (char)(i + 67);
            cout << NoJ << "\t";
        }
        else if (i == 10)
        {
            char NoK = (char)(i + 67);
            cout << NoK << "\t";
        }
        else if (i == 11)
        {
            char JumpL = (char)(i + 67);
            cout << JumpL << "\t";
        }
        else
        {
            char IndexLine = (char)(i + 65);
            cout << IndexLine << "\t";
        }

        for (int c = 0; c < COLatk; c++)
        {
            cout << attackField[i][c] << "   |   ";
        }
        cout << endl;
    }
    cout << "\n";
}