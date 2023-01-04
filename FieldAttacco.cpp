#include <string>
#include <iostream>
#include "FieldAttacco.h"

using namespace std;

void stampaCampo(int line, int column, int AttackField[LINE][COL]) {
    for(int i=1; i<=line; i++){
        for(int j=1; j<=column; j++){
            cout<<"|   "<<AttackField[i][j]<<"\t";
        } 
        cout<<endl;
    }
    cout<<endl;
}