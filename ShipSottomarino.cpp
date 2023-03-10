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
    if (defenceFieldPlayer[coordinataSpostamento[2]][coordinataSpostamento[3]] == '-')
    {
        defenceFieldPlayer[coordinataSpostamento[2]][coordinataSpostamento[3]] = 'E';
        defenceFieldPlayer[coordinataSpostamento[0]][coordinataSpostamento[1]] = '-';
    }else if(defenceFieldPlayer[coordinataSpostamento[2]][coordinataSpostamento[3]]=='E'){
        defenceFieldPlayer[coordinataSpostamento[2]][coordinataSpostamento[3]] = 'E';
    }else{
        cout << "La casella non e' libera o c'e' gia' un sottomarino!!!"<<endl;
    }

    for (int i = 0; i < 5; i++) // linea
    {
        for (int c = 0; c < 5; c++) // column
        {
            int x = coordinataSpostamento[0] - 3 + i;
            int y = coordinataSpostamento[1] - 2 + c;
            if (defenceFieldCPU[x][y] != '-')
            {
                attackFieldPlayer[x][y] = 'Y';
            }
        }
    }
}
