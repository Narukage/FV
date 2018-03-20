#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Invocacion.h"

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
  
        Invocacion mano[5];
        /* A ver hay que hacer un array o una lista que guarde las cartas jugadas, borrar la carta de mano
         y la pones aqui, ademas el setposicion se tiene que hacer directamente en la carta que se añada en este array
         y no desde el puntero, hacer que unit(puntero) apunte a la invocacion que se meta en este array o lista*/
        Invocacion* man = new Invocacion();
        Invocacion invo[19];
        Invocacion comandante;
        Invocacion *com;
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
        Invocacion* getUnit(){ com=&comandante; return com; };
        Invocacion* getMano(){ man=mano; return man; };
};

