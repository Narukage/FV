#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "Player.h"
#define WIDTH 12
#define HEIGHT 8

//SINGLETON

using namespace std;

class Tablero{
    private:
        //Crear clase Casilla que contenga los atributos del struct
        struct boardInfo {
            Invocacion* unit= new Invocacion();;
           
            bool free;
            int coordX;
            int coordY;
            bool spawn1; //spawn permitted commander1
            bool spawn2; //spawn permitted commander2
            sf::Sprite sprite;
            int alcanzable=0;
            
        };
        
        Player* player1;
        Player* player2;
        
       boardInfo board[WIDTH][HEIGHT]; //board matrix with information about what it contains
       sf::Texture texturabloqueazul;
       sf::Texture texturabloquerojo;
       sf::Texture texturabloqueverde;
       sf::Texture texturavida;
       sf::Texture texturalife;
       sf::Texture texturacarta;
       sf::Sprite carta;
       sf::Sprite sprite;
       sf::Sprite sprite2;
       sf::Font font;
       sf::Text manar;
       sf::Text vida;
       sf::Text mananumb;
       sf::Text barra;
       sf::CircleShape coco;
       
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
        void Adyacentes(int posx, int posy);
        int getAlcanzable(int posx, int posy);
        Invocacion* esCarta(int posx, int posy);
        void resetMap();
        void drawMap(sf::RenderWindow& window);
        void drawAdyacentes(sf::RenderWindow& window);
        void ReiniciarAdy();
        Invocacion* getUnit(int posx, int posy);
       
        void drawLife(int commander, sf::RenderWindow& window);
        sf::Text drawLifeNumb(int commander);
        sf::Text drawManaRest(int commander);
        sf::Text drawManaNumb(int commander);
        sf::Text drawBarra(int commander);
        void drawMana(int commander, sf::RenderWindow& window);
        void drawRetrato(int commander, sf::RenderWindow& window);
        void Mostrar_mano(sf::RenderWindow& window);
        
        //GETTERS & SETTERS
        bool isFree(int posx, int posy);
        Player* getPlayer(){return player1;};
};