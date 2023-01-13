#include <string>
#include <iostream>
#include<vector>
#include "ShipCorazzata.h"
#include "Coordinate.h"

using namespace std;

ShipCorazzata::ShipCorazzata(){
    dimensione=5;
    corazza=5;
}; 

/*
    La corazzata fa fuoco su determinate coordinate. Il colpo va a segno se la casella
    colpita è occupata da un’unità avversaria. Se la corazza dell’unità bersaglio raggiunge 0
    (tutte le caselle in cui l’unità è presente sono state colpite), l’unità bersaglio viene
    affondata
*/
void fuoco(char (&attackFieldPlayer)[12][12], char (&defenceFieldCPU)[12][12],string coordinata){
    
    vector<int> listaCoordinate = Coordinate::convertStringToInt(coordinata); 
    int coordinateY = listaCoordinate.pop_back();
    int coordinateX = listaCoordinate.pop_back();

    
    if(defenceFieldCPU[coordinateX][coordinateY]!=' '){
        attackFieldPlayer[coordinateX][coordinateY]='X';
    }else if(defenceFieldCPU[coordinateX][coordinateY]==' '){
        attackFieldPlayer[coordinateX][coordinateY]='O';
    } 
}

