#ifndef FIELDATTACCO
#define FIELDATTACCO

#include <iostream>
#include <string>

using namespace std;

const int COL = 12;
const int LINE = 12;

class FieldAttacco{
    
    public:
        FieldAttacco();
        void StampaCampo(int line, int column, int AttackField[LINE][COL]);
    private:
        char AttackField[LINE][COL];

};

#endif