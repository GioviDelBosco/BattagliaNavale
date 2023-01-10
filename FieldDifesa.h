#ifndef FIELDDIFESA
#define FIELDDIFESA

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int COLdef = 12;
const int LINEdef = 12;

class FieldDifesa
{

public:
    FieldDifesa(); 

    void stampaCampoDifesa(char (&defendeField)[LINEdef][COLdef]);
    void printGrigliaVuotaDifesa(int line, int column);
    void convertStringToInt(string coordinata, char (&defendeField)[12][12]);

private:
    char defendeField[LINEdef][COLdef];
};

#endif