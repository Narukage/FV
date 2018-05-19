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
        int vida;            //Vida
        int mana;            //Mana máximo
        int manarest;        //Mana restante, nunca tenemos 4,5 de mana.
        sf::Texture textura; //?
        sf::Texture textura2;//?
        sf::Texture textura3;//?
        sf::Sprite retrato;  //Retrato del personaje con 6 y un 4
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
        
        Invocacion* comandante;
                
    public:
        ///////////////////////////////
        // CONSTRUCTO / DESTRUCTOR
        ///////////////////////////////
        Player(int commander);
        ~Player();
        
        ///////////////////////////////
        // FUNCIONES DE LA MANO
        ///////////////////////////////
        Invocacion* getMonstruo(Invocacion* montruito, int donde);
        void Mostrar_mano(sf::RenderWindow& window);
        void ResetStats();
        bool RellenarJugadas(Invocacion* jugada);
        bool eliminarMazo(Invocacion* invo);
        bool eliminarMano(Invocacion* invo);
        //bool eliminarManoIa(Invocacion* inv);
        bool eliminarJugadas(Invocacion* invo);
        bool RellenarMano(Invocacion* invo, int jugar);
        Invocacion* JugadaEn(int posx, int posy);
        int damePosicion(int posx,int posy);
        bool estaJugadaEn(int posx, int posy);
        void Robar();
        
        ///////////////////////////////
        // GETTERS Y SETTERS
        ///////////////////////////////
        void setLife(int x)                 { vida=x;           };
        void setMana(int x)                 { mana=x;           };
        void setManaRest(int x)             { manarest=x;       };
        void setPosMano(int pos)            { posmano=pos;      };
        int getLife()                       { return vida;      };
        int getMana()                       { return mana;      };
        int getManaRest()                   { return manarest;  };
        vector<Invocacion*> getMano()       { return mano;      };
        vector<Invocacion*> getJugadas()    { return jugadas;   };
        Invocacion* getUnit()               { return comandante;};
       
};

