#include "Invocacion.h"
#include "Tablero.h"

Invocacion::Invocacion() {
    pos_x = -1;
    pos_y = -1;
}

void Invocacion::moveToPos(int posx, int posy/*, Tablero& tablero*/){
    //tablero->moveToPos(posx, posy, this);
}

Invocacion::~Invocacion() {
}

void Invocacion::setPosicion(int x, int y){
    pos_x=x;
    pos_y=y;
}