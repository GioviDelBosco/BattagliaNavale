#ifndef CORAZZATA
#define CORAZZATA

#include <iostream>
#include <string>

using namespace std;

class ShipCorazzata{
    
    public:
        ShipCorazzata();
        void fuoco();
        void inserisciCorazzata();

    private:
        int dimensione;
        int corazza;

};

#endif