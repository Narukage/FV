#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Player{
    private:
        int vida;
        float mana;
        float manarest;
        sf::Texture textura;
        sf::Texture textura2;
        sf::Sprite retrato;
        
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

