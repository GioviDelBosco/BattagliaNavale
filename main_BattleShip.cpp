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
#include "Coordinate.h"
#include "Player.h"

using namespace std;

int main()
{
    // questo deve essere un array di puntatori se avete usato i puntatoris
    char defenceFieldPlayer[LINEdef][COLdef];
    char attackFieldPlayer[LINEatk][COLatk];

    for (int i = 0; i <= LINEdef; i++)
    {
        for (int c = 0; c <= COLdef; c++)
        {
            defenceFieldPlayer[i][c] = ' ';
            attackFieldPlayer[i][c] = ' ';
        }
    }

    int flag = 0; // varaibile check per corazzata,supporto,sottomarino
    // creazione oggetti + variabili
    ShipCorazzata naveCorazzata;
    ShipSupporto naveDiSupporto;
    ShipSottomarino sottomarino;

    string match, avvio;
    string coordinataPlayer1, coordinataPlayer2;
    coordinataPlayer2 = "";
    string comando;

    bool stato = 1;

    FieldAttacco atkField;
    FieldDifesa defField;

    Coordinate posizione;
    Player azione;

    cout << "**************************************************************************\n";
    cout << "**                                                                      **\n";
    cout << "*******                  BENVENUTO IN BATTAGLIANAVALE              *******\n";
    cout << "**                                                                      **\n";
    cout << "*******   Premere: 1.Avviare nuova partita    0.Chiudere VideoGame *******\n";
    cout << "**                                                                      **\n";
    cout << "**************************************************************************\n";
    getline(std::cin, avvio);
    int start = stoi(avvio);
    if (start == 0)
    {
        cout << "**************************************************************************\n";
        cout << "**                                                                      **\n";
        cout << "*******                     ALLA PROSSIMA PARTITA                  *******\n";
        cout << "**                                                                      **\n";
        cout << "**************************************************************************\n";
        return 0;
    }

    cout << "**************************************************************************\n";
    cout << "**                                                                      **\n";
    cout << "*******                        GIOCO AVVIATO                       *******\n";
    cout << "**                                                                      **\n";
    cout << "***       Premere: 1.Player vs Computer   2.Computer vs Computer       ***\n";
    cout << "**                                                                      **\n";
    cout << "**************************************************************************\n";
    getline(std::cin, match);
    int game = stoi(match);
    /*
    switch (game)
    {
    case 1:
    */

    for (int i = 0; i < 1; i++)
    {
        cout << "Inserisci le coordinate della " << i + 1 << " nave corazzata\n";
        getline(std::cin, coordinataPlayer1);
        azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
    }

    for (int i = 0; i < 1; i++)
    {
        flag = 1;
        cout << "Inserisci le coordinate della " << i + 1 << " nave supporto\n";
        getline(std::cin, coordinataPlayer1);
        azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
    }
    for (int i = 0; i < 1; i++)
    {
        flag = 2;
        cout << "Inserisci le coordinate del " << i + 1 << " sottomarino\n";
        getline(std::cin, coordinataPlayer1);
        azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
    }
    cout << "\n";
    defField.stampaCampoDifesa(defenceFieldPlayer);
    // break;
    /*
    // Posizionamento Computer
     case 2:
     // corazzata
     for (int i = 0; i < 3; i++)
     {
         coordinataPlayer2 = "";
     }
     // supporto
     for (int i = 0; i < 3; i++)
     {
         coordinataPlayer2 = "";
     }
     // sottomarino
     for (int i = 0; i < 1; i++)
     {

         coordinataPlayer2 = "";
     }
 }

    */

    while (stato == 1)
    {
        cout << "Inserire comando:                                         XYOrigin  XYTarget                                   XX XX \n";
        cout << "                                    coordinataPlayer1, coordinataPlayer2 centrale corazzata + Casella arrivo fuoco          Visualizzazione griglie\n";
        getline(std::cin, comando);
        // posizione.convertStringToInt(comando);
        //  naveCorazzata.fuoco(X,Y,attackFieldPlayer,);
    }
    return 0;
}