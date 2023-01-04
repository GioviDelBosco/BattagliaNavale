#include <string>
#include <iostream>
#include <sstream>
#include "FieldAttacco.h"

using namespace std;

FieldAttacco::FieldAttacco()
{
    AttackField[COL][LINE];
}

void stampaCampoAttacco(int line, int col, char AttackField[COL][LINE])
{
    for (int i = 1; i <= COL; i++)
    {
        for (int j = 1; j <= LINE; j++)
        {
            cout << "|   " << AttackField[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void printGrigliaVuotaAttacco(int LINE, int COL)
{
    // matrice[12]x[12]
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

void ConvertStringToInt(string coordinata, char AttackField[12][12])
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
    int Yi = stoi(Yo);
    int Xf;
    int Yf = stoi(Ye);
    for (auto &elem : Xo)
    {
        if (isalpha(elem))
        {
            elem = toupper(elem);
            Xi += static_cast<int>(elem - 'A'); // DA CAPIRE PERCHé SENZA IL +1
        }
    }

    for (auto &elem : Xe)
    {
        if (isalpha(elem))
        {
            elem = toupper(elem);
            Xf += static_cast<int>(elem - 'A' + 1);
        }
    }
    if (Xi == Xf)
        for (int i = Yi; i < Yf + 1; i++)
            AttackField[Xi][i] = 'C'; // tieni fissa la riga, cambia colonna
    else
        for (int i = Xi; i < Xf + 1; i++)
            AttackField[i][Yi] = 'C';
}