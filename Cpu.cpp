#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include <time.h>
#include "Cpu.h"
#include "Player.h"

using namespace std;

Player azione;

Cpu::Cpu()
{
    srand((unsigned int)time(NULL));
};

string Cpu::getCoordinateRND(int flag, char (&defenceFieldCPU)[12][12]){

    string coordinateRandom;
    int RoC;
    ostringstream ss; // riga o colonna casuale
    int num, Yi, Yf;
    char Xi, Xf;
    int cont;
    
    if(flag==0){
        //cout<<"sono qui\n";
        cont=0;
        RoC = rand() % 2;
        if (RoC == 0)
        { 
            // same riga  -----> orizzontale
            do{
                num=rand()%11;
                Xi='A' + num;
                Xf=Xi;
                do{
                    num=rand()%11;
                }while(num>7);
                Yi=num;
                Yf=Yi+4;
                for(int i=num;i<num+6;i++)
                    {
                        if(defenceFieldCPU[num][i] == ' ') cont++;
                        else cont=0;
                    }
                }while(cont<5);
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            cout<<coordinateRandom<<endl;
        azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
        }
        else if(RoC==1)
        {
            
            do{
                Yi=rand()%11;
                Yf=Yi;
            do{
                num=rand()%11;
               
            }while(num>7);
             if(num > 6){
                    num += 2;
                }
            Xi='A' + num;
            Xf=Xi+4;
            for(int i=num;i<num+6;i++)
            {
                if(defenceFieldCPU[i][num] == ' ') cont++;
                else cont=0;
            }
            }while(cont<5);

            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            cout<<coordinateRandom<<endl;
            azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
        } 
    }

    else if(flag==1)
    {
        cont=0;
        RoC = rand() % 2;
        if (RoC == 0)
        { 
            // same riga  -----> orizzontale
            do{
                num=rand()%11;
                Xi='A' +num;
                Xf=Xi;
                do{
                    num=rand()%11;
                }while(num>9);
                Yi=num;
                Yf=Yi+2;
                for(int i=num;i<num+4;i++)
                    {
                        if(defenceFieldCPU[num][i]==' ') cont++;
                        else cont=0;
                    }
                }while(cont<3);
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            cout<<coordinateRandom<<endl;
        azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
        }
        else if(RoC==1)
        {
            do{
                Yi=rand()%11;
                Yf=Yi;
            do{
                num=rand()%11;
               
            }while(num>9);
             if(num > 6){
                    num += 2;
                }
            Xi='A' + num;
            Xf=Xi+2;
            for(int i=num;i<num+4;i++)
            {
                if(defenceFieldCPU[i][num]==' ') cont++;
                else cont=0;
            }
            }while(cont<3);

            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            cout<<coordinateRandom<<endl;
            azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
        } 
    }
    else if(flag==2)
    {
        cont=0;
            // same riga  -----> orizzontale
            do{
                num=rand()%11;
                Xi='A' +num;
                Xf=Xi;
                num=rand()%11;
                Yi=num;
                Yf=Yi;
                for(int i=num;i<=num;i++)
                    {
                        if(defenceFieldCPU[num][i]==' ') cont++;
                        else cont=0;
                    }
            }while(cont<1);
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            cout<<coordinateRandom<<endl;
        azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
    }

    return coordinateRandom;
}