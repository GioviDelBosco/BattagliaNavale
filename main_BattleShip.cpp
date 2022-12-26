//BGM(): Colapietro Mattia, Santoro Giuseppe, Sgaravatto Giovanni 
//main 
#include<iostream>
#include<string>
#include "Ship.h"
using namespace std;
const int COL=12;
const int LINE=12;

char YourField[LINE][COL];
char AttackField[LINE][COL];

int main(){
    string battleship;
    string support;
    string submarine;
    for(int i=0;i<3;i++){
        //XY start XY finish ---> B2 B6
        cout<<"Inserire coordinata corazzata "<<i+1<<"(XY Origin XY Finish): ";
        cin>>battleship;
        PosizionaBattleship(battleship);
    }
    for(int i=0;i<2;i++){
        //XY start XY finish ---> B2 B6
        cout<<"Inserire coordinata support "<<i+1<<"(XY Origin XY Finish): ";
        cin>>support;
        Ship::PosizionaSupport(support);
    }
    for(int i=0;i<1;i++){
        //XY start XY finish ---> B2 B6
        cout<<"Inserire coordinata submarine "<<i+1<<"(XY Origin XY Finish): ";
        cin>>submarine;
        PosizionaSubmarine(submarine);
    }
    PrintBattleField();
    return 0;
}