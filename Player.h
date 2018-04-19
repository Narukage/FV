#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Invocacion.h"
#include <vector>
#include <cstdlib>

#include <stdio.h>  	/* printf, scanf, puts, NULL */
#include <stdlib.h> 	/* srand, rand */
#include <time.h>   	/* time */



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
        int contador = 0;
        int posmano=0;
        vector<Invocacion*> mano;
        vector<Invocacion*> jugadas;
        vector<Invocacion*> invo;
        vector<Invocacion*> invo2;
        //Invocacion* mano= new Invocacion[5];//mano
       // Invocacion* insertar = new Invocacion[20];//en el tablero
        //Invocacion* invo= new Invocacion[20];//mazo
        /* A ver hay que hacer un array o una lista que guarde las cartas jugadas, borrar la carta de mano
         y la pones aqui, ademas el setposicion se tiene que hacer directamente en la carta que se añada en este array
         y no desde el puntero, hacer que unit(puntero) apunte a la invocacion que se meta en este array o lista*/
        Invocacion* man = new Invocacion();
        
        Invocacion* comandante= new Invocacion();
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
        Invocacion* getUnit(){  return comandante; };
        Invocacion* getMonstruo(Invocacion* montruito, int donde);
        vector<Invocacion*> getMano(){ return mano; };
        vector<Invocacion*> getJugadas(){return jugadas; };
        bool RellenarJugadas(Invocacion* jugada);
        bool eliminarMano(Invocacion* invo);
        bool eliminarJugadas(Invocacion* invo);
        bool RellenarMano(Invocacion* invo, int jugar);
        Invocacion* JugadaEn(int posx, int posy);
        int damePosicion(int posx,int posy);
        bool estaJugadaEn(int posx, int posy);
        void Robar();
        void setPosMano(int pos){posmano=pos;};
};

