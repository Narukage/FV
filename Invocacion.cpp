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
Invocacion::Invocacion(string nombre,int coste,int vida,int ataque,int comandante,int unico) {
        this->nombre = nombre;
        this->coste = coste;
        this->ataque = ataque;
        this->vida = vida;
        this->comandante=comandante;
        this->unico=unico;

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
            if(!textcarta.loadFromFile("assets/Sprites/Zoogxredim.png")){
                std::cout<<"Textura en mano aplicada"<<std::endl;
            }
            devolver=true;
        }
        if(nombretext=="Yigx"){
            if(!textcarta.loadFromFile("assets/Sprites/Yigxredim.png")){
                std::cout<<"Textura en mano aplicada"<<std::endl;
            }
           devolver=true;
        }
        if(nombretext=="Cthughax"){
            if(!textcarta.loadFromFile("assets/Sprites/Cthughaxredim.png")){
                std::cout<<"Textura en mano aplicada"<<std::endl;
            }
            devolver=true;
        }
        if(nombretext=="Gugox"){
            if(!textcarta.loadFromFile("assets/Sprites/Gugoxredim.png")){
                std::cout<<"Textura en mano aplicada"<<std::endl;
            }
           devolver=true;
        }
        if(nombretext=="Bokrugs"){
            if(!textcarta.loadFromFile("assets/Sprites/Bokrugsredim.png")){
                std::cout<<"Textura en mano aplicada"<<std::endl;
            }
            devolver=true;
        }
        cartamano.setTexture(textcarta);
        cartamano.setPosition((i*100)+150,480);
    }
    return devolver;
}
bool Invocacion:: soyJugada(string nombretext){
    //
    bool devolver= false;
    if(mano==false){
        if(nombretext=="Zoogx"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/zoogxiddle.png",11,1,0.001f,11,1);
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
            devolver=true;
        }
        if(nombretext=="Cthughax"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/cthughaxiddle.png",10,1,0.001f,10,1);
            devolver=true;
        }
        if(nombretext=="Gugox"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/gugoxiddle.png",14,1,0.001f,14,1);
            devolver=true;
        }
        if(nombretext=="Bokrugs"){
            id = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/dolorArterial.png",14,1,0.001f,14,1);
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

