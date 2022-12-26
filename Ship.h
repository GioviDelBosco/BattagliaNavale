//Progetto BattleShip
/*
Gruppo: BGM
Membri: Mattia Colapietro, Giuseppe Santoro, Giovanni Sgaravatto*/


//file.h Ship
#ifndef SHIPH
#define SHIPH
#include<iostream>
#include<string>

using namespace std;

class Ship{
    public:
    Ship();
    //Ship(int line, int column);
    void PrintBattleField();
    void PosizionaBattleShip(string coordinata);
    void PosizionaSubmarine(string coordinata);
    void PosizionaSupport(string coordinata);
};
#endif