#include <string>
#include <iostream>
#include <sstream>
#include "FieldDifesa.h"
#include <fstream>

using namespace std;

FieldDifesa::FieldDifesa()
{
    defenceFieldPlayer[12][12];
}

void FieldDifesa::stampaCampoDifesa(char (&defenceFieldPlayer)[12][12])
{
    ofstream fout("replica.txt");
    cout << "Campo difesa" << endl;
    fout<<"Campo difesa" << endl;
    cout << "\t";
    fout<< "\t";
    for (int col = 0; col < COLdef; col++)
    {
        cout << col + 1 << "\t";
        fout<< col + 1 << "\t";
    }
    cout << endl;
    fout<<endl;
    // stampa righe senza J,K

    for (int i = 0; i < LINEdef; i++)
    {
        if (i == 9)
        {
            char NoJ = (char)(i + 67);
            cout << NoJ << "\t";
            fout<< NoJ << "\t";
        }
        else if (i == 10)
        {
            char NoK = (char)(i + 67);
            cout << NoK << "\t";
            fout<<NoK << "\t";
        }
        else if (i == 11)
        {
            char JumpL = (char)(i + 67);
            cout << JumpL << "\t";
            fout<< JumpL << "\t";
        }
        else
        {
            char IndexLine = (char)(i + 65);
            cout << IndexLine << "\t";
            fout<<IndexLine << "\t";
        }

        for (int c = 0; c < COLdef; c++)
        {
            cout << defenceFieldPlayer[i][c] << "   |   ";
            fout << defenceFieldPlayer[i][c] << "   |   ";
        }
        cout << endl;
        fout<<endl;
    }
    cout << "\n";
    fout<<"\n";
}