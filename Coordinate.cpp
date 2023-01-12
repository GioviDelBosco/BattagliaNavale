#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<tuple>
#include "Coordinate.h"

using namespace std;

Coordinate::Coordinate(){

}

vector<int> Coordinate::convertStringToInt(string coordinata){
    vector<int> coordinatine;
    stringstream ss(coordinata);
    // creo le 2 variabili per il posizionamneto della barca
    string coordinateXYi, coordinateXYf;
    ss >> coordinateXYi >> coordinateXYf;
    string Xo = coordinateXYi.substr(0, 1);
    string Yo = coordinateXYi.substr(1, coordinateXYi.length() - 1);
    string Xe = coordinateXYf.substr(0, 1);
    string Ye = coordinateXYf.substr(1, coordinateXYf.length() - 1);

    

    int Xi=0;
    int Yi = stoi(Yo) - 1;
    int Xf=0;
    int Yf = stoi(Ye) - 1;


    char elem = Xo.at(0);
    if (isalpha(elem))
    {
        elem = toupper(elem);
        Xi += static_cast<int>(elem - 'A' + 1) - 1;
        if (Xi >= 10)
        {
            Xi = Xi - 2;
        }
    }
    
    char elem2 = Xe.at(0);
    {
        if (isalpha(elem2))
        {
            elem2 = toupper(elem2);
            Xf += static_cast<int>(elem2 - 'A');
            if (Xf >= 10)
            {
                Xf = Xf - 2;
            }
        }
    }

    coordinatine.push_back(Xi);
    coordinatine.push_back(Yi);
    coordinatine.push_back(Xf);
    coordinatine.push_back(Yf);   

    return coordinatine;
}
//creo un vettore di int
//vector<int> cacapupu = convertStringToInt(coordinata)
//uso o pop back o uso le quadre [0(Xi),1(Yi),2(Xf),3(Yf)]
//cacapupu[0]