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
    int num, Yi, Yf,cont=0,XI;
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
                XI=num-1;
                do{
                    num=rand()%11;
                }while(num>7);
                Yi=num;
                Yf=Yi+4;
                
                for(int i=Yi;i<Yf+1;i++)
                    {
                        
                        if(defenceFieldCPU[XI][i] == ' ') {
                            //cout<<"libero"<<endl;
                            cont++;
                            
                        }
                    }
                }while(cont<5);//casella.posOccupataLine(Xi,Yi,Yf,defenceFieldCPU)==1);
            Xi='A' + XI;
            Xf=Xi;
            if(Yi == 0){
                Yf += 1;
            }
            
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            //cout << " coordinate" << coordinateRandom <<endl ;
            
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
            XI=num-1;
            
            for(int i=XI;i<XI+4;i++)
                    {
                        
                        if(defenceFieldCPU[i][Yi] == ' ') {
                            cont++;
                        }
                    }
                }while(cont<5);//casella.posOccupataLine(Xi,Yi,Yf,defenceFieldCPU)==1);
            //}while(casella.posOccupataCol(Xi,Yi,Yf,defenceFieldCPU)==1);
        Xi='A' + XI;
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
        //cout << " coordinate " << coordinateRandom <<endl ;
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
                XI=num-1;
                do{
                    num=rand()%11;
                }while(num>9);
                Yi=num;
                if(Yi == 0){
                Yf += 1;
                }
                else{
                    Yf=Yi+2;
                }
                
                for(int i=Yi;i<Yf+1;i++)
                    {
                        
                        if(defenceFieldCPU[XI][i] == ' ') {
                            cont++;
                            
                        }
                    }
                }while(cont<3);//casella.posOccupataLine(Xi,Yi,Yf,defenceFieldCPU)==1);
                    
                //}while(casella.posOccupataLine(Xi,Yi,Yf,defenceFieldCPU)==1);
                Xi='A' +XI;
                Xf=Xi;
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();
            //cout << " coordinate" << coordinateRandom <<endl ;
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
            XI=num-1;
            for(int i=XI;i<XI+2;i++)
                    {
                        
                        if(defenceFieldCPU[i][Yi] == ' ') {
                            cont++;
                        }
                    }
                }while(cont<3);//casella.posOccupataLine(Xi,Yi,Yf,defenceFieldCPU)==1);
            
            //}while(casella.posOccupataCol(Xi,Yi,Yf,defenceFieldCPU));
            Xi='A' +XI;
            Xf=Xi+2;
            ss << Xi << Yi << " " << Xf << Yf;
            coordinateRandom = ss.str();           
            //cout << " coordinate" << coordinateRandom <<endl ;

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