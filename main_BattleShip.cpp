// BGM(): Colapietro Mattia, Santoro Giuseppe, Sgaravatto Giovanni
// main
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ShipSupporto.h"
#include "ShipCorazzata.h"
#include "ShipSottomarino.h"
#include "FieldAttacco.h"
#include "FieldDifesa.h"
#include "Coordinate.h"
#include "Player.h"
#include "Cpu.h"
#include <time.h>


using namespace std;

int main()
{
    ofstream fout("replica.txt"); //file scrittura replica partita

    // questo deve essere un array di puntatori se avete usato i puntatoris
    char defenceFieldPlayer[LINEdef][COLdef];
    char attackFieldPlayer[LINEatk][COLatk];
    int cont=0;
    char defenceFieldComputer[LINEdef][COLdef];
    char attackFieldComputer[LINEatk][COLatk];

    for (int i = 0; i < LINEdef; i++)
    {
        for (int c = 0; c < COLdef; c++)
        {
            defenceFieldPlayer[i][c] = ' ';
            attackFieldPlayer[i][c] = ' ';
            defenceFieldComputer[i][c] = ' ';
            attackFieldComputer[i][c] = ' ';
        }
    }

    int flag = 0; // varaibile check per corazzata,supporto,sottomarino
    // creazione oggetti + variabili
    ShipCorazzata naveCorazzata;
    ShipSupporto naveDiSupporto;
    ShipSottomarino sottomarino;

    string match, avvio;
    string coordinataPlayer1, coordinataPlayer2;
   

    bool stato = 1;

    FieldAttacco atkField;
    FieldDifesa defField;

    Coordinate posizione;
    Player azione;
    Cpu Pc;

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
    fout<<"Corazzate:\n";
    for (int i = 0; i < 1; i++)
    {
        cout << "Inserisci le coordinate della " << i + 1 << " nave corazzata\n";
        getline(std::cin, coordinataPlayer1);
        
        fout<<coordinataPlayer1<<"\n";
        azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
    }
    fout<<"Supporto:\n";
    for (int i = 0; i < 1; i++)
    {
        flag = 1;
        cout << "Inserisci le coordinate della " << i + 1 << " nave supporto\n";
        getline(std::cin, coordinataPlayer1);
        
        fout<<coordinataPlayer1<<"\n";
        azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
    }
    fout<<"Sottomarino:\n";
    for (int i = 0; i < 1; i++)
    {
        flag = 2;
        cout << "Inserisci le coordinate del " << i + 1 << " sottomarino\n";
        getline(std::cin, coordinataPlayer1);
        
        fout<<coordinataPlayer1<<"\n";
        azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
    }
    cout << "\n";
    defField.stampaCampoDifesa(defenceFieldPlayer);

cout<<"---------------------------------------------------------------\n";
cout<<"Inserimento random\n";


flag = 0;
fout<<"Corazzata nemica:\n";
for(int i=0;i<3;i++){
    
    coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer);
 }
 flag = 1;
 fout<<"Supporto nemico:\n";
 for (int i = 0; i < 3; i++){
    coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer);
 }
 flag=2;
 fout<<"Sottomarino nemica:\n";
 for (int i = 0; i < 2; i++){
    coordinataPlayer2 = Pc.getCoordinateRND(flag,defenceFieldComputer);
 }
defField.stampaCampoDifesa(defenceFieldComputer);
//while(cont<10)
//{
    cout << "Dove vuoi fare fuoco?"<< endl;
//-----------------------FUOCO-----------------------------
    string comando;
    getline(std::cin, comando);
    //B6 B10
    naveCorazzata.fuoco(comando,attackFieldPlayer,defenceFieldComputer,defenceFieldPlayer);
    atkField.stampaCampoAttacco(attackFieldPlayer);
//---------------------------------------------------------
    
    do{
        cout << "Inserisci coordinate per muoviBarca"<< endl;
        getline(std::cin, comando);
       
    }
    while(naveDiSupporto.checkPosArrivoLine(comando,defenceFieldPlayer) == 0 || naveDiSupporto.checkPosArrivoCol(comando,defenceFieldPlayer) == 0);
    azione.muoviBarca(defenceFieldPlayer,comando);
    defField.stampaCampoDifesa(defenceFieldPlayer);
    //cont++;
//}

    return 0;
}