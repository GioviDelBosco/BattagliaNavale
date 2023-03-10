#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "Player.h"
#include "Coordinate.h"
#include "FieldDifesa.h"

using namespace std;

FieldDifesa defField;

Player::Player()
{
}
// tolgo le coordinate e uso un vettore
void Player::piazzaBarca(int flag, char (&defenceFieldPlayer)[12][12], string coordinata)
{
    vector<int> listacoordinate = Coordinate::convertStringToInt(coordinata);

    switch (flag)
    {

    // corazzata
    case 0:
        // se le Y nella mappa sono le stesse, scrive solo nelle X
        if (listacoordinate[1] == listacoordinate[3])
        {
            for (int i = listacoordinate[0]; i <= listacoordinate[2]; i++)
            {
                defenceFieldPlayer[i][listacoordinate[1]] = 'C';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (listacoordinate[0] == listacoordinate[2])
        {
            for (int i = listacoordinate[1]; i <= listacoordinate[3]; i++)
            {
                defenceFieldPlayer[listacoordinate[0]][i] = 'C';
            }
        }
        break;
    // supporto
    case 1:
        // se le Y nella mappa sono le stesse, scrive solo nelle X
        if (listacoordinate[1] == listacoordinate[3])
        {
            for (int i = listacoordinate[0]; i <= listacoordinate[2]; i++)
            {
                defenceFieldPlayer[i][listacoordinate[1]] = 'S';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (listacoordinate[0] == listacoordinate[2])
        {
            for (int i = listacoordinate[1]; i <= listacoordinate[3]; i++)
            {
                defenceFieldPlayer[listacoordinate[0]][i] = 'S';
            }
        }
        break;
    // sottomarino
    case 2:
        if (listacoordinate[1] == listacoordinate[3])
        {
            for (int i = listacoordinate[0]; i <= listacoordinate[2]; i++)
            {
                defenceFieldPlayer[i][listacoordinate[1]] = 'E';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (listacoordinate[0] == listacoordinate[2])
        {
            for (int i = listacoordinate[1]; i <= listacoordinate[3]; i++)
            {
                defenceFieldPlayer[listacoordinate[0]][i] = 'E';
            }
        }
        break;
    }
}
