// BGM(): Colapietro Mattia, Santoro Giuseppe, Sgaravatto Giovanni
// main
#include <iostream>
#include <string>
#include <sstream>
#include "ShipSupporto.h"
#include "ShipCorazzata.h"
#include "ShipSottomarino.h"

using namespace std;

// creo il campo
const int COL = 12;
const int LINE = 12;

char YourField[LINE][COL];
char AttackField[LINE][COL];

// MAIN
int main()
{
    string coordinata;

    // Creiamo gli oggetti ship
    ShipCorazzata naveDaBattaglia;
    ShipSupporto naveDiSupporto;
    ShipSottomarino sottomarino;

    //stampo gli indici delle colonne
    cout << "\t";
    for (int i = 1; i <= 12; i++)
    {
        cout << i << "\t";
    }
    cout << endl;

    for (int i = 0; i < LINE; i++)
    {
        
        cout << i + 1 << "\t";
        for (int c = 0; c < COL; c++)
        {
            cout << "A   |   ";
        }
        cout << endl;
    }
    
    cout<<"\n";
    /*
        >> Quali sono le coordinate per la corazzata 1:
        >> B6 B10

    */
    cout<<"Inserisci le coordinate dove vuoi inserire la corazzata 1\n";
    getline(std::cin, coordinata);
    stringstream ss(coordinata);

    //creo le 2 variabili per il posizionamneto della barca
    string coordinateXYi, coordinateXYf;
    ss >> coordinateXYi >> coordinateXYf;

    cout << "Le coordinate iniziali = " << coordinateXYi << "\nLe coordinate finali = " << coordinateXYf << std::endl;
    string Xo = coordinateXYi.substr(0,1);
    string Yo = coordinateXYi.substr(1,coordinateXYi.length()-1); 
    string Xe = coordinateXYf.substr(0,1);
    string Ye = coordinateXYf.substr(1,coordinateXYf.length()-1);
    int Xi;
    int Yi= stoi(Yo);
    int Xf;
    int Yf= stoi(Ye);
    for (auto& elem : Xo)
    {
        if(isalpha(elem))
        {
            elem = toupper(elem);
            Xi += static_cast<int>(elem - 'A' + 1);
        }
    }
    for (auto& elem : Xe)
    {
        if(isalpha(elem))
        {
            elem = toupper(elem);
            Xf += static_cast<int>(elem - 'A' + 1);
        }
    }
    //int Xi=atoi(Xo);
    //int Xf=static_cast<int>(Xe)-65;
    //int Yi=static_cast<int>(Yo);
    cout<<Xi<<"\n";
    cout<<Yi<<"\n";
    cout<<Xf<<"\n";
    return 0;
}

/*void Ship::PosizionaBattleShip(string coordinate){
    //VALIDO SOLO PER COORDINATE CON LETTRE MAIUSCOLE
    char x1Origin = coordinate[0];
    int Xo=(int)x1Origin-65;
    int Yo=(int)coordinate[1]-48;

    char x1Finish= coordinate[2];
    int Xf=(int)x1Finish-65;
   
    int Yf=(int)coordinate[3]-48;

    if(Xo==Xf) for(int i=Yo;i<Yf+1;i++) YourField[Xo][i]='C'; //tieni fissa la riga, cambia colonna 
    else 
    for(int i=Xo;i<Xf+1;i++) YourField[i][Yo]='C'; 
}
*/

/*
    shorturl.at/nBZ16
    std::cout << "Enter text \n";
    std::string text{};
    getline(std::cin, text);
    int sum{};
    for (auto& elem : text)
    {
        if(isalpha(elem))
        {
            elem = toupper(elem);
            sum += static_cast<int>(elem - 'A' + 1);
        }
    }
    std::cout << sum << "\n";
}
*/