#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "FieldAttacco.h"
#include "Coordinate.h"

using namespace std;
int cont = 0;
FieldAttacco::FieldAttacco()
{
    attackFieldPlayer[12][12];
}

void FieldAttacco::stampaCampoAttacco(char (&attackFieldPlayer)[12][12])
{
    cout << "Campo Attacco" << endl;
    cout << "\t";
    for (int col = 0; col < COLatk; col++)
    {
        cout << col + 1 << "\t";
    }
    cout << endl;
    // stampa righe senza J,K

    for (int i = 0; i < LINEatk; i++)
    {
        if (i == 9)
        {
            char NoJ = (char)(i + 67);
            cout << NoJ << "\t";
        }
        else if (i == 10)
        {
            char NoK = (char)(i + 67);
            cout << NoK << "\t";
        }
        else if (i == 11)
        {
            char JumpL = (char)(i + 67);
            cout << JumpL << "\t";
        }
        else
        {
            char IndexLine = (char)(i + 65);
            cout << IndexLine << "\t";
        }

        for (int c = 0; c < COLatk; c++)
        {
            cout << attackFieldPlayer[i][c] << "   |   ";
        }
        cout << endl;
    }
    cout << "\n";
}

// funzione conta barche rimanenti
void FieldAttacco::contaBarcheRimanenti(int barchePlayer, vector<string> coordinateP1, char (&defenceFieldPlayer)[12][12])
{

    vector<int> coordinateBarche;
    for (int i = 0; i < coordinateP1.size(); i++)
        coordinateBarche = Coordinate::convertStringToInt(coordinateP1[i]);
    vector<int> corazzate;
    for (int i = 0; i < 2 ;i++)
    {
        corazzate.push_back(coordinateBarche[i]);
    }
    vector<int> supporto;
    for (int i = 1; i < 2; i++)
    {
        supporto.push_back(coordinateBarche[i]);
    }
    vector<int> sottomarino;
    for (int i = 2; i < 3; i++)
    {
        sottomarino.push_back(coordinateBarche[i]);
    }

    //int affondato = 0;
    cout << "sono qua\n";
    for (int i = corazzate[0]; i <= corazzate[2]; i++)
    {
        for (int c = corazzate[1]; i <= corazzate[3]; c++)
        {

            cout << "contenuto nella posizione " << i << " " << c << " " << defenceFieldPlayer[i][c] << endl;
            /*if(defenceFieldPlayer[i][c]=='X')
            cont++;*/
        }
    }
    // cout<<cont<<endl;
    if (cont == 5)
        cout << "Nave corazzata affondata\n";
}

// vettore cordinate = cordinata P1
// barchePlayer numero di barche
/*barche=8
b6 b10 nel campo defence controllo che siano uguali a  XXXXX se sono uguali faccio barche--;
pop_back(posioneNave)
*/

/*
    coordinatine.push_back(Xi);
    coordinatine.push_back(Yi);
    coordinatine.push_back(Xf);
    coordinatine.push_back(Yf);
    return coordinatine;
*/

/*for (int i = coordinateP1[0]; i < 5; i++) //Linea
{
    for (int c = 0; c < 12; c++) // Colonna
    {
        if(defenceFieldPlayer[i][c]){

        }
    }

}*/