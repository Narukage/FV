#include "FachadaMotor2D.h"
#include <string>

//Crea la ventana del juego, le paso tamanyo de la ventana, fps y si lleva o no vsync
void FachadaMotor2D::crearVentana(int width, int height, int frames, bool vsync){
    sf::RenderWindow window(sf::VideoMode(width,height),"Summoners");
    window.setFramerateLimit(frames);
    window.setVerticalSyncEnabled(vsync);
}

void FachadaMotor2D::crearAnimacion(){
    
}

//Crea un sprite, le paso la url de la textura para cargarla en memoria
int FachadaMotor2D::crearSprite(std::string &url){
    //Cargamos la textura
    if(!s.textura.loadFromFile(url)){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    //Reservamos memoria para el sprite, ya que ahora es un puntero
    s.sprite = new sf::Sprite;
    //Asignamos la textura al sprite
    s.sprite->setTexture(s.textura);
    //Guardo el sprite en un array de sprites
    
    //Hacemos id++ para que el id propio del sprite cambie
    s.id = cont;
    cont++;
    //Devolvemos el id propio del sprite que se ha creado
    return s.id;
}

bool FachadaMotor2D::borrarSprite(int id){
    
}
//Dibuja en la ventana del juego
void FachadaMotor2D::dibujar(){
    
}
