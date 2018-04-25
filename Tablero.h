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
            bool free;        // Ocupado o no por obstaculo
            int coordX;       // Coordenada X
            int coordY;       // Coordenada Y
            bool spawn1;      // spawn permitted commander1
            bool spawn2;      // spawn permitted commander2
            int alcanzable=0; // Nùmero casillas adyacentes accesibles
        };
        
        //Variables de tablero
        boardInfo board[WIDTH][HEIGHT]; //board matrix with information about what it contains
        int offsetX; //Espacio por la izquierda
        int offsetY; //Espacio por arriba
        int sizeX;   //Tamaño de la casilla en X
        int sizeY;   //Tamaño de la casilla en Y
        
        //Jugadores
        Player* player1;
        Player* player2;
        
        //orden del turno
        bool turno=true;
        
        //Variables de sprites
        float spriteSize; //Resolución de los sprites
        
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
        int retrato1;
        int retrato2;
        int idle;
      
       sf::Texture texturacarta;
       
       //Variables principales
       static Tablero* pinstance; //Puntero del objeto
       sf::RenderWindow* window;  //Ventana del juego
       
    protected:
        ///////////////////////////////
        // CONSTRUCTO / DESTRUCTOR
        ///////////////////////////////
        Tablero();
        Tablero(const Tablero&);
        
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
        
        ///////////////////////////////
        // DIBUJADO
        ///////////////////////////////
        void drawMap();
        void drawAdyacentes();
        void drawUnit();
        void drawInvocaciones(vector<Invocacion*> array);
        void ReiniciarAdy();
        void drawLife(int commander);
        void drawLifeNumb(int commander);
        void drawManaRest(int commander);
        void drawManaNumb(int commander);
        void drawBarra(int commander);
        void drawMana(int commander);
        void drawRetrato(int commander);
        
        void Mostrar_mano(sf::RenderWindow& window);
        bool isFree(int posx, int posy);
        
        ///////////////////////////////
        // GETTERS Y SETTERS
        ///////////////////////////////
        void setWindow(sf::RenderWindow* w) { window = w;    };
        void setTurno(bool metoca)          { turno=metoca;  };
        Player* getPlayer()                 { return player1;};
        
        void setFree(int posx,int posy,bool set);
};