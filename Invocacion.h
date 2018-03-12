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
        string nombre;
        bool comandante=false;
        sf::Texture textura;
        
    public:
        Invocacion();
        Invocacion(string nombre,int coste,int vida,int ataque,bool comandante);
        ~Invocacion();
        
        void moveToPos(int posx, int posy/*Tablero& tablero*/);
        void setPosicion(int x, int y);
        int getX(){ return pos_x; };
        int getY(){ return pos_y; };
};