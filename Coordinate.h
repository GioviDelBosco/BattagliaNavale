#ifndef COORDINATE
#define COORDINATE

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "FieldDifesa.h"
#include "FieldAttacco.h"
using namespace std;

class Coordinate 
{

public:
    Coordinate();
    static vector<int> convertStringToInt(string coordinata);
    static vector<int> getCentro(string coordinata, char (&defenceFieldPlayer)[12][12]);

private:
    
};

#endif