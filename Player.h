#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Baraja.h"
#include "Tablero.h"

using namespace std;

class Player{
    private:
        int vida;
        float mana; //int mana
        float manarest; // int mana restante, nunca tenemos 4,5 de mana.
        sf::Texture textura;
        sf::Texture textura2;
        sf::Sprite retrato;
        Baraja actual;
        Invocacion comandante;
        
    public:
        Player(int commander);
        ~Player();
        void setLife(int x){ vida=x; };
        void setMana(int x){ mana=x; };
        int getLife(){ return vida; };
        int getMana(){ return mana; };
        sf::Sprite getRetrato(){ return retrato; };
        float getManaRest(){ return manarest; };
};

