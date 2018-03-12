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
    Invocacion mano[10];
    int cantidad;
    
public:
    Baraja();
    //Baraja(string mazo);
    virtual ~Baraja();


};



