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
    char attackField[COL][LINE];
    FieldAttacco atkField;
    FieldDifesa defField;

    // qua sbagliavate a passare la dimensione dell array, basta il nome della variabile
    // comunque mi sembra inutile fare un array di puntatori quindi eviterei
    //l'array di puntatori inchesenso? cancello il * in char? okz dappertutto, quindi tolgo tutti i puntatori nell'array
    // sono inutili, non ti serve avere un array di puntatori
    //comunque non mettere piu' le dimensioni ad attackfield quando lo passi a una funzione
    atkField.stampaCampoAttacco(attackField);
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
