#include <string>
#include <iostream>
#include <sstream>
#include "FieldDifesa.h"

using namespace std;

FieldDifesa::FieldDifesa()
{
    defenceFieldPlayer[12][12];
}

void FieldDifesa::stampaCampoDifesa(char (&defenceFieldPlayer)[12][12])
{
    cout << "Campo difesa" << endl;
    cout << "\t";
    for (int col = 0; col < COLdef; col++)
    {
        cout << col + 1 << "\t";
    }
    cout << endl;
    // stampa righe senza J,K

    for (int i = 0; i < LINEdef; i++)
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

        for (int c = 0; c < COLdef; c++)
        {
            cout << defenceFieldPlayer[i][c] << "   |   ";
        }
        cout << endl;
    }
    cout << "\n";
}

/*
void FieldDifesa::printGrigliaVuotaDifesa(int LINEdef, int COLdef)
{
    // matrice[12]x[12]
    cout << "Campo difesa" << endl;
    cout << "\t";
    for (int col = 0; col < COLdef; col++)
    {
        cout << col + 1 << "\t";
    }
    cout << endl;
    // stampa righe senza J,K

    for (int i = 0; i < LINEdef; i++)
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

        for (int c = 0; c < COLdef; c++)
        {
            cout << "    |   ";
        }
        cout << endl;
    }
    cout << "\n";
}
*/