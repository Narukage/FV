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
        bool com;  //???????????????'
        bool mano; //????
        int unico;// -1 Es el jugador -2 es el rival
        int idsprite;
        int id;
        int idcarta;
        
    public:
        ///////////////////////////////
        // CONSTRUCTO / DESTRUCTOR
        ///////////////////////////////
        Invocacion();
        Invocacion(string nombre,int coste,int vida,int ataque,int comandante,int unico);
        ~Invocacion();
        
        ///////////////////////////////
        // FUNCIONES PRINCIPALES
        ///////////////////////////////
        void moveToPos(int posx, int posy/*Tablero& tablero*/);
        bool esAliado(int comandante);
        bool soyManoT(string nombretext,int i);
        bool soyJugada(string nombretext);
        
        ///////////////////////////////
        // GETTERS Y SETTERS
        ///////////////////////////////
        void setPosicion(int x, int y);
        void setJugar(int jugar)                            { this->jugarla=jugar;  };
        void setExisto()                                    { existo=true;          };
        void setVida(int vida)                              { this->vida = vida;    };
        void setMano(bool man)                              { mano=man;             };
        void setPosition(float positionX,float positionY);
        void setScale(float scaleX,float scaleY);
        void setCom(bool coman)                             { com=coman;            };
        int getX()                                          { return pos_x;         };
        int getY()                                          { return pos_y;         };
        int getJugar()                                      { return jugarla;       };
        bool getExisto()                                    { return existo;        };
        int GetUnico()                                      { return unico;         };
        int getComandante();
        int getVida()                                       { return vida;          };
        int getAtaque()                                     { return ataque;        };
        string getNombre()                                  { return nombre;        };
        bool getMano()                                      { return mano;          };
        bool getCom()                                       { return com;           };
        int getCoste()                                      { return coste;         };
        int getId()                                         { return id;            };
        int getIdCarta()                                    { return idcarta;       };
};