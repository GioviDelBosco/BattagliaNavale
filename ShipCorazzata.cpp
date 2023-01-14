#include <string>
#include <iostream>
#include <vector>
#include "ShipCorazzata.h"
#include "Coordinate.h"
#include "FieldDifesa.h"
#include "FieldAttacco.h"

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

        if (defenceFieldCPU[coordinateX][coordinateY] != ' ')
        {
            attackFieldPlayer[coordinateX][coordinateY] = 'X';
        }
        else if (defenceFieldCPU[coordinateX][coordinateY] == ' ')
        {
            attackFieldPlayer[coordinateX][coordinateY] = 'O';
        }
    }else{
        cout<<"Hai inserito delle coordinate sbagliate";
    }
}
