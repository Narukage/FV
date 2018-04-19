#ifndef FACHADAMOTOR2D_H
#define FACHADAMOTOR2D_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "IFachada.h"
#include <vector>


class FachadaMotor2D : public IFachada {
private:
    int cont = 0;
    struct Sprite{
        int id;
        sf::Texture textura;
        sf::Sprite *sprite;
    };
    
    Sprite s;
    std::vector<Sprite*> sprites;
    
public:
    FachadaMotor2D() : IFachada(){};
    virtual ~FachadaMotor2D(){};
    void crearVentana();
    void crearAnimacion();
    void crearSprite();
    bool borrarSprite(int id);
    void dibujar();
};

#endif

