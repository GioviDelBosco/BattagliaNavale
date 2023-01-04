#ifndef SUPPORTO
#define SUPPORTO

#include <iostream>
#include <string>

using namespace std;

class ShipSupporto{
    public:
        ShipSupporto();
        void muoviERipara();
        void inserisciSupporto();
    private:
        int dimensione;
        int corazza;

};
#endif