// BGM(): Colapietro Mattia, Santoro Giuseppe, Sgaravatto Giovanni
// main
#include <iostream>
#include <string>
#include "ShipSupporto.h"
#include "ShipCorazzata.h"
#include "ShipSottomarino.h"

using namespace std;

// creo il campo
const int COL = 12;
const int LINE = 12;

char YourField[LINE][COL];
char AttackField[LINE][COL];

// MAIN
int main()
{
    string battleship;
    string support;
    string submarine;

    // Creiamo gli oggetti ship
    ShipCorazzata naveDaBattaglia;
    ShipSupporto naveDiSupporto;
    ShipSottomarino sottomarino;

    //stampo il campo
    cout << "\t";
    for (int i = 1; i <= 12; i++)
    {
        cout << i << "\t";
    }
    cout << endl;

    for (int i = 0; i < LINE; i++)
    {
        cout << i + 1 << "\t";
        for (int c = 0; c < COL; c++)
        {
            cout << "    |   ";
        }
        cout << endl;
    }

    return 0;
}