#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Invocacion.h"
#include <fstream>
using namespace std;

class Baraja {
private:
    Invocacion invo[19];
    bool comandante =false; //comandante false = Nosotros ; true = rival
    Invocacion mano[10];    //lo del comandante lo he hecho yo como
    int cantidad;           //comandante=1 yo, comandante=2 enemigo
    
    
public:
    Baraja();
    //Baraja(string mazo);
    virtual ~Baraja();
    Invocacion* getMano(){ return mano; };
    


};



