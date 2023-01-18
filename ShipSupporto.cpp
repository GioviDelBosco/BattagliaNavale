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

    string nuovacoordinata;
    bool state = 1;
    vector<int> coordinataCentroBarca = Coordinate::getCentro(comando, defenceFieldPlayer);
    vector<int> posizioneArrivo = Coordinate::convertStringToInt(comando);
    // se sono nella stessa riga
    if (coordinataCentroBarca[0] == posizioneArrivo[2])
    {
        // se mi sposto verso destra o sinistra

            defenceFieldPlayer[posizioneArrivo[2]][posizioneArrivo[3] - 1] = 'S';
            defenceFieldPlayer[posizioneArrivo[2]][posizioneArrivo[3]] = 'S';
            defenceFieldPlayer[posizioneArrivo[2]][posizioneArrivo[3] + 1] = 'S';

            // pulizia posizione vecchia
            defenceFieldPlayer[coordinataCentroBarca[0]][coordinataCentroBarca[1] - 1] = '-';
            defenceFieldPlayer[coordinataCentroBarca[0]][coordinataCentroBarca[1]] = '-';
            defenceFieldPlayer[coordinataCentroBarca[0]][coordinataCentroBarca[1] + 1] = '-';

            //ripara area 3x3
            defenceFieldPlayer[posizioneArrivo[2] - 1][posizioneArrivo[3] - 1] = ripara(posizioneArrivo.at((2)-1),posizioneArrivo.at((3)-1),defenceFieldPlayer);
            defenceFieldPlayer[posizioneArrivo[2] - 1][posizioneArrivo[3]] = ripara(posizioneArrivo.at((2)-1),posizioneArrivo.at((3)),defenceFieldPlayer);
            defenceFieldPlayer[posizioneArrivo[2] - 1][posizioneArrivo[3] + 1] = ripara(posizioneArrivo.at((2)-1),posizioneArrivo.at((3)+1),defenceFieldPlayer);

            defenceFieldPlayer[posizioneArrivo[2] + 1][posizioneArrivo[3] - 1] = ripara(posizioneArrivo.at((2)+1),posizioneArrivo.at((3)-1),defenceFieldPlayer);
            defenceFieldPlayer[posizioneArrivo[2] + 1][posizioneArrivo[3]] = ripara(posizioneArrivo.at((2)+1),posizioneArrivo.at((3)),defenceFieldPlayer);
            defenceFieldPlayer[posizioneArrivo[2] + 1][posizioneArrivo[3] + 1] = ripara(posizioneArrivo.at((2)+1),posizioneArrivo.at((3)+1),defenceFieldPlayer);

    }
        // se sono nella stessa colonna
    else if (coordinataCentroBarca[1] == posizioneArrivo[3])
    {   
        // se mi sposto verso il basso o verso l'alto

            defenceFieldPlayer[posizioneArrivo[2] - 1][posizioneArrivo[3]] = 'S';
            defenceFieldPlayer[posizioneArrivo[2]][posizioneArrivo[3]] = 'S';
            defenceFieldPlayer[posizioneArrivo[2] + 1][posizioneArrivo[3]] = 'S';

            // pulizia posizione vecchia
            defenceFieldPlayer[coordinataCentroBarca[0] - 1][coordinataCentroBarca[1]] = '-';
            defenceFieldPlayer[coordinataCentroBarca[0]][coordinataCentroBarca[1]] = '-';
            defenceFieldPlayer[coordinataCentroBarca[0] + 1][coordinataCentroBarca[1]] = '-';

            //ripara area 3x3
            defenceFieldPlayer[posizioneArrivo[2] - 1][posizioneArrivo[3] - 1] = ripara(posizioneArrivo.at((2)-1),posizioneArrivo.at((3)-1),defenceFieldPlayer);
            defenceFieldPlayer[posizioneArrivo[2]][posizioneArrivo[3] - 1] = ripara(posizioneArrivo.at((2)),posizioneArrivo.at((3)-1),defenceFieldPlayer);
            defenceFieldPlayer[posizioneArrivo[2] + 1][posizioneArrivo[3] - 1] = ripara(posizioneArrivo.at((2)+1),posizioneArrivo.at((3)-1),defenceFieldPlayer);

            defenceFieldPlayer[posizioneArrivo[2] - 1][posizioneArrivo[3] + 1] = ripara(posizioneArrivo.at((2)-1),posizioneArrivo.at((3)+1),defenceFieldPlayer);
            defenceFieldPlayer[posizioneArrivo[2]][posizioneArrivo[3] + 1] = ripara(posizioneArrivo.at((2)),posizioneArrivo.at((3)+1),defenceFieldPlayer);
            defenceFieldPlayer[posizioneArrivo[2] + 1][posizioneArrivo[3] + 1] = ripara(posizioneArrivo.at((2)+1),posizioneArrivo.at((3)+1),defenceFieldPlayer);
        
    }
    
    else{
        cout<<"Coordinate non valide"<<endl;
    }

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

char ShipSupporto::ripara(int posArrivoX, int posArrivoY, char (&defenceFieldPlayer)[12][12]){

    if(defenceFieldPlayer[posArrivoX][posArrivoY] =='c'){ return 'C'; }
    if(defenceFieldPlayer[posArrivoX][posArrivoY] =='s'){ return 'S'; }
    if(defenceFieldPlayer[posArrivoX][posArrivoY] =='e'){ return 'E'; }

}