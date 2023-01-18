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
    //getcentro e getcentroRandom, verificano se coordinata passa è centro 
    static vector<int> getCentro(string coordinata, char (&defenceFieldPlayer)[12][12]);
    vector<char> getCentroRandom(vector<string>coordinateCorazzate);
    bool posOccupataLine(int Xi, int Yi, int Yf, char (&defenceFieldCPU)[12][12]);
    bool posOccupataCol(int Yi, int Xi, int Xf, char (&defenceFieldCPU)[12][12]);
   
private:
    
};

#endif