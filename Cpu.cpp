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

    // bool occ=1;

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
        else if(flag==2)
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