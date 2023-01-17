#ifndef SOTTOMARINO
#define SOTTOMARINO

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ShipSottomarino 
{

public:
    ShipSottomarino();
    void muoviECerca(char (&attackFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12], char (&defenceFieldPlayer)[12][12], string coordinata);

private:
    int dimensione;
    int corazza;
};

#endif