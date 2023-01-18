#ifndef CPU
#define CPU
#include <iostream>
#include <string>

using namespace std;

class Cpu{

    public:
        Cpu();
        string getCoordinateRND(int flag, char(&defenceFieldCPU)[12][12]);
        string getCoordinataRNDattacco(char (&defenceFieldCPU)[12][12]);
    private:
        
};
#endif