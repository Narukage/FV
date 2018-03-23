#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Invocacion{
    private:
        int pos_x;
        int pos_y;
        int coste;
        int vida;
        int ataque;
        int jugarla=0; //posicion en la mano
        string nombre;
        bool existo=false;
        int comandante=1;
        sf::Texture textura;
        sf::Sprite carta;
        int unico;// -1 Es el jugador -2 es el rival
        
    public:
        Invocacion();
        Invocacion(string nombre,int coste,int vida,int ataque,int comandante,int unico);
        ~Invocacion();
        
        void moveToPos(int posx, int posy/*Tablero& tablero*/);
        void setPosicion(int x, int y);
        void setCarta(sf::Sprite carta){this->carta=carta;};
        int getX(){ return pos_x; };
        int getY(){ return pos_y; };
        sf::Sprite getSprite(){ return carta; };
        void setJugar(int jugar){this->jugarla=jugar;};
        int getJugar(){return jugarla;};
        void setExisto(){existo=true;};
        bool getExisto(){return existo;};
        int GetUnico(){return unico;};
};