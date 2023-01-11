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
    char defenceFieldPlaye[LINEdef][COLdef];
    for (int i = 0; i <= LINEdef; i++)
    {
        for (int c = 0; c <= COLdef; c++)
        {
            defenceFieldPlaye[i][c] = ' ';
        }
        
    }
    
    FieldAttacco atkField;
    FieldDifesa defField;

    //stampiamo la griglia d'attacco
    cout<<"Inserisci il comando speciale XX XX per visualizzare le griglie\n";
    string stampaCampi;
    getline(std::cin, stampaCampi);
    if(stampaCampi=="XX XX"){

        defField.printGrigliaVuotaDifesa(LINEdef,COLdef);
        atkField.printGrigliaVuotaAttacco(LINEatk,COLatk);
    }
    else{
        cout<<"comando errato\n";
    }
    
    int flag=0;
    string coordinata;

    // Creiamo gli oggetti ship
    ShipCorazzata naveDaBattaglia;
    ShipSupporto naveDiSupporto;
    ShipSottomarino sottomarino;

    //inserisco una barca
    for (int i = 0; i < 2; i++)
    {
        cout << "Inserisci le coordinate della " << i + 1 << " navecorazzata\n";
        getline(std::cin, coordinata);
        defField.convertStringToInt(coordinata,flag,defenceFieldPlaye);
    }

    for (int i = 0; i < 2; i++)
    {
        flag=1;
        cout << "Inserisci le coordinate della " << i + 1 << " nave supporto\n";
        getline(std::cin, coordinata);
        defField.convertStringToInt(coordinata,flag,defenceFieldPlaye);
    }

    for (int i = 0; i < 1; i++)
    {
        flag=2;
        cout << "Inserisci le coordinate del " << i + 1 << " sottomarino\n";
        getline(std::cin, coordinata);
        defField.convertStringToInt(coordinata,flag,defenceFieldPlaye);
    }
    
    
    defField.stampaCampoDifesa(defenceFieldPlaye);
    return 0;
}