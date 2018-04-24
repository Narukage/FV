#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "Player.h"
#include "RenderManager.h"
#define WIDTH 12
#define HEIGHT 8

//SINGLETON

using namespace std;

class Tablero{
    private:
        //Crear clase Casilla que contenga los atributos del struct
        struct boardInfo {
            Invocacion* unit=new Invocacion();
           
            bool free;
            int coordX;
            int coordY;
            bool spawn1; //spawn permitted commander1
            bool spawn2; //spawn permitted commander2
            int alcanzable=0;
            
        };
        
        Player* player1;
        Player* player2;
        bool turno=true;
        int idverde;
        int idrojo;
        int idazul;
        int idvidacu;
        int idvidaco;
        int fuente;
        int fuentemana;
        int manarest;
        int barra;
        int mana;
        
       boardInfo board[WIDTH][HEIGHT]; //board matrix with information about what it contains
       sf::Texture texturacarta;
       
       static Tablero* pinstance;
       
    protected:
        Tablero();
        Tablero(const Tablero&);
        Tablero &operator=(const Tablero&);
    public:
        static Tablero* Instance();
        ~Tablero();
        void clear();
        bool addUnit(int posx, int posy, Invocacion* unit, int spawn); //return true if adds a unit at the location succesfully
        bool moveToPos(int fromx, int fromy,int gox, int goy, Invocacion* unit); //returns true if unit is moved succesfully
        int atackToPos(int fromx, int fromy,int gox, int goy);
        bool removeUnit(int posx, int posy, Invocacion* unit); //returns true if unit is removed succesfully
        void Adyacentes(int posx, int posy);
        int getAlcanzable(int posx, int posy);
        Invocacion* esCarta(int posx, int posy);
        void resetMap();
        void drawMap(sf::RenderWindow& window);
        void drawAdyacentes(sf::RenderWindow& window);
        void drawUnit(sf::RenderWindow& window);
        void ReiniciarAdy();
       
        void drawLife(int commander, sf::RenderWindow& window);
        void drawLifeNumb(int commander, sf::RenderWindow& window);
        void drawManaRest(int commander, sf::RenderWindow& window);
        void drawManaNumb(int commander, sf::RenderWindow& window);
        void drawBarra(int commander, sf::RenderWindow& window);
        void drawMana(int commander, sf::RenderWindow& window);
        void drawRetrato(int commander, sf::RenderWindow& window);
        void Mostrar_mano(sf::RenderWindow& window);
        void setFree(int posx,int posy,bool set);
        //GETTERS & SETTERS
        bool isFree(int posx, int posy);
        void setTurno(bool metoca){turno=metoca;};
        Player* getPlayer(){return player1;};
};