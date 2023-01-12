#ifndef FIELDDIFESA
#define FIELDDIFESA

#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"

using namespace std;

const int COLdef = 12;
const int LINEdef = 12;

class FieldDifesa : public Player
{

public:
    FieldDifesa(); 

    void stampaCampoDifesa(char (&defenceFieldPlayer)[LINEdef][COLdef]);
    void printGrigliaVuotaDifesa(int line, int column);

private:
    char defenceFieldPlayer[LINEdef][COLdef];
};

#endif