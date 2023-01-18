#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "ShipCorazzata.h"
#include "Coordinate.h"
#include "FieldDifesa.h"
#include "FieldAttacco.h"
#include "Cpu.h"

using namespace std;

ShipCorazzata::ShipCorazzata()
{
    dimensione = 5;
    corazza = 5;
};

/*
    La corazzata fa fuoco su determinate coordinate. Il colpo va a segno se la casella
    colpita è occupata da un’unità avversaria. Se la corazza dell’unità bersaglio raggiunge 0
    (tutte le caselle in cui l’unità è presente sono state colpite), l’unità bersaglio viene
    affondata
*/
void ShipCorazzata::fuoco(string comando, char (&attackFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12], char (&defenceFieldPlayer)[12][12])
{
    int coordinateY = 0;
    int coordinateX = 0;
    int coordinataCX = 0;
    int coordinataCY = 0;
    vector<int> listaCoordinate = Coordinate::convertStringToInt(comando);
    coordinateY = listaCoordinate.at(3);
    coordinateX = listaCoordinate.at(2);
    coordinataCY = listaCoordinate.at(1);
    coordinataCX = listaCoordinate.at(0);


    if (coordinataCX == Coordinate::getCentro(comando,defenceFieldPlayer).at(0) && coordinataCY == Coordinate::getCentro(comando,defenceFieldPlayer).at(1))
    {

        if (defenceFieldCPU[coordinateX][coordinateY] != '-')
        {
            attackFieldPlayer[coordinateX][coordinateY] = 'X';

            if(defenceFieldCPU[coordinateX][coordinateY] == 'C')
                defenceFieldCPU[coordinateX][coordinateY] == 'c';
            else if(defenceFieldCPU[coordinateX][coordinateY] == 'S')
                defenceFieldCPU[coordinateX][coordinateY] == 's';
             else if(defenceFieldCPU[coordinateX][coordinateY] == 'E')
                defenceFieldCPU[coordinateX][coordinateY] == 'e';

                
        }
        else if (defenceFieldCPU[coordinateX][coordinateY] == '-')
        {
            attackFieldPlayer[coordinateX][coordinateY] = 'O';
        }
    }else{
        cout<<"Hai inserito delle coordinate sbagliate";
    }
}
void ShipCorazzata::fuocoRandom(vector<char> coordinateCentroRnd,char (&attackFieldCPU)[12][12], char (&defenceFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12]){
    
    int Xt, Yt = 0; //coordinate target
    int coordinateX = 0;
    int coordinateY = 0;
    ostringstream ss;
    char coordinataCX = coordinateCentroRnd.at(0); //XY origin, centro della corazzata
    char coordinataCY = coordinateCentroRnd.at(1);
    //target
    Xt=rand()%12;
    Yt=rand()%12;
    
    
    ss << coordinataCX << coordinataCY << " "<< Xt << Yt;
    string comando;
    vector<int> listaCoordinate = Coordinate::convertStringToInt(comando);
    coordinateY = listaCoordinate.at(3);
    coordinateX = listaCoordinate.at(2);
    coordinataCY = listaCoordinate.at(1);
    coordinataCX = listaCoordinate.at(0);

    

        if (defenceFieldPlayer[coordinateX][coordinateY] != '-')
        {
            attackFieldCPU[coordinateX][coordinateY] = 'X';

            if(defenceFieldPlayer[coordinateX][coordinateY] == 'C')
                defenceFieldPlayer[coordinateX][coordinateY] == 'c';
            else if(defenceFieldPlayer[coordinateX][coordinateY] == 'S')
                defenceFieldPlayer[coordinateX][coordinateY] == 's';
             else if(defenceFieldPlayer[coordinateX][coordinateY] == 'E')
                defenceFieldPlayer[coordinateX][coordinateY] == 'e';

        }
        else if (defenceFieldPlayer[coordinateX][coordinateY] == '-')
        {
            attackFieldCPU[coordinateX][coordinateY] = 'O';
        }
}




/*void ShipCorazzata::fuocoRandom(string comando,char (&attackFieldCPU)[12][12], char (&defenceFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12]){
    
    int coordinateY = 0;
    int coordinateX = 0;
    int coordinataCX = 0;
    int coordinataCY = 0;
    vector<int> listaCoordinate = Coordinate::convertStringToInt(comando);
    coordinateY = listaCoordinate.at(3);
    coordinateX = listaCoordinate.at(2);
    coordinataCY = listaCoordinate.at(1);
    coordinataCX = listaCoordinate.at(0);

    if (coordinataCX == Coordinate::getCentro(comando,defenceFieldCPU).at(0) && coordinataCY == Coordinate::getCentro(comando,defenceFieldCPU).at(1))
    {

        if (defenceFieldPlayer[coordinateX][coordinateY] != '-')
        {
            attackFieldCPU[coordinateX][coordinateY] = 'X';
        }
        else if (defenceFieldPlayer[coordinateX][coordinateY] == '-')
        {
            attackFieldCPU[coordinateX][coordinateY] = 'O';
        }
    }else{
        cout<<"Hai inserito delle coordinate sbagliate";
    }
}*/