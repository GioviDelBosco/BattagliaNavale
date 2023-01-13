#ifndef COORDINATE
#define COORDINATE

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Coordinate 
{

public:
    Coordinate();
    static vector<int> convertStringToInt(string coordinata);
    static vector<int> getCentro(string coordinata);

private:
    
};

#endif