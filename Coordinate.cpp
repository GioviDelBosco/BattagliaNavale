#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <time.h>
#include "Coordinate.h"

using namespace std;

Coordinate::Coordinate()
{
    srand((unsigned int)time(NULL));
}

vector<int> Coordinate::convertStringToInt(string coordinata)
{
    vector<int> coordinatine;
    stringstream ss(coordinata);
    // creo le 2 variabili per il posizionamneto della barca
    string coordinateXYi, coordinateXYf;
    ss >> coordinateXYi >> coordinateXYf;
    string Xo = coordinateXYi.substr(0, 1);
    string Yo = coordinateXYi.substr(1, coordinateXYi.length() - 1);
    string Xe = coordinateXYf.substr(0, 1);
    string Ye = coordinateXYf.substr(1, coordinateXYf.length() - 1);

    int Xi = 0;
    int Yi = stoi(Yo)-1 ;
    int Xf = 0;
    int Yf = stoi(Ye) -1;

    char elem = Xo.at(0);
    if (isalpha(elem))
    {
        elem = toupper(elem);
        Xi += static_cast<int>(elem - 'A' + 1) - 1;
        if (Xi > 8)
        {
            Xi = Xi - 2;
        }
    }

    char elem2 = Xe.at(0);

    if (isalpha(elem2))
    {
        elem2 = toupper(elem2);
        Xf += static_cast<int>(elem2 - 'A');
        if (Xf > 8)
        {
            Xf = Xf - 2;
        }
    }

    coordinatine.push_back(Xi);
    coordinatine.push_back(Yi);
    coordinatine.push_back(Xf);
    coordinatine.push_back(Yf);
    return coordinatine;
}

// creo un vettore di int
// vector<int> cacapupu = convertStringToInt(coordinata)
// uso o pop back o uso le quadre [0(Xi),1(Yi),2(Xf),3(Yf)]

vector<int> Coordinate::getCentro(string coordinata, char (&defenceFieldPlayer)[12][12])
{
    vector<int> coordinataCentro = Coordinate::convertStringToInt(coordinata);
    vector<int> coordinataFinale;
    // se la corazzata e' messa in orizzontale
    try
    {
        if (defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == 'C')
        {
            if (defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0]][(coordinataCentro[1]) + 1] && defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1] + 2] && defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1] - 1] && defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1] - 2]
                // nave in verticale
                || (defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0] + 1][coordinataCentro[1]] && defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0] + 2][coordinataCentro[1]] && defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0] - 1][coordinataCentro[1]] && defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0] - 2][coordinataCentro[1]]))
            {

                coordinataFinale.push_back(coordinataCentro[0]);
                coordinataFinale.push_back(coordinataCentro[1]);
                return coordinataFinale; //coordinata centro
            }
        }
        else if (defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == 'S')
        {
            if (defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0]][(coordinataCentro[1]) + 1] && defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1] - 1] || (defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0] + 1][coordinataCentro[1]] && defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == defenceFieldPlayer[coordinataCentro[0] - 1][coordinataCentro[1]]))
            {
                coordinataFinale.push_back(coordinataCentro[0]);
                coordinataFinale.push_back(coordinataCentro[1]);
                return coordinataFinale;
            }
        }
        else if (defenceFieldPlayer[coordinataCentro[0]][coordinataCentro[1]] == 'E')
        {
            coordinataFinale.push_back(coordinataCentro[0]);
            coordinataFinale.push_back(coordinataCentro[1]);
            return coordinataFinale;
        }
    }
    catch (const exception &e)
    {
        cout << "ERRORE: non hai inserito il centro" << endl;
        throw;
    }
}
// da rivedere un attimo perche' esegue tutti e due gli else in caso di barca verticale

bool Coordinate::posOccupataLine(int Xi, int Yi, int Yf, char (&defenceFieldCPU)[12][12]){
 
    bool posOccupata = 0;
 
    for(int i=Yi;i<=Yf;i++)
    {
        
        if(defenceFieldCPU[Xi][i] != '-') { 
            posOccupata=1;  
        }
    
        if(defenceFieldCPU[Xi][i] == 'C') { 
            posOccupata=1;  
        }
        if(defenceFieldCPU[Xi][i] == 'S') { 
            posOccupata=1;  
        }
        if(defenceFieldCPU[Xi][i] == 'E') { 
            posOccupata=1;  
        }

        
        
    }
    
    return posOccupata;
}
bool Coordinate::posOccupataCol(int Yi, int Xi, int Xf, char (&defenceFieldCPU)[12][12]){
 
    bool posOccupata = 0;   
    

    for(int i=Xi;i<=Xf;i++)
    {
        
        if(defenceFieldCPU[i][Yi] != '-') { 
            posOccupata=1;  
        }
         if(defenceFieldCPU[Xi][i] == 'C') { 
            posOccupata=1;  
        }
        if(defenceFieldCPU[Xi][i] == 'S') { 
            posOccupata=1;  
        }
        if(defenceFieldCPU[Xi][i] == 'E') { 
            posOccupata=1;  
        }
    }
    
    return posOccupata;
}


/*---------------new centro random--------------*/
vector<char> Coordinate::getCentroRandom(vector<string>coordinateCorazzate){
        int sceltaCorazzata =rand()%3;
        vector<char> coordinateCentroRnd;
        string C1 = coordinateCorazzate.at(sceltaCorazzata); //B6 B10
        char XI=C1.at(0);
        char YI=C1.at(1);
        char XF=C1.at(3);
        char YF=C1.at(4);
        char Xcentro,Ycentro;
        if(XI==XF){
            Xcentro=XI;
            Ycentro=YI+2;
        } 
        else if(YI==YF){
            Xcentro=XI+2;
            Ycentro=YI;
        }
        coordinateCentroRnd.push_back(Xcentro);
        coordinateCentroRnd.push_back(Ycentro);
        return coordinateCentroRnd;
    }



