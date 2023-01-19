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
    // file scrittura replica partita
    ofstream fout("replica.txt"); 
    bool win = 0;
    // questo deve essere un array di puntatori se avete usato i puntatoris
    char defenceFieldPlayer[LINEdef][COLdef];
    char attackFieldPlayer[LINEatk][COLatk];
    int cont = 0;
    char defenceFieldComputer1[LINEdef][COLdef];//usato con Plaver vs Computer
    char attackFieldComputer1[LINEatk][COLatk];//usato con Plaver vs Computer
    
    char defenceFieldComputer2[LINEdef][COLdef];//usato con computer vs Computer
    char attackFieldComputer2[LINEatk][COLatk];//usato con computer vs Computer


    string supportoOSottomarino = "0";
    int sceltaPartita;
    int scelta, turni = 0;
    string comando;
    string mossa;
    int naviPlayer1=8,naviPlayer2=8; 

    for (int i = 0; i < LINEdef; i++)
    {
        for (int c = 0; c < COLdef; c++)
        {
            defenceFieldPlayer[i][c] = '-';
            attackFieldPlayer[i][c] = '-';
            defenceFieldComputer1[i][c] = '-';
            attackFieldComputer1[i][c] = '-';
            defenceFieldComputer2[i][c] = '-';
            attackFieldComputer2[i][c] = '-';
        }
    }

    int flag = 0; // varaibile check per corazzata,supporto,sottomarino
    // creazione oggetti + variabili
    ShipCorazzata naveCorazzata;
    ShipCorazzata corazzataNemica;
    ShipSupporto supporto;
    ShipSottomarino sottomarino;

    string match, avvio;
    string coordinataPlayer1, coordinataPlayer2;

    bool stato = 1;

    FieldAttacco atkField;
    FieldDifesa defField;

    Coordinate posizione;
    Player azione;
    Cpu Pc;

    vector<string> coordinateCorazzate;

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

    if (game == 1)
    {
        for (int i = 0; i < 1; i++)
        {
            cout << "Inserisci le coordinate della " << i + 1 << " nave corazzata\n";
            getline(std::cin, coordinataPlayer1);

            fout << coordinataPlayer1 << "\n";
            azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
        }
        for (int i = 0; i < 1; i++)
        {
            flag = 1;
            cout << "Inserisci le coordinate della " << i + 1 << " nave supporto\n";
            getline(std::cin, coordinataPlayer1);

            fout << coordinataPlayer1 << "\n";
            azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
        }
        for (int i = 0; i < 1; i++)
        {
            flag = 2;
            cout << "Inserisci le coordinate del " << i + 1 << " sottomarino\n";
            getline(std::cin, coordinataPlayer1);

            fout << coordinataPlayer1 << "\n";
            azione.piazzaBarca(flag, defenceFieldPlayer, coordinataPlayer1);
        }
        cout << "\n";
        defField.stampaCampoDifesa(defenceFieldPlayer);

        // Inserimento random

        flag = 0;
        fout << "Corazzata nemica:\n";
        for (int i = 0; i < 1; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }

        flag = 1;

        for (int i = 0; i < 1; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }
        flag = 2;
        fout << "Sottomarino nemica:\n";
        for (int i = 0; i < 1; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }
        defField.stampaCampoDifesa(defenceFieldComputer1);
        do
        {
            cout << "Inserire: \n"
                 << "1.Fuoco con Corazzata\n"
                 << "2.Spostamento nave supporto/sottomarino\n"
                 << "3. Stampa griglia\n";
            getline(std::cin, mossa);
            scelta = stoi(mossa);
            if (scelta == 3)
            {
                defField.stampaCampoDifesa(defenceFieldPlayer);
                atkField.stampaCampoAttacco(attackFieldPlayer);
            }
            //-----------------------FUOCO-----------------------------
            else if (scelta == 1)
            {
                cout << "Inserire coordinate fuoco XO XT:      (XO=centro corazzata     XT=Coordinata target)" << endl;
                getline(std::cin, comando);
                naveCorazzata.fuoco(comando, attackFieldPlayer, defenceFieldComputer1, defenceFieldPlayer);
                atkField.stampaCampoAttacco(attackFieldPlayer);
                //defField.stampaCampoDifesa(defenceFieldComputer1);
                atkField.contaBarcheRimanenti(naviPlayer2,coordinateCorazzate,attackFieldComputer1);
            }

            //--------------------SPOSTA BARCA-------------------------------------
            else if (scelta == 2)
            {
                cout << "1. Muovi nave Supporto      2.Muovi Sottomarino" << endl;
                getline(std::cin, supportoOSottomarino);
                if (supportoOSottomarino == "1")
                {
                   // do
                   // {
                        cout << "Inserisci coordinate per la nave di supporto" << endl;
                        getline(std::cin, comando);
                        supporto.muoviERipara(comando, defenceFieldPlayer);
                  //  } while (supporto.checkPosArrivoLine(comando, defenceFieldPlayer) == 0 || supporto.checkPosArrivoCol(comando, defenceFieldPlayer) == 0);
                    defField.stampaCampoDifesa(defenceFieldPlayer);
                }
                else if (supportoOSottomarino == "2")
                {
                    cout << "Inserisci coordinate per il sottomarino" << endl;
                    getline(std::cin, comando);
                    sottomarino.muoviECerca(attackFieldPlayer, defenceFieldComputer1, defenceFieldPlayer, comando);
                    atkField.stampaCampoAttacco(defenceFieldPlayer);
                }
                // qua
                cout << " " << endl;

                // azione nemico
            }
            //-----------------------FUOCO NEMICO----------------------------
            
    
            naveCorazzata.fuocoRandom(posizione.getCentroRandom(coordinateCorazzate),attackFieldComputer1,defenceFieldPlayer,defenceFieldComputer1);
            atkField.stampaCampoAttacco(attackFieldComputer1);    
            if(naviPlayer1==0){
                cout<<"HAI PERSO!!!\n LE TUE NAVI SONO STATE TUTTE COLPITE\n";
                win=1;
            }
            else if(naviPlayer2==0){
                cout<<"COMPLIMENTI HAI VINTO!!!\n HAI COLPITO TUTTE LE NAVI\n";
                win=1;
            }
            /*cout<<"fuoco random\n";
            naveCorazzata.fuocoRandom(posizione.getCentroRandom(coordinateCorazzate),attackFieldComputer1,defenceFieldPlayer,defenceFieldComputer1);
            atkField.stampaCampoAttacco(attackFieldComputer1);*/
        } while (win == 0);
    }
    
    



    //PC vs PC
    if (game == 2)
    {
        //-----------------------INSERIMENTO NAVE 1 RANDOM----------------------------------------
        
        flag = 0;
        cout << "Corazzata nemica:\n";
        for (int i = 0; i < 3; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }
        flag = 1;
        for (int i = 0; i < 3; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }
        flag = 2;
        fout << "Sottomarino nemica:\n";
        for (int i = 0; i < 2; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }
        defField.stampaCampoDifesa(defenceFieldComputer1);

        //-----------------------INSERIMENTO NAVE 2 RANDOM----------------------------------------
        cout << "Inserimento random 2\n";
        flag = 0;
        for (int i = 0; i < 3; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer2);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }
        flag = 1;
        for (int i = 0; i < 3; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer2);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }
        flag = 2;
        fout << "Sottomarino nemica:\n";
        for (int i = 0; i < 2; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer2);
            coordinateCorazzate.push_back(coordinataPlayer2);
        }
        defField.stampaCampoDifesa(defenceFieldComputer2);
        do
        {
            //----------------azione nave 1--------------
            naveCorazzata.fuocoRandom(posizione.getCentroRandom(coordinateCorazzate),attackFieldComputer1,defenceFieldComputer2,defenceFieldComputer1);
            atkField.stampaCampoAttacco(attackFieldComputer1);

            //---------------azione nave 2--------------
            naveCorazzata.fuocoRandom(posizione.getCentroRandom(coordinateCorazzate),attackFieldComputer2,defenceFieldComputer1,defenceFieldComputer2);
            atkField.stampaCampoAttacco(attackFieldComputer2);
            turni++;
        } while (turni < 10);
    }
    return 0;
}






/*
-------------------DA FARE------------------
Sottomarino e supporto per random 
controllo affondata e vittoria player 1 ( utente vs pc)

controllo centro per coordinata sbagliata del player

controllo per spazi già occupati vector 
cmake 
random engine 

test vm 
consegna 

*/