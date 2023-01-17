#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "Cpu.h"
#include "Player.h"
#include "Coordinate.h"

using namespace std;

Player azione;

Cpu::Cpu()
{
    srand((unsigned int)time(NULL));
};

string Cpu::getCoordinateRND(int flag, char (&defenceFieldCPU)[12][12]){

    string coordinateRandom;
    int RoC;
    char ASCII_C='C';
    char ASCII_S='S';
    char ASCII_E='E';
    ostringstream ss; // riga o colonna casuale
    int num, Yi, Yf;
    char Xi, Xf;

    //bool occ=1;

    Coordinate casella;
    
    if(flag==0){
        
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
                /*
                for(int i=Yi;i<Yf+1;i++)
                    {
                        
                        if(defenceFieldCPU[Xi][i] == ASCII_C || defenceFieldCPU[Xi][i] == ASCII_S || defenceFieldCPU[Xi][i] == ASCII_E) { 
                            occ=1;
                            break;
                        }
                        else {
                            occ=0;
                        }
                    }
                */
            }while(casella.posOccupataLine(Xi,Yi,Yf,defenceFieldCPU)==1);
            Xi='A' + num;
            Xf=Xi;
            if(Yi == 0){
                Yf += 1;
            }
            
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            cout << " flag 0 C" << "riga" << coordinateRandom <<endl ;
            
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
            /*
            for(int i=Xi;i<Xi+5;i++)
            {
                
                if(defenceFieldCPU[i][Yi] == ASCII_C || defenceFieldCPU[i][Yi] == ASCII_S || defenceFieldCPU[i][Yi] == ASCII_E){
                    occ=1;
                    break;
                    }
                else {
                    occ=0;
                    
                }
            }
            */
            }while(casella.posOccupataCol(Xi,Yi,Yf,defenceFieldCPU)==1);
        Xi='A' + num;
        if(Xi == 'A'){
            Xf +=1;
        }
        if(Xi > 'E'){
             Xf=Xi+6;
        }
        else {
            Xf=Xi+4;
        }
        ss << Xi << Yi << " " << Xf << Yf;
        coordinateRandom = ss.str();        
            cout << " flag 0 C" << "colonna" << coordinateRandom <<endl ;

        azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
        } 
    }

    else if(flag==1)
    {
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
                /*for(int i=Yi;i<Yf+1;i++)
                    {
                        
                        if(defenceFieldCPU[Xi][i] == ASCII_C || defenceFieldCPU[Xi][i] == ASCII_S || defenceFieldCPU[Xi][i] == ASCII_E ) {
                            occ=1;
                            break;
                        }
                        else{
                            occ=0;
            
                        }
                    }*/
                }while(casella.posOccupataLine(Xi,Yi,Yf,defenceFieldCPU)==1);
                Xi='A' +num;
                Xf=Xi;
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            cout << " flag 1 S" << "riga" << coordinateRandom <<endl ;

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
            
            /*for(int i=Xi;i<Xi+3;i++)
            {
                if(defenceFieldCPU[i][Yi] == ASCII_C || defenceFieldCPU[i][Yi] == ASCII_S || defenceFieldCPU[i][Yi] == ASCII_E ){
                    occ=1;
                    break;
                } 
                else {
                    occ=0;
                }
            }*/
            }while(casella.posOccupataCol(Xi,Yi,Yf,defenceFieldCPU));
            Xi='A' +num;
            Xf=Xi+2;
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();           
             cout << " flag 0 C" << "colonna" << coordinateRandom <<endl ;

            azione.piazzaBarca(flag,defenceFieldCPU,coordinateRandom);
        } 
    }
/*
    else if(flag==2)
    {
            // same riga  -----> orizzontale
            do{
                num=rand()%11;
                Xi=num;
                num=rand()%11;
                Yi=num;
                Yf=Yi;
                for(int i=Yi;i<Yi+1;i++)
                    {
                        if(defenceFieldCPU[Xi][i] == ASCII_C || ) cont++;
                        el
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