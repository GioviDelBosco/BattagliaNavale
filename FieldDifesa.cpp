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

void FieldDifesa::convertStringToInt(string coordinata, int flag, char (&defenceFieldPlayer)[12][12])
{
    stringstream ss(coordinata);
    // creo le 2 variabili per il posizionamneto della barca
    string coordinateXYi, coordinateXYf;
    ss >> coordinateXYi >> coordinateXYf;

    string Xo = coordinateXYi.substr(0, 1);
    string Yo = coordinateXYi.substr(1, coordinateXYi.length() - 1);
    string Xe = coordinateXYf.substr(0, 1);
    string Ye = coordinateXYf.substr(1, coordinateXYf.length() - 1);
    int Xi;
    int Yi = stoi(Yo) - 1;
    int Xf;
    int Yf = stoi(Ye) - 1;
    char elem = Xo.at(0);
    if (isalpha(elem))
    {
        elem = toupper(elem);
        Xi += static_cast<int>(elem - 'A' + 1) - 1;
        if (Xi >= 10)
        {
            Xi = Xi - 2;
        }
    }

    char elem2 = Xe.at(0);
    {
        if (isalpha(elem2))
        {
            elem2 = toupper(elem2);
            Xf += static_cast<int>(elem2 - 'A') - 1;
            if (Xf >= 10)
            {
                Xf = Xf - 2;
            }
        }
    }
    switch (flag)
    {

    // corazzata
    case 0:
        // se le Y nella mappa sono le stesse, scrive solo nelle X
        if (Yi == Yf)
        {
            for (int i = Xi; i <= Xf; i++)
            {
                defenceFieldPlayer[i][Yi] = 'C';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (Xi == Xf)
        {
            for (int i = Yi; i <= Yf; i++)
            {
                defenceFieldPlayer[Xi][i] = 'C';
            }
        }
        break;
    // supporto
    case 1:
        // se le Y nella mappa sono le stesse, scrive solo nelle X
        if (Yi == Yf)
        {
            for (int i = Xi; i <= Xf; i++)
            {
                defenceFieldPlayer[i][Yi] = 'S';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (Xi == Xf)
        {
            for (int i = Yi; i <= Yf; i++)
            {
                defenceFieldPlayer[Xi][i] = 'S';
            }
        }
        break;
    // sottomarino
    case 2:
        // se le Y nella mappa sono le stesse, scrive solo nelle X
        if (Yi == Yf)
        {
            for (int i = Xi; i <= Xf; i++)
            {
                defenceFieldPlayer[i][Yi] = 'E';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (Xi == Xf)
        {
            for (int i = Yi; i <= Yf; i++)
            {
                defenceFieldPlayer[Xi][i] = 'E';
            }
        }
        break;
    }
}