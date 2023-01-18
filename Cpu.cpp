#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "Cpu.h"
#include "Player.h"
#include "Coordinate.h"

using namespace std;

Player azione;

std::vector<char> numeri = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N'};

Cpu::Cpu()
{
    srand((unsigned int)time(NULL));
};

string Cpu::getCoordinateRND(int flag, char (&defenceFieldCPU)[12][12])
{

    string coordinateRandom;
    int RoC;
    char ASCII_C = 'C';
    char ASCII_S = 'S';
    char ASCII_E = 'E';
    ostringstream ss; // riga o colonna casuale
    int nR, nC, Yi, Yf, num;
    int Xi, Xf;

    Coordinate casella;

    if (flag == 0)
    {

        RoC = rand() % 2;
        if (RoC == 0)
        {
            // same riga  -----> orizzontale
            do
            {
                nR = rand() % 12;
                Xi = nR;
                do
                {
                    nC = rand() % 12;
                } while (nC > 7);
                Yi = nC;
                Yf = Yi + 4;

            } while (casella.posOccupataLine(Xi, Yi, Yf, defenceFieldCPU) == 1);
            Xf = Xi;
            if (Yi == 0)
            {
                Yi = 1;
                Yf++;
            }

            ss << numeri[Xi] << Yi << " " << numeri[Xf] << Yf;
            coordinateRandom = ss.str();

            azione.piazzaBarca(flag, defenceFieldCPU, coordinateRandom);
        }
        else if (RoC == 1)
        {
            do
            {
                Yi = rand() % 12;
                Yf = Yi;
                do
                {
                    nR = rand() % 12;
                } while (nR > 7);
                Xi = nR;
                Xf = Xi + 4;

            } while (casella.posOccupataCol(Yi, Xi, Xf, defenceFieldCPU) == 1);

            if (Yi == 0)
            {
                Yi = 1;
            }
            Yf = Yi;

            ss << numeri[Xi] << Yi << " " << numeri[Xf] << Yf;
            coordinateRandom = ss.str();

            azione.piazzaBarca(flag, defenceFieldCPU, coordinateRandom);
        }
    }

    else if (flag == 1)
    {
        RoC = rand() % 2;
        if (RoC == 0)
        {
            // same riga  -----> orizzontale
            do
            {
                nR = rand() % 12;
                Xi = nR;
                do
                {
                    nC = rand() % 12;
                } while (nC > 9);
                Yi = nC;
                Yf = Yi + 2;

            } while (casella.posOccupataLine(Xi, Yi, Yf, defenceFieldCPU) == 1);

            Xf = Xi;

            if (Yi == 0)
            {
                Yi = 1;
                Yf++;
            }

            ss << numeri[Xi] << Yi << " " << numeri[Xf] << Yf;
            coordinateRandom = ss.str();

            azione.piazzaBarca(flag, defenceFieldCPU, coordinateRandom);
        }
        else if (RoC == 1)
        {
            do
            {
                Yi = rand() % 12;
                Yf = Yi;
                do
                {
                    nR = rand() % 12;

                } while (nR > 9);
                Xi = nR;
                Xf = Xi + 2;

            } while (casella.posOccupataCol(Yi, Xi, Xf, defenceFieldCPU) == 1);

            if (Yi == 0)
            {
                Yi = 1;
            }
            Yf = Yi;

            ss << numeri[Xi] << Yi << " " << numeri[Xf] << Yf;
            coordinateRandom = ss.str();

            azione.piazzaBarca(flag, defenceFieldCPU, coordinateRandom);
        }
    }
    else if (flag == 2)
    {
        RoC = rand() % 2;
        if (RoC == 0)
        {
            // same riga  -----> orizzontale
            do
            {
                nR = rand() % 12;
                Xi = nR;
                nC = rand() % 12;
                Yi = nC;
                Yf = Yi;
            } while (casella.posOccupataLine(Xi, Yi, Yf, defenceFieldCPU) == 1);
            Xf = Xi;
            if (Yi == 0)
            {
                Yi = 1;
                Yf++;
            }

            ss << numeri[Xi] << Yi << " " << numeri[Xf] << Yf;
            coordinateRandom = ss.str();

            azione.piazzaBarca(flag, defenceFieldCPU, coordinateRandom);
        }
        else if (RoC == 1)
        {
            do
            {
                Yi = rand() % 12;
                Yf = Yi;
                nR = rand() % 12;
                Xi = nR;
                Xf = Xi;

            } while (casella.posOccupataCol(Yi, Xi, Xf, defenceFieldCPU) == 1);

            if (Yi == 0)
            {
                Yi = 1;
            }
            Yf = Yi;

            ss << numeri[Xi] << Yi << " " << numeri[Xf] << Yf;
            coordinateRandom = ss.str();

            azione.piazzaBarca(flag, defenceFieldCPU, coordinateRandom);
        }
    }
    return coordinateRandom;
}


/*string Cpu::getCoordinataRNDattacco(char (&defenceFieldCPU)[12][12])
{
    int Xi, Yi, Xf, Yf; // Xi,Yi => origine fuoco
    int Xt, Yt; // Xt,Y => target fuoco
    int nR, nC;
    int RoC;
    bool attacco = 0;
    ostringstream ss;
    string coordinateRandomattacco;
    RoC = rand() % 2;
    if (RoC == 0) // riga
    {
        do
        {
                nR = rand() % 12;
                Xi = nR;
                nC = rand() % 12;
                Yi = nC;
                    
                if (defenceFieldCPU[Xi][Yi] == 'C')
                { 
                    // controllo che sia il centro della corazzzata
                    if (numeri[Xi] == Coordinate::getCentro(coordinateRandomattacco, defenceFieldCPU).at(0) && Yi == Coordinate::getCentro(coordinateRandomattacco, defenceFieldCPU).at(1))
                    {
                        attacco = 1;
                    }
                }

        } while (attacco == 0);
        nR = rand() % 12;
        Xt = nR;
        nC = rand() % 12;
        Yt = nC;
    }
    else if (RoC == 1)
    {
        do
        {

            nR = rand() % 12;
            Yi = nR;
            Xi = rand() % 12;

            if (defenceFieldCPU[Xi][Yi] == 'C' && defenceFieldCPU[Xf][Yf] == 'C')
            {

                // controllo che sia il centro della corazzzata
                if (numeri[Xi] == Coordinate::getCentro(coordinateRandomattacco, defenceFieldCPU).at(0) && Yi == Coordinate::getCentro(coordinateRandomattacco, defenceFieldCPU).at(1))
                {
                    cout << "son qua\n";
                    attacco = 1;
                }

                cout << "attacco: " << attacco << endl;
            }

        } while (attacco == 0);
        nR = rand() % 12;
        Xt = nR;
        nC = rand() % 12;
        Yt = nC;
    }
    // coordinate origine
    // cout<<"coordinata Y "<<Yi<<endl;
    ss << numeri[Xi] << Yi << " " << numeri[Xt] << Yt;
    coordinateRandomattacco = ss.str();
    cout << "XYorigin XYtarget | " << coordinateRandomattacco << endl;
    return coordinateRandomattacco;
}*/





