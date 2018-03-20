#include "Invocacion.h"
#include "Tablero.h"

Invocacion::Invocacion() {
    pos_x = -1;
    pos_y = -1;
    nombre = "";
    coste = 0;
    ataque = 0;
    vida = 0;
    comandante=false;

}
Invocacion::Invocacion(string nombre,int coste,int ataque,int vida,int comandante) {
        this->nombre = nombre;
        this->coste = coste;
        this->ataque = ataque;
        this->vida = vida;
        this->comandante=comandante;
        
        if(!textura.loadFromFile("assets/Sprites/bloque2.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
        carta.setTexture(textura);
        
   
}

void Invocacion::moveToPos(int posx, int posy/*, Tablero& tablero*/){
    pos_x = posx;
    pos_y = posy;
}

Invocacion::~Invocacion() {
}

void Invocacion::setPosicion(int x, int y){
    pos_x=x;
    pos_y=y;
}

