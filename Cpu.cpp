#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <random>
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
    // Crea un device random e lo usa per generare un seed random
    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();

    //inizializzazione di default_random_engine
    std::default_random_engine myRandomEngine(seed);

    string coordinateRandom;
    int RoC;
  
    ostringstream ss; // riga o colonna casuale
    int nR, nC, Yi, Yf, num;
    int Xi, Xf;

    Coordinate casella;

    if (flag == 0)
    {

       // RoC = rand() % 2;
       uniform_int_distribution<int> myUnifIntDist(0, 1);
        RoC = myUnifIntDist(myRandomEngine);
        if (RoC == 0)
        {
            // same riga  -----> orizzontale
            do
            {
                //nR = rand() % 12;
               uniform_int_distribution<int> myUnifIntDist(0, 11);
                nR = myUnifIntDist(myRandomEngine);
                Xi = nR;
                do
                {
                   // nC = rand() % 12;
                   nC = myUnifIntDist(myRandomEngine);
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
                //Yi = rand() % 12;
               uniform_int_distribution<int> myUnifIntDist(0, 11);
                Yi = myUnifIntDist(myRandomEngine);
                Yf = Yi;
                do
                {
                    //nR = rand() % 12;
                    nR = myUnifIntDist(myRandomEngine);
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
        // RoC = rand() % 2;
       uniform_int_distribution<int> myUnifIntDist(0, 1);
        RoC = myUnifIntDist(myRandomEngine);
       
        if (RoC == 0)
        {
            // same riga  -----> orizzontale
            do
            {
                //nR = rand() % 12;
               uniform_int_distribution<int> myUnifIntDist(0, 11);
                nR = myUnifIntDist(myRandomEngine);
                Xi = nR;
                do
                {
                    //nC = rand() % 12;
                    nC = myUnifIntDist(myRandomEngine);
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
                // Yi = rand() % 12;
               uniform_int_distribution<int> myUnifIntDist(0, 11);
                Yi = myUnifIntDist(myRandomEngine);
                Yf = Yi;
                do
                {
                   // nR = rand() % 12;
                    nR = myUnifIntDist(myRandomEngine);

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
        //RoC = rand() % 2;
       uniform_int_distribution<int> myUnifIntDist(0, 1);
        RoC = myUnifIntDist(myRandomEngine);
        if (RoC == 0)
        {
            // same riga  -----> orizzontale
            do
            {
               // nR = rand() % 12;
               uniform_int_distribution<int> myUnifIntDist(0, 11);
                nR = myUnifIntDist(myRandomEngine);
                Xi = nR;
                //nC = rand() % 12;
                nC = myUnifIntDist(myRandomEngine);
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
                //Yi = rand() % 12;
               uniform_int_distribution<int> myUnifIntDist(0, 11);
                Yi = myUnifIntDist(myRandomEngine);
                Yf = Yi;
                //nR = rand() % 12;
                Yi = myUnifIntDist(myRandomEngine);
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