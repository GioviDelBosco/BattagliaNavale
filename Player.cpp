#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include "Player.h"
#include "Coordinate.h"

using namespace std;

Player::Player(){

}
//tolgo le coordinate e uso un vettore
void Player::piazzaBarca(int flag, char (&defenceFieldPlayer)[12][12], string coordinata){
    int Xi,Yi,Xf,Yf;
    tie(Xi,Yi,Xf,Yf)=Coordinate::convertStringToInt(coordinata);


    switch (flag)
    {

    // corazzata
    case 0:
        // se le Y nella mappa sono le stesse, scrive solo nelle X
        if (Yi == Yf)
        {
            for (int i = Xi; i <= Xf; i++)
            {
                defenceFieldPlayer[i][Yi] = 'C';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (Xi == Xf)
        {
            for (int i = Yi; i <= Yf; i++)
            {
                defenceFieldPlayer[Xi][i] = 'C';
            }
        }
        break;
    // supporto
    case 1:
        // se le Y nella mappa sono le stesse, scrive solo nelle X
        if (Yi == Yf)
        {
            for (int i = Xi; i <= Xf; i++)
            {
                defenceFieldPlayer[i][Yi] = 'S';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (Xi == Xf)
        {
            for (int i = Yi; i <= Yf; i++)
            {
                defenceFieldPlayer[Xi][i] = 'S';
            }
        }
        break;
    // sottomarino
    case 2:
        if (Yi == Yf)
        {
            for (int i = Xi; i <= Xf; i++)
            {
                defenceFieldPlayer[i][Yi] = 'E';
            }
        }
        // se le X nella mappa sono le stesse, scrive solo nelle Y
        if (Xi == Xf)
        {
            for (int i = Yi; i <= Yf; i++)
            {
                defenceFieldPlayer[Xi][i] = 'E';
            }
        }
        break;
    }

}
void Player::muoviBarca(){
    
}
void Player::usaBarca(){
    
}
