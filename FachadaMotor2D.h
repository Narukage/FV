#ifndef FACHADAMOTOR2D_H
#define FACHADAMOTOR2D_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "IFachada.h"
#include <vector>


class FachadaMotor2D : public IFachada {
private:
    struct Sprite{
        int id;
        sf::Texture textura;
        sf::Sprite *sprite;
    };
    
    Sprite s;
    std::vector<Sprite> sprites;
    sf::RenderWindow* window;
   
    struct Animacion{
        int id;
        sf::Vector2u imageCount;
        float switchTime;
        sf::IntRect uvRect;
        sf::Vector2u currentImage;
        float totalTime;
        sf::Texture* textura;
        sf::Sprite* sprite;
    };
    
    Animacion a;
    std::vector<Animacion> animaciones;
    int cont = 0;
    int cont2 = 0;
    
public:
    FachadaMotor2D() : IFachada(){};
    virtual ~FachadaMotor2D(){};
    void crearVentana(int width, int height, int frames, bool vsync);
    int crearAnimacion(std::string &url, float imageCountx, float imageCounty, float switchTime);
    void updateAnimacion(int row,float deltaTime);
    bool borrarAnimacion(int id);
    int crearSprite(std::string &url);
    bool borrarSprite(int id);
    void dibujar(int id, float positionx, float positiony, float scale);
    int crearAudio();
    bool borrarAudio();
    void play();
    int crearTexto();
    bool borrarTexto();
    void escribir();
};

#endif

