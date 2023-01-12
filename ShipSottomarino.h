#ifndef SOTTOMARINO
#define SOTTOMARINO

#include <iostream>
#include <string>

using namespace std;

class ShipSottomarino 
{

public:
    ShipSottomarino();
    void muoviECerca();
    void inserisciSottomarino();

private:
    int dimensione;
    int corazza;
};

#endif