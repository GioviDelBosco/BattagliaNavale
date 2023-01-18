#ifndef SUPPORTO
#define SUPPORTO

#include <iostream>
#include <string>

using namespace std;

class ShipSupporto {
    public:
        ShipSupporto();
        void muoviERipara(string comando, char (&defenceFieldPlayer)[12][12]);
        bool checkPosArrivoLine(string coordinata, char (&defenceFieldPlayer)[12][12]);
        bool checkPosArrivoCol(string coordinata, char (&defenceFieldPlayer)[12][12]);
    private:
        int dimensione;
        int corazza;

};
#endif