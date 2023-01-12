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
    static tuple<int,int,int,int> convertStringToInt(string coordinata);

private:
    
};

#endif