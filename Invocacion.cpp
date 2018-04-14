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
Invocacion::Invocacion(string nombre,int coste,int vida,int ataque,int comandante,int unico) {
        this->nombre = nombre;
        this->coste = coste;
        this->ataque = ataque;
        this->vida = vida;
        this->comandante=comandante;
        this->unico=unico;
        
     /*   if(!textura.loadFromFile("assets/Sprites/bloque2.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
        carta.setTexture(textura);*/
        
   
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
    bool devolver= false;
    if(mano==false){
        if(nombretext=="Zoogx"){
            if(!textura.loadFromFile("assets/Sprites/Zoogx.png")){
                std::cout<<"Textura jugada aplicada"<<std::endl;
            }
            devolver=true;
        }
         if(nombretext=="comandante1"){
            if(!textura.loadFromFile("assets/Sprites/comandante1.png")){
                std::cout<<"Textura jugada aplicada"<<std::endl;
            }
            devolver=true;
        }
        if(nombretext=="comandante2"){
            if(!textura.loadFromFile("assets/Sprites/comandante2.png")){
                std::cout<<"Textura jugada aplicada"<<std::endl;
            }
            devolver=true;
        }
        if(nombretext=="Yigx"){
            if(!textura.loadFromFile("assets/Sprites/Yigx.png")){
                std::cout<<"Textura jugada aplicada"<<std::endl;
            }
            devolver=true;
        }
        if(nombretext=="Cthughax"){
            if(!textura.loadFromFile("assets/Sprites/Cthughax.png")){
                std::cout<<"Textura jugada aplicada"<<std::endl;
            }
            devolver=true;
        }
        if(nombretext=="Gugox"){
            if(!textura.loadFromFile("assets/Sprites/Gugox.png")){
                std::cout<<"Textura jugada aplicada"<<std::endl;
            }
            devolver=true;
        }
        if(nombretext=="Bokrugs"){
            if(!textura.loadFromFile("assets/Sprites/Bokrugs.png")){
                std::cout<<"Textura jugada aplicada"<<std::endl;
            }
            devolver=true;
        }

        monstruo.setTexture(textura);
        //carta.setPosition((i*100)+150,480);
    }
    return devolver;
}
void Invocacion:: setPosition(float positionX, float positionY){
    monstruo.setPosition(positionX,positionY);
}
void Invocacion:: setScale(float scaleX, float scaleY){
    monstruo.setScale(sf::Vector2f(scaleX,scaleY));
    
}

