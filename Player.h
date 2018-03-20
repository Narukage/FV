#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Invocacion.h"
#include "Tablero.h"

using namespace std;

class Player{
    private:
        int vida;
        float mana; //int mana
        float manarest; // int mana restante, nunca tenemos 4,5 de mana.
        sf::Texture textura;
        sf::Texture textura2;
        sf::Texture textura3;
        sf::Sprite retrato;
       // int soy = 1;
        Invocacion mano[5]; 
        Invocacion invo[19];
        Invocacion comandante;
        sf::Sprite carta;
        

    public:
        Player(int commander);
        ~Player();
        void setLife(int x){ vida=x; };
        void setMana(int x){ mana=x; };
        int getLife(){ return vida; };
        int getMana(){ return mana; };
        void Mostrar_mano(sf::RenderWindow& window);
        sf::Sprite getRetrato(){ return retrato; };
        float getManaRest(){ return manarest; };
};

