#ifndef CORAZZATA
#define CORAZZATA

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ShipCorazzata{
    
    public:
        ShipCorazzata();
        void fuoco(string comando, char (&attackFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12], char (&defenceFieldPlayer)[12][12]);

    private:
        int dimensione;
        int corazza;

};

#endif