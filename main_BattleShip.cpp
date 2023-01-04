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
//STAMPA GRIGLIA CON POSIZIONAMENTI 
void Griglia(int line,int column){
    //cout<<"\t";
    for(int i=1; i<=line; i++){
        for(int j=1; j<=column; j++){
            cout<<"|   "<<YourField[i][j]<<"\t";
        } 
        cout<<endl;
    }
    cout<<endl;
}

//STAMPA GRIGLIA VUOTA
void printGrigliaVuota(int line,int coloumn){
    //matrice[12]x[12]
    cout << "\t";
    for (int col = 0; col<COL; col++)
    {
        cout << col + 1 << "\t";
    }
    cout << endl;
    //stampa righe senza J,K

    for (int i = 0; i < LINE; i++)
    {
        if(i==9){
            char NoJ=(char)(i+67);
            cout <<  NoJ<< "\t";
        }
        else if(i==10)
        {
            char NoK=(char)(i+67);
            cout <<  NoK<< "\t";
        }
        else if(i==11){
            char JumpL=(char)(i+67);
            cout<< JumpL<< "\t";
        }
        else{
            char IndexLine=(char)(i+65);
        cout <<  IndexLine<< "\t";
        }
        
        for (int c = 0; c < COL; c++)
        {
            cout << "    |   ";
        }
        cout << endl;
    }
    cout<<"\n";
}

//COORDINATE CORAZZATA
void ConvertStringToInt(string coordinata){
    stringstream ss(coordinata);
    //creo le 2 variabili per il posizionamneto della barca
    string coordinateXYi, coordinateXYf;
    ss >> coordinateXYi >> coordinateXYf;

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
            Xi += static_cast<int>(elem - 'A'); // DA CAPIRE PERCHé SENZA IL +1
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
    if(Xi==Xf)for(int i=Yi;i<Yf+1;i++) YourField[Xi][i]='C'; //tieni fissa la riga, cambia colonna 
    else 
    for(int i=Xi;i<Xf+1;i++) YourField[i][Yi]='C'; 
}


// MAIN
int main()
{
    printGrigliaVuota(LINE,COL);
    string coordinata;

    // Creiamo gli oggetti ship
    ShipCorazzata naveDaBattaglia;
    ShipSupporto naveDiSupporto;
    ShipSottomarino sottomarino;

    //stampo gli indici delle colonne numerate
    /*
        >> Quali sono le coordinate per la corazzata 1:
        >> B6 B10
    */
   
   for(int i=0;i<1;i++)
   {
    cout<<"Inserisci le coordinate della "<<i+1<<" corazzata\n";
    getline(std::cin, coordinata);
    //stringstream ss(coordinata);
    ConvertStringToInt(coordinata);
   }
    Griglia(LINE,COL);
    return 0;
} 
