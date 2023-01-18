#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>

using namespace std;

class Player{
    public:
        Player();
        //provare  a fare piu "piazza barca" per ogni barca // vedere di semplificarne con uno
        void piazzaBarca(int flag, char (&defenceFieldPlayer)[12][12], string coordinata);
        void muoviBarca(char (&defenceFieldPlayer)[12][12], string coordinata);

    private:
        

};
#endif
/*
    per reditarieta andare sulla classe figlia e mettere Class nomeclasse : public nomeClasseMadre
    per chiamare una funzione basta scriverla normalmente
*/