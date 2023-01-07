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
    // questo deve essere un array di puntatori se avete usato i puntatoris
    char attackField[LINE][COL];
    for (int i = 0; i <= LINE; i++)
    {
        for (int c = 0; c <= COL; c++)
        {
            attackField[i][c] = ' ';
        }
        
    }
    
    FieldAttacco atkField;
    FieldDifesa defField;

    //stampiamo la griglia d'attacco
    atkField.printGrigliaVuotaAttacco(LINE,COL);

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
   
    for (int i = 0; i < 2; i++)
    {
        cout << "Inserisci le coordinate della " << i + 1 << " corazzata\n";
        getline(std::cin, coordinata);
        atkField.convertStringToInt(coordinata,attackField);
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "Inserisci le coordinate della " << i + 1 << " nave di supporto\n";
        getline(std::cin, coordinata);
        atkField.convertStringToInt(coordinata,attackField);
    }
    for (int i = 0; i < 1; i++)
    {
        cout << "Inserisci le coordinate del " << i + 1 << " sottomarino\n";
        getline(std::cin, coordinata);
        atkField.convertStringToInt(coordinata,attackField);
    }
    atkField.stampaCampoAttacco(attackField);
    
   
   
   
   
    
    return 0;
}
