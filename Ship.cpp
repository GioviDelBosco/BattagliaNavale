#ifndef SHIP
#define SHIP
#include <iostream>
#include <string>
#include "Ship.h"

using namespace std;

const int COL=12;
const int LINE=12;

char YourField[LINE][COL];
char AttackField[LINE][COL];

Ship::Ship(int size, int x, int y){
    shipSize = size;
    posX = x;
    posY = y;
}

void Ship::PosizionaBattleShip(string coordinate){
    //VALIDO SOLO PER COORDINATE CON LETTRE MAIUSCOLE
    char x1Origin = coordinate[0];
    int Xo=(int)x1Origin-65;
    int Yo=(int)coordinate[1]-48;

    char x1Finish= coordinate[2];
    int Xf=(int)x1Finish-65;
   
    int Yf=(int)coordinate[3]-48;

    if(Xo==Xf) for(int i=Yo;i<Yf+1;i++) YourField[Xo][i]='C'; //tieni fissa la riga, cambia colonna 
    else 
    for(int i=Xo;i<Xf+1;i++) YourField[i][Yo]='C'; 
}

//posizionamento submarine
void Ship::PosizionaSubmarine(string coordinate){
    //VALIDO SOLO PER COORDINATE CON LETTRE MAIUSCOLE
    char x1Origin = coordinate[0];
    int Xo=(int)x1Origin-65;
    int Yo=(int)coordinate[1]-48;

    char x1Finish= coordinate[2];
    int Xf=(int)x1Finish-65;
   
    int Yf=(int)coordinate[3]-48;

    YourField[Xf][Yf]='E';
}

//posizionamento supporto
void Ship::PosizionaSupport(string coordinate){
    //VALIDO SOLO PER COORDINATE CON LETTRE MAIUSCOLE
    char x1Origin = coordinate[0];
    int Xo=(int)x1Origin-65;
    int Yo=(int)coordinate[1]-48;

    char x1Finish= coordinate[2];
    int Xf=(int)x1Finish-65;
   
    int Yf=(int)coordinate[3]-48;

    if(Xo==Xf) for(int i=Yo;i<Yf+1;i++) YourField[Xo][i]='S'; //tieni fissa la riga, cambia colonna 
    else 
    for(int i=Xo;i<Xf+1;i++) YourField[i][Yo]='S'; 
}

//stampa Field
void Ship::PrintBattleField(){
    for(int i=0; i<LINE; i++){
        for(int j=0; j<COL; j++){
            cout<<YourField[i][j]<<"\t*";
            /*if(YourField[i][j]=='')
                cout<<YourField[i][j]<<" |";
                else
                    cout<<YourField[i][j]<<"|";
            */
        } 
        cout<<endl;
    }
    cout<<endl;
}
#endif