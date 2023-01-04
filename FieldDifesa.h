#ifndef FIELDDIFESA
#define FIELDDIFESA

#include <iostream>
#include <string>

using namespace std;

class FieldDifesa
{

public:
    FieldDifesa();
    void StampaCampoDifesa(int line, int column, int DefenceField[12][12]);

private:
    char DefenceField[12][12];
    int col = 12;
    int line = 12;
};

#endif