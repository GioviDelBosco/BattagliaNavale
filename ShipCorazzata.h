#ifndef CORAZZATA
#define CORAZZATA

#include <iostream>
#include <string>

using namespace std;

class ShipCorazzata{
    
    public:
        ShipCorazzata();
        void fuoco(string comando, char (&attackFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12]);

    private:
        int dimensione;
        int corazza;

};

#endif