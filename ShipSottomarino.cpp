#include "ShipSottomarino.h"
#include "Coordinate.h"
#include "FieldDifesa.h"
#include "FieldAttacco.h"

using namespace std;
ShipSottomarino::ShipSottomarino()
{
    dimensione = 1;
    corazza = 1;
}

//nel main mettiamo che AA AA cancella tutte le Y nell'attack field
void ShipSottomarino::muoviECerca(char (&attackFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12], char (&defenceFieldPlayer)[12][12], string coordinata)
{
    vector<int> coordinataSpostamento = Coordinate::convertStringToInt(coordinata);
    // sposto la barca in modo semplice perche' e' dim 1
    if (defenceFieldPlayer[coordinataSpostamento[2]][coordinataSpostamento[3]] == ' ')
    {
        defenceFieldPlayer[coordinataSpostamento[2]][coordinataSpostamento[3]] = 'E';
        defenceFieldPlayer[coordinataSpostamento[0]][coordinataSpostamento[1]] = ' ';
    }else{
        cout << "La casella non e' libera!!!"<<endl;
    }

    for (int i = 0; i < 5; i++) // linea
    {
        for (int c = 0; c < 5; c++) // column
        {
            int x = coordinataSpostamento[0] - 2 + i;
            int y = coordinataSpostamento[1] - 2 + c;
            cout<<x<<" - "<<y<<endl;
            if (defenceFieldCPU[x][y] != ' ')
            {
                attackFieldPlayer[x][y] = 'Y';
            }
        }
    }
}
