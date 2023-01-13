#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "Cpu.h"

using namespace std;

Cpu::Cpu()
{
    srand((unsigned int) time(NULL));
}


string Cpu::getCoordinateRND(int flag)
{
    int RoC; // riga o colonna casuale
    int num, Yi, Yf;
    char Xi, Xf;

    //corazzata
    if(flag==0){ 
        RoC = rand() % 2;
        if (RoC == 0)
        { // same riga
            
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
                Yf = Yi + 4;
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
        }
        else if (RoC == 1)
        { // colonna uguale
            // riga lettera varia
            
            do
            {
                num = rand() % 12;
            } while (num > 8);
            if (num == 9)
            {
                Xi = 'A' + num + 2;
                Xf = Xi + 4;
                // colonna lettera fissa
                
                Yi = 1 + rand() % 12;
                Yf = Yi;
            }
            if (num == 10)
            {
                Xi = 'A' + num + 1;
                Xf = Xi + 4;
                // colonna lettera fissa
                
                Yi = 1 + rand() % 12;
                Yf = Yi;
            }
            else
            {
                Xi = 'A' + num;
                Xf = Xi + 4;
                if (Xf == 'J')
                    Xf = Xf + 2;
                else if (Xf == 'K')
                    Xf = Xf + 1;
                // colonna lettera fissa
                
                Yi = 1 + rand() % 12;
                Yf = Yi;
            }
        }
        ostringstream ss;
        ss<<Xi<<Yi<<" "<<Xf<<Yf;
        string coordinatineRandom=ss.str();
        return coordinatineRandom;
    }
        //supporto
        else if(flag==1){ 
        RoC = rand() % 2;
        if (RoC == 0)
        { // same riga
            
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
        }
        else if (RoC == 1)
        { // colonna uguale
            // riga lettera varia
            
            do
            {
                num = rand() % 12;
            } while (num > 8);
            if (num == 9)
            {
                Xi = 'A' + num + 2;
                Xf = Xi + 2;
                // colonna lettera fissa
                
                Yi = 1 + rand() % 12;
                Yf = Yi;
            }
            if (num == 10)
            {
                Xi = 'A' + num + 1;
                Xf = Xi + 2;
                // colonna lettera fissa
                
                Yi = 1 + rand() % 12;
                Yf = Yi;
            }
            else
            {
                Xi = 'A' + num;
                Xf = Xi + 2;
                if (Xf == 'J')
                    Xf = Xf + 2;
                else if (Xf == 'K')
                    Xf = Xf + 1;
                // colonna lettera fissa
                
                Yi = 1 + rand() % 12;
                Yf = Yi;
            }
        }
        ostringstream ss;
        ss<<Xi<<Yi<<" "<<Xf<<Yf;
        string coordinatineRandom=ss.str();
        return coordinatineRandom;
        
        }


        
        //sottomarino
        else if(flag==2){
            RoC = rand() % 2;
        if (RoC == 0)
        { // same riga
            
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
        }
        else if (RoC == 1)
        { // colonna uguale
            // riga lettera varia
            
            do
            {
                num = rand() % 12;
            } while (num > 8);
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
        }
        ostringstream ss;
        ss<<Xi<<Yi<<" "<<Xf<<Yf;
        string coordinatineRandom=ss.str();
        return coordinatineRandom;
        }
    }














