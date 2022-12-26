//classe stampa griglia 
#include<iostream>
using namespace std;
const int LINE=12;
const int COLUMN=12;
void PrintField(){
    //matrice[12]x[12]
    char campo[LINE][COLUMN];
    for(int i=0; i<LINE; i++){
        cout<<"_____________________________________"<<endl;
        cout<<"|";
        for(int j=0; j<COLUMN; j++){
            cout<<" |";
        } 
        cout<<endl;
    }
    cout<<"_____________________________________"<<endl;
    cout<<endl;
}