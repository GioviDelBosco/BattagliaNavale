// BGM(): Colapietro Mattia, Santoro Giuseppe, Sgaravatto Giovanni
// main
#include <iostream>
#include <string>
#include <sstream>
#include "ShipSupporto.h"
#include "ShipCorazzata.h"
#include "ShipSottomarino.h"
#include "FieldAttacco.h"
#include "FieldDifesa.h"

using namespace std;


int main()
{
    char AttackField[12][12];
    FieldAttacco atkField;
    FieldDifesa defField;

    atkField.StampaCampoAttacco(LINE, COL, &AttackField[12][12]);
    string coordinata;

    // Creiamo gli oggetti ship
    ShipCorazzata naveDaBattaglia;
    ShipSupporto naveDiSupporto;
    ShipSottomarino sottomarino;

    // stampo gli indici delle colonne numerate
    /*
        >> Quali sono le coordinate per la corazzata 1:
        >> B6 B10
    */
   /*
   for (int i = 0; i < 1; i++)
    {
        cout << "Inserisci le coordinate della " << i + 1 << " corazzata\n";
        getline(std::cin, coordinata);
        // stringstream ss(coordinata);
        atkField.ConvertStringToInt(coordinata,AttackField[12][12]);
    }
   */
   
   
    
    return 0;
}
