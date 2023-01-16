#ifndef SUPPORTO
#define SUPPORTO

#include <iostream>
#include <string>

using namespace std;

class ShipSupporto {
    public:
        ShipSupporto();
        void muoviERipara(string comando, char (&defenceFieldPlayer)[12][12]);
        void inserisciSupporto();
    private:
        int dimensione;
        int corazza;

};
#endif