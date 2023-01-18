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
    ofstream fout("replica.txt"); // file scrittura replica partita
    bool win = 0;
    // questo deve essere un array di puntatori se avete usato i puntatoris
    char defenceFieldPlayer[LINEdef][COLdef];
    char attackFieldPlayer[LINEatk][COLatk];
    int cont = 0;
    char defenceFieldComputer1[LINEdef][COLdef];
    char attackFieldComputer1[LINEatk][COLatk];
    char defenceFieldComputer2[LINEdef][COLdef];
    char attackFieldComputer2[LINEatk][COLatk];
    string supportoOSottomarino = "0";
    int sceltaPartita;
    int scelta, turni = 0;
    string comando;
    string mossa;

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
        for (int i = 0; i < 3; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
        }

        flag = 1;

        for (int i = 0; i < 3; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
        }
        flag = 2;
        fout << "Sottomarino nemica:\n";
        for (int i = 0; i < 2; i++)
        {
            coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
        }
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
            }

            //--------------------SPOSTA BARCA-------------------------------------
            else if (scelta == 2)
            {
                cout << "1. Muovi nave Supporto      2.Muovi Sottomarino"<< endl;
                getline(std::cin, supportoOSottomarino);
                if (supportoOSottomarino == "1")
                {
                    do
                    {
                        cout << "Inserisci coordinate per la nave di supporto" << endl;
                        getline(std::cin, comando);
                        azione.muoviBarca(defenceFieldPlayer, comando);
                    } while (naveDiSupporto.checkPosArrivoLine(comando, defenceFieldPlayer) == 0 || naveDiSupporto.checkPosArrivoCol(comando, defenceFieldPlayer) == 0);
                }
                else if (supportoOSottomarino == "2")
                {
                    cout << "Inserisci coordinate per il sottomarino" << endl;
                    getline(std::cin, comando);
                    sottomarino.muoviECerca(attackFieldPlayer, defenceFieldComputer1, defenceFieldPlayer, comando);
                }
                // qua
                cout << " " << endl;
            }
        } while (win == 0);
    }

    if (game == 2)
    {
        //-----------------------INSERIMENTO NAVE 1 RANDOM----------------------------------------
        do
        {
            cout << "Inserimento random 1\n";

            flag = 0;
            fout << "Corazzata nemica:\n";
            for (int i = 0; i < 3; i++)
            {
                coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            }
            flag = 1;
            for (int i = 0; i < 3; i++)
            {
                coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            }
            flag = 2;
            fout << "Sottomarino nemica:\n";
            for (int i = 0; i < 2; i++)
            {
                coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer1);
            }
            defField.stampaCampoDifesa(defenceFieldComputer1);

            //-----------------------INSERIMENTO NAVE 2 RANDOM----------------------------------------
            cout << "Inserimento random 2\n";
            flag = 0;
            for (int i = 0; i < 3; i++)
            {
                coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer2);
            }
            flag = 1;
            for (int i = 0; i < 3; i++)
            {
                coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer2);
            }
            flag = 2;
            fout << "Sottomarino nemica:\n";
            for (int i = 0; i < 2; i++)
            {
                coordinataPlayer2 = Pc.getCoordinateRND(flag, defenceFieldComputer2);
            }
            defField.stampaCampoDifesa(defenceFieldComputer2);
        } while (turni < 10);
    }
    return 0;
}

// attacco random => passo griglia difesa, analizzo tutta la griglia e check C, se trovo C=> getCentro.
// Quando getCentro True => randomCordinate random => passo getCentro e CoordinataTarget a Fuoco
