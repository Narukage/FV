#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>
#include <cstdlib>


using namespace std;

class IA{
private:
    Player* jugadorEnemigo;
    
    
    
 public:
     IA();
     IA(Player* player);
     Player* getPlayer(){return jugadorEnemigo;}
     void setPlayer(Player* player){jugadorEnemigo = player;}
};
