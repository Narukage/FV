#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
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
        sf::Texture textcarta;
        sf::Sprite monstruo;
        sf::Sprite cartamano;
        bool com=false;
        bool mano=false;
        int unico;// -1 Es el jugador -2 es el rival
        
    public:
        Invocacion();
        Invocacion(string nombre,int coste,int vida,int ataque,int comandante,int unico);
        ~Invocacion();
        
        void moveToPos(int posx, int posy/*Tablero& tablero*/);
        void setPosicion(int x, int y);
       // void setCarta(sf::Sprite carta){this->monstruo=monstruo;};
        int getX(){ return pos_x; };
        int getY(){ return pos_y; };
        sf::Sprite getSprite(){ return monstruo; };
        void setJugar(int jugar){this->jugarla=jugar;};
        int getJugar(){return jugarla;};
        void setExisto(){existo=true;};
        bool getExisto(){return existo;};
        int GetUnico(){return unico;};
        bool esAliado(int comandante);
        int getComandante();
        void setVida(int vida){this->vida = vida;};
        int getVida(){return vida;};
        int getAtaque(){return ataque;};
        string getNombre(){return nombre;};
        bool getMano(){return mano;};
        void setMano(bool man){mano=man;};
        sf::Sprite getSpriteM(){ return cartamano; };
        bool soyManoT(string nombretext,int i);
        bool soyJugada(string nombretext);
        void setPosition(float positionX,float positionY);
        void setScale(float scaleX,float scaleY);
        bool getCom(){return com;};
        void setCom(bool coman){com=coman;};
        int getCoste(){return coste;}
        
};