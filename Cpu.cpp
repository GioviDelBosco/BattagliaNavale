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
    char ASCII_SPACE=' ';
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
                Xi=num;
                do{
                    num=rand()%11;
                }while(num>7);
                Yi=num;
                Yf=Yi+4;
                for(int i=Yi;i<Yf+1;i++)
                    {
                        //cout<<defenceFieldCPU[Xi][i]<<endl;
                        if(defenceFieldCPU[Xi][i] == ASCII_SPACE) {
                            cont++;
                            cout<<cont<<endl;
                        }
                        else cont=0;
                    }
                }while(cont<5);
            Xi='A' + num;
            Xf=Xi;
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            
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
            Xi=num;
            
            for(int i=Xi;i<Xi+5;i++)
            {
                //cout<<defenceFieldCPU[i][Yi]<<endl;
                if(defenceFieldCPU[i][Yi] == ASCII_SPACE) cont++;
                else cont=0;
            }
            }while(cont<5);
        Xi='A' + num;
        Xf=Xi+4;
        ss << Xi << Yi << " " << Xf << Yf;
        coordinateRandom = ss.str();        
        azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
        } 
    }

    /*else if(flag==1)
    {
        cont=0;
        RoC = rand() % 2;
        if (RoC == 0)
        { 
            // same riga  -----> orizzontale
            do{
                num=rand()%11;
                Xi=num;
                do{
                    num=rand()%11;
                }while(num>9);
                Yi=num;
                Yf=Yi+2;
                for(int i=Yi;i<Yf+1;i++)
                    {
                        //cout<<"Celle occupata: riga "<<defenceFieldCPU[Xi][i]<<endl;
                        if(defenceFieldCPU[Xi][i] == ASCII_SPACE) cont++;
                        else cont=0;
                    }
                }while(cont<3);
                Xi='A' +num;
                Xf=Xi;
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            
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
            Xi=num;
            
            for(int i=Xi;i<Xi+3;i++)
            {
                //cout<<"Cella occupata: colonna "<<defenceFieldCPU[i][Yi]<<endl;
                if(defenceFieldCPU[i][Yi] == ASCII_SPACE) cont++;
                else cont=0;
            }
            }while(cont<3);
            Xi='A' +num;
            Xf=Xi+2;
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            
            azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
        } 
    }
/*
    else if(flag==2)
    {
        cont=0;
            // same riga  -----> orizzontale
            do{
                num=rand()%11;
                Xi=num;
                num=rand()%11;
                Yi=num;
                Yf=Yi;
                for(int i=Yi;i<Yi+1;i++)
                    {
                        if(defenceFieldCPU[Xi][i] == ASCII_SPACE) cont++;
                        else cont=0;
                    }
            }while(cont<1);
            Xi='A' +num;
            Xf=Xi;
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            
        azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
    }
*/
    return coordinateRandom;
}