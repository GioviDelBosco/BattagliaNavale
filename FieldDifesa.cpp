#include <string>
#include <iostream>
#include "FieldDifesa.h"

using namespace std;
FieldDifesa::FieldDifesa(){
    line=12;
    col=12;
}
void stampaCampoDifesa(int line, int column, int DefenceField[12][12]) {
    for(int i=1; i<=line; i++){
        for(int j=1; j<=column; j++){
            cout<<"|   "<<DefenceField[i][j]<<"\t";
        } 
        cout<<endl;
    }
    cout<<endl;
}