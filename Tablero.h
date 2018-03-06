#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define HEIGHT 10
#define WIDTH 20

class Tablero{
    private:
        
        struct boardInfo {
            //Invocacion unit;
            bool free;
            int coordX;
            int coordY;
            bool spawn1; //spawn permitted commander1
            bool spawn2; //spawn permitted commander2
            
        };
        
       boardInfo board[HEIGHT][WIDTH]; //board matrix with information about what it contains
              
    public:
        Tablero();
        ~Tablero();
        bool addUnit(int posx, int posy/*, Invocacion& unit*/); //return true if adds a unit at the location succesfully
        bool moveToPos(int posx, int posy); //returns true if unit is moved succesfully
        bool removeUnit(int posx, int posy); //returns true if unit is removed succesfully
        void resetMap();
        void drawMap();
        
        //GETTERS & SETTERS
        bool isFree(int posx, int posy){ return board[posx][posy].free; };
};