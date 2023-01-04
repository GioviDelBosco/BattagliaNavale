#ifndef FIELDATTACCO
#define FIELDATTACCO

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int COL=12;
const int LINE=12;

class FieldAttacco
{

public:
    FieldAttacco();
    void StampaCampoAttacco(int line, int column, char& AttackField[COL][LINE]);
    void printGrigliaVuotaAttacco(int line, int column);
    void ConvertStringToInt(string coordinata,char& AttackField[COL][LINE]);

private:
    char *AttackField[COL][LINE];
};

#endif