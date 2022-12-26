//BGM(): Colapietro Mattia, Santoro Giuseppe, Sgaravatto Giovanni 
//main 
#include<iostream>
//#include<stdlib.h>
#include<string>
using namespace std;
const int COL=12;
const int LINE=12;

char YourField[LINE][COL];
char AttackField[LINE][COL];

void printGriglia(int line,int coloumn){
    //matrice[12]x[12]
    for(int i=0; i<line; i++){
        for(int j=0; j<coloumn; j++){
            cout<<YourField[i][j]<<"\t*";
            /*if(YourField[i][j]=='')
                cout<<YourField[i][j]<<" |";
                else
                    cout<<YourField[i][j]<<"|";
            */
        } 
        cout<<endl;
    }
    cout<<endl;
}
//posizionamento corazzate
void posizionaCor(string coordinate){

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
//posizionamento submarine
void posizionaSub(string coordinate){

    char x1Origin = coordinate[0];
    int Xo=(int)x1Origin-65;
    int Yo=(int)coordinate[1]-48;

    char x1Finish= coordinate[2];
    int Xf=(int)x1Finish-65;
   
    int Yf=(int)coordinate[3]-48;

    YourField[Xf][Yf]='E';
}
//posizionamento supporto
void posizionaSup(string coordinate){

    char x1Origin = coordinate[0];
    int Xo=(int)x1Origin-65;
    int Yo=(int)coordinate[1]-48;

    char x1Finish= coordinate[2];
    int Xf=(int)x1Finish-65;
   
    int Yf=(int)coordinate[3]-48;

    if(Xo==Xf) for(int i=Yo;i<Yf+1;i++) YourField[Xo][i]='S'; //tieni fissa la riga, cambia colonna 
    else 
    for(int i=Xo;i<Xf+1;i++) YourField[i][Yo]='S'; 
}


int main(){
    printGriglia(LINE,COL);
    string corazzata;
    string submarine;
    string supporto;
    //XY start XY finish ---> B2 B6
    for(int i=1;i<2;i++){
        cout<<"Inserisci coordinate per la corazzata "<<i<<" :";   
        cin>>corazzata;
        posizionaCor(corazzata);
        corazzata="";
    }
    //inserimento supporto
    for(int i=1;i<2;i++){
        cout<<"Inserisci coordinate per la nave di supporto "<<i<<" :";   
        cin>>supporto;
        posizionaSup(supporto);
        supporto="";

    }
    //inserimento submarine
    for(int i=1;i<2;i++){
        cout<<"Inserisci coordinate per il sottomarino "<<i<<" :";   
        cin>>submarine;
        posizionaSub(submarine);
        submarine="";
    }
    printGriglia(LINE,COL);
    return 0;
}
