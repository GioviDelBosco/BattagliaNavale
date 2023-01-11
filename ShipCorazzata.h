#ifndef CORAZZATA
#define CORAZZATA

#include <iostream>
#include <string>

using namespace std;

class ShipCorazzata{
    
    public:
        ShipCorazzata();
        void fuoco(int coordinateX,int coordinateY, char (&attackFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12]);

    private:
        int dimensione;
        int corazza;

};

#endif