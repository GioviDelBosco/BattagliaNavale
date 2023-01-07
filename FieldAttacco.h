#ifndef FIELDATTACCO
#define FIELDATTACCO

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int COL = 12;
const int LINE = 12;

class FieldAttacco
{

public:
    FieldAttacco(); 

    void stampaCampoAttacco(char (&attackField)[COL][LINE]);
    void printGrigliaVuotaAttacco(int line, int column);
    void convertStringToInt(string coordinata, char (&attackField)[12][12]);

private:
    char attackField[COL][LINE];
};

#endif