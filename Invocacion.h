#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Invocacion{
    private:
        int pos_x;
        int pos_y;
        
    public:
        Invocacion();
        ~Invocacion();
        void moveToPos(int posx, int posy/*Tablero& tablero*/);
        void setPosicion(int x, int y);
        int getX(){ return pos_x; };
        int getY(){ return pos_y; };
};