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
    com = false;
    mano = false;
}
Invocacion::Invocacion(string nombre,int coste,int vida,int ataque,int movimiento,int comandante,int unico) {
        this->nombre = nombre;
        this->coste = coste;
        this->ataque = ataque;
        this->vida = vida;
        this->comandante=comandante;
        this->unico=unico;
        this->movimiento=movimiento;
        this->movfijo=movimiento;
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
bool Invocacion:: esAliado(int comandante){
    if(comandante == this->comandante){
        return true;
    }
    return false;
}
int Invocacion::getComandante(){
    return this->comandante;
}
bool Invocacion:: soyManoT(string nombretext,int i){
    bool devolver = false;
    if(mano==true){
        std::cout << "mano true" << std::endl;
        if(nombretext=="Zoogx"){
            idcarta = RenderManager::Instance(1)->getMotor()->crearSprite("assets/Sprites/Zoogxredim.png");
            devolver=true;
        }
        if(nombretext=="Yigx"){
            idcarta = RenderManager::Instance(1)->getMotor()->crearSprite("assets/Sprites/cartayigx.png");
            devolver=true;
        }
        if(nombretext=="Cthughax"){
            idcarta = RenderManager::Instance(1)->getMotor()->crearSprite("assets/Sprites/Cthughaxredim.png");
            devolver=true;
        }
        if(nombretext=="Gugox"){
            idcarta = RenderManager::Instance(1)->getMotor()->crearSprite("assets/Sprites/gugoxcarta.png");
            devolver=true;
        }
        if(nombretext=="Bokrugs"){
            idcarta = RenderManager::Instance(1)->getMotor()->crearSprite("assets/Sprites/Bokrugsredim.png");
            devolver=true;
        }
    }
    return devolver;
}
bool Invocacion:: soyJugada(string nombretext){
    //
    bool devolver= false;
    if(mano==false){
        if(nombretext=="Zoogx"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/zoogxiddle.png",11,1,0.001f,11,1);
            idcartasel = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/zoogxcartaanimacion.png",10,1,0.001f,10,1);
            devolver=true;
        }
         if(nombretext=="comandante1"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/com1iddle.png",13,1,0.001f,13,1);
            devolver=true;
        }
        if(nombretext=="comandante2"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/com2iddle.png",14,1,0.001f,14,1);
            devolver=true;
        }
        if(nombretext=="Yigx"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/yigxiddle.png",14,1,0.001f,14,1);
            idcartasel = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/yigxcartaanimacion.png",10,1,0.001f,10,1);
            devolver=true;
        }
        if(nombretext=="Cthughax"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/cthughaxiddle.png",10,1,0.001f,10,1);
            idcartasel = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/cthughaxcartaanimacion.png",10,1,0.001f,10,1);
            devolver=true;
        }
        if(nombretext=="Gugox"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/GUGOXITO.png",12,1,0.001f,12,1);
            idcartasel = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/gugoxcartaanimacion.png",10,1,0.001f,10,1);
            devolver=true;
        }
        if(nombretext=="Bokrugs"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/dolorArterial.png",14,1,0.001f,14,1);
            idcartasel = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/cartaanimacion.png",10,1,0.001f,10,1);
            devolver=true;
        }
    }
    return devolver;
}
void Invocacion:: setPosition(float positionX, float positionY){
    //monstruo.setPosition(positionX,positionY);
}
void Invocacion:: setScale(float scaleX, float scaleY){
    //monstruo.setScale(sf::Vector2f(scaleX,scaleY));
    
}

