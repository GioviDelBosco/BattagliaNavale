#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "Cpu.h"

using namespace std;

Cpu::Cpu()
{
    srand((unsigned int)time(NULL));
}

string Cpu::getCoordinateRND(int flag, char (&defenceFieldCPU)[12][12])
{
    int RoC; // riga o colonna casuale
    int num, Yi, Yf;
    char Xi, Xf;
    int count = 0;
    // corazzata

    if (flag == 0)
    {
        RoC = rand() % 2;
        if (RoC == 0)
        { // same riga  -----> orizzontale
            do
            {
                do
                {
                    num = rand() % 12;
                } while (num > 7);
                if (num == 9)
                { // evito J
                    Xi = ('A' + num) + 2;
                    Xf = Xi;
                    // colonna varia
                }
                else if (num == 10)
                { // evito k
                    Xi = ('A' + num) + 1;
                    Xf = Xi;
                    // colonna varia
                    Yi = 1 + rand() % 12;
                    Yf = Yi + 4;
                }
                else
                {
                    Xi = ('A' + num);
                    Xf = Xi;
                    // colonna varia

                    Yi = 1 + rand() % 12;
                    Yf = Yi + 4;
                }
                
                for (int i = num; i < num + 5; i++)
                {
                    cout<<"Sono qua"<<endl;
                    if (defenceFieldCPU[num][i] = ' ')
                    {
                        count++;
                        cout<<count<<endl;
                    }
                    else
                        count = 0;
                }
            } while (count != 5);
            ostringstream ss;
            ss << Xi << Yi << " " << Xf << Yf;
            string coordinatineRandom = ss.str();
            count = 0;
            return coordinatineRandom;
        }
        else if (RoC == 1)
        { // colonna uguale
            // riga lettera varia
            do
            {
                do
                {
                    num = rand() % 12;
                } while (num > 7);
                if (num == 9)
                {
                    Xi = 'A' + num + 2;
                    Xf = Xi + 5;
                    // colonna lettera fissa

                    Yi = 1 + rand() % 12;
                    Yf = Yi;
                }
                if (num == 10)
                {
                    Xi = 'A' + num + 1;
                    Xf = Xi + 5;
                    // colonna lettera fissa

                    Yi = 1 + rand() % 12;
                    Yf = Yi;
                }
                else
                {
                    Xi = 'A' + num;
                    Xf = Xi + 5;
                    if (Xf == 'J')
                        Xf = Xf + 2;
                    else if (Xf == 'K')
                        Xf = Xf + 1;
                    // colonna lettera fissa

                    Yi = 1 + rand() % 12;
                    Yf = Yi;
                }
                for (int i = num; i < num + 5; i++)
                {
                    if (defenceFieldCPU[i][num] = ' ')
                    {
                        count++;
                    }
                    else
                        count = 0;
                }
            } while (count != 5);

            ostringstream ss;
            ss << Xi << Yi << " " << Xf << Yf;
            string coordinatineRandom = ss.str();
            count = 0;
            return coordinatineRandom;
        }
        // supporto
        else if (flag == 1)
        {
            cout<<"Sono qua supporto"<<endl;
            RoC = rand() % 2;
            if (RoC == 0)
            { // same riga
                do
                {
                    do
                    {
                        num = rand() % 12;
                    } while (num > 9);
                    if (num == 9)
                    { // evito J
                        Xi = ('A' + num) + 2;
                        Xf = Xi;
                        // colonna varia

                        do
                        {
                            Yi = 1 + rand() % 12;
                        } while (Yi > 8);
                        Yf = Yi + 2;
                    }
                    else if (num == 10)
                    { // evito k
                        Xi = ('A' + num) + 1;
                        Xf = Xi;
                        // colonna varia

                        Yi = 1 + rand() % 12;
                        Yf = Yi + 2;
                    }
                    else
                    {
                        Xi = ('A' + num);
                        Xf = Xi;
                        // colonna varia

                        Yi = 1 + rand() % 12;
                        Yf = Yi + 2;
                    }
                    for (int i = num; i < num + 3; i++)
                    {
                        if (defenceFieldCPU[num][i] == ' ')
                        {
                            count++;
                        }
                        else
                            count = 0;
                    }
                } while (count != 3);
            ostringstream ss;
            ss << Xi << Yi << " " << Xf << Yf;
            string coordinatineRandom = ss.str();
            count = 0;
            return coordinatineRandom;
            }
            else if (RoC == 1)
            { // colonna uguale
                // riga lettera varia
                do
                {
                    do
                    {
                        num = rand() % 12;
                    } while (num > 9);
                    // incolla qua

                    if (num == 9)
                    {
                        Xi = 'A' + num + 2;
                        Xf = Xi + 3;
                        // colonna lettera fissa

                        Yi = 1 + rand() % 12;
                        Yf = Yi;
                    }
                    if (num == 10)
                    {
                        Xi = 'A' + num + 1;
                        Xf = Xi + 3;
                        // colonna lettera fissa

                        Yi = 1 + rand() % 12;
                        Yf = Yi;
                    }
                    else
                    {
                        Xi = 'A' + num;
                        Xf = Xi + 3;
                        if (Xf == 'J')
                            Xf = Xf + 2;
                        else if (Xf == 'K')
                            Xf = Xf + 1;
                        // colonna lettera fissa

                        Yi = 1 + rand() % 12;
                        Yf = Yi;
                    }
                    for (int i = num; i < num + 3; i++)
                    {

                        if (defenceFieldCPU[num][i] = ' ')
                        {
                            count++;
                        }
                        else
                            count = 0;
                    }
                } while (count != 3);
            }
            ostringstream ss;
            ss << Xi << Yi << " " << Xf << Yf;
            string coordinatineRandom = ss.str();
            count = 0;
            return coordinatineRandom;
        }
        // parentesi chiusa

        // sottomarino
        else if (flag == 2)
        {
            RoC = rand() % 2;
            if (RoC == 0)
            { // same riga
                do
                {
                    num = rand() % 12;
                    if (num == 9)
                    { // evito J
                        Xi = ('A' + num) + 2;
                        Xf = Xi;
                        // colonna varia

                        do
                        {
                            Yi = 1 + rand() % 12;
                        } while (Yi > 8);
                        Yf = Yi;
                    }
                    else if (num == 10)
                    { // evito k
                        Xi = ('A' + num) + 1;
                        Xf = Xi;
                        // colonna varia

                        Yi = 1 + rand() % 12;
                        Yf = Yi;
                    }
                    else
                    {
                        Xi = ('A' + num);
                        Xf = Xi;
                        // colonna varia

                        Yi = 1 + rand() % 12;
                        Yf = Yi;
                    }
                    for (int i = num; i < num; i++)
                    {

                        if (defenceFieldCPU[num][i] == ' ')
                        {
                            count++;
                        }
                        else
                            count = 0;
                    }
                } while (count != 1);

                //
                ostringstream ss;
            ss << Xi << Yi << " " << Xf << Yf;
            string coordinatineRandom = ss.str();
            count = 0;
            return coordinatineRandom;

            }
            else if (RoC == 1)
            { // colonna uguale
                // riga lettera varia
                do
                {
                    num = rand() % 12;
                    if (num == 9)
                    {
                        Xi = 'A' + num + 2;
                        Xf = Xi;
                        // colonna lettera fissa

                        Yi = 1 + rand() % 12;
                        Yf = Yi;
                    }
                    if (num == 10)
                    {
                        Xi = 'A' + num + 1;
                        Xf = Xi;
                        // colonna lettera fissa

                        Yi = 1 + rand() % 12;
                        Yf = Yi;
                    }
                    else
                    {
                        Xi = 'A' + num;
                        Xf = Xi;
                        if (Xf == 'J')
                            Xf = Xf + 2;
                        else if (Xf == 'K')
                            Xf = Xi;
                        // colonna lettera fissa

                        Yi = 1 + rand() % 12;
                        Yf = Yi;
                    }
                    for (int i = num; i < num; i++)
                    {

                        if (defenceFieldCPU[i][num] = ' ')
                        {
                            count++;
                        }
                        else
                            count = 0;
                    }
                } while (count != 1);
            }
            ostringstream ss;
            ss << Xi << Yi << " " << Xf << Yf;
            string coordinatineRandom = ss.str();
            count = 0;
            return coordinatineRandom;
        }
    }
} // end