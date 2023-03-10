#ifndef FIELDATTACCO
#define FIELDATTACCO

#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"

using namespace std;

const int COLatk = 12;
const int LINEatk = 12;

class FieldAttacco : public Player
{

public:
    FieldAttacco(); 

    void stampaCampoAttacco(char (&attackFieldPlayer)[LINEatk][COLatk]);
    void printGrigliaVuotaAttacco(int line, int column);
    void convertStringToInt(string coordinata, char (&attackFieldPlayer)[12][12]);
    void contaBarcheRimanenti(int barchePlayer,vector <string> coordinateP1,char (&defenceFieldPlayer)[12][12]);

private:
    char attackFieldPlayer[LINEatk][COLatk];
};

#endif