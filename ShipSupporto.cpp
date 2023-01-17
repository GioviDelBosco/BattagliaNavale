#include <iostream>
#include <string>
#include "ShipSupporto.h"
#include "Coordinate.h"

using namespace std;

ShipSupporto::ShipSupporto(){
    dimensione = 3;
    corazza = 3;
};
void ShipSupporto::muoviERipara(string comando, char (&defenceFieldPlayer)[12][12]){

    /*vector<int> listaCoordinate = Coordinate::convertStringToInt(comando);
  
   int coordinataXi = listaCoordinate.at(0);
   int coordinataYi = listaCoordinate.at(1);
   int coordinataXf = listaCoordinate.at(2);
   int coordinataYf = listaCoordinate.at(3);

   if (coordinataXi == Coordinate::getCentro(comando,defenceFieldPlayer).at(0) &&
    coordinataYi == Coordinate::getCentro(comando,defenceFieldPlayer).at(1)){

        if()
        
    }
    else{
        cout<<"non hai inserito il centro della nave corretto\n";
    }

        if (defenceFieldCPU[coordinateX][coordinateY] != ' ')
        {
            attackFieldPlayer[coordinateX][coordinateY] = 'X';
        }
        else if (defenceFieldCPU[coordinateX][coordinateY] == ' ')
        {
            attackFieldPlayer[coordinateX][coordinateY] = 'O';
        }*/
   



}
bool ShipSupporto::checkPosArrivoLine(string coordinata, char (&defenceFieldPlayer)[12][12]){
    
    bool isCorrect = 1;
    vector<int> posizioneArrivo = Coordinate::convertStringToInt(coordinata);
    if(posizioneArrivo[3]+1>11){

        isCorrect = 0;
        cout<<"Coordinata di arrivo non valida\n";
    }
    else{
        isCorrect = 1;
    }

    return isCorrect;
}

bool ShipSupporto::checkPosArrivoCol(string coordinata, char (&defenceFieldPlayer)[12][12]){
    
    bool isCorrect = 1;
    vector<int> posizioneArrivo = Coordinate::convertStringToInt(coordinata);
    if(posizioneArrivo[2]+1>11){

        isCorrect = 0;
        cout<<"Coordinata di arrivo non valida\n";
    }
    else{
        isCorrect = 1;
    }

    return isCorrect;
}

void inserisciSupporto(){

}