#ifndef FIELDATTACCO
#define FIELDATTACCO

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int COLatk = 12;
const int LINEatk = 12;

class FieldAttacco
{

public:
    FieldAttacco(); 

    void stampaCampoAttacco(char (&attackField)[LINEatk][COLatk]);
    void printGrigliaVuotaAttacco(int line, int column);
    void convertStringToInt(string coordinata, char (&attackField)[12][12]);

private:
    char attackField[LINEatk][COLatk];
};

#endif