#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#define WIDTH 12
#define HEIGHT 8

//SINGLETON

using namespace std;

class Tablero{
    private:
        
        struct boardInfo {
            Invocacion* unit;
            bool free;
            int coordX;
            int coordY;
            bool spawn1; //spawn permitted commander1
            bool spawn2; //spawn permitted commander2
            sf::Sprite sprite;
            
        };

        int matx;
        int maty;
        
       boardInfo board[WIDTH][HEIGHT]; //board matrix with information about what it contains
       sf::Texture textura;
       sf::Texture textura2;
       sf::Texture textura3;
       
       static Tablero* pinstance;
       
    protected:
        Tablero();
        Tablero(const Tablero&);
        Tablero &operator=(const Tablero&);
    public:
        static Tablero* Instance();
        ~Tablero();
        bool addUnit(int posx, int posy, Invocacion* unit, int spawn); //return true if adds a unit at the location succesfully
        bool moveToPos(int posx, int posy, Invocacion* unit); //returns true if unit is moved succesfully
        bool removeUnit(int posx, int posy, Invocacion* unit); //returns true if unit is removed succesfully
        bool cartaCogida(int posx, int posy);
        bool esCarta(int posx, int posy);
        void resetMap();
        void drawMap(sf::RenderWindow& window);
        
        //GETTERS & SETTERS
        bool isFree(int posx, int posy);
};