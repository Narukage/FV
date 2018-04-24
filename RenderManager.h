#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H
#include "IFachada.h"

//SINGLETON

class RenderManager {
private:
    IFachada* motor;
    static RenderManager* pinstance;
    
public:
    static RenderManager* Instance(int libreria);
    IFachada* getMotor(){ return motor; };
    ~RenderManager();
    
protected:
    RenderManager(int libreria);
    RenderManager(const RenderManager& orig);

};

class FachadaMotor2D : public IFachada {
private:
    sf::Clock clock;
    
    struct Sprite{
        int id;
        sf::Texture textura;
        sf::Sprite *sprite;
    };
        
    std::vector<Sprite> sprites;
   
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
    int cont3 = 0;
    int cont4 = 0;
    
    struct Audio{
        int id;
        sf::SoundBuffer buffer;
        sf::Sound* sound;
    };
    
    Audio m;
    std::vector<Audio> sonidos;
    
    struct Texto{
        int id;
        sf::Font font;
        sf::Text* text;
    };
    
    Texto t;
    std::vector<Texto> textos;
    
public:
    FachadaMotor2D() : IFachada(){};
    virtual ~FachadaMotor2D(){};
    void crearVentana(int frames, bool vsync, sf::RenderWindow& window);
    void cerrarVentana(sf::RenderWindow& window);
    void crearClock();
    int crearAnimacion(std::string url, float imageCountx, float imageCounty, float switchTime);
    void updateAnimacion(int row,float deltaTime);
    bool borrarAnimacion(int id);
    int crearSprite(std::string url);
    bool borrarSprite(int id);
    void dibujar(int id, float positionx, float positiony, float scale, sf::RenderWindow& window);
    int crearAudio(std::string url, int volumen);
    bool borrarAudio(int id);
    void play(int id);
    int crearTexto(std::string url);
    bool borrarTexto(int id);
    void escribir(std::string s, int id, float positionx, float positiony, float scale, sf::RenderWindow& window);
    sf::Clock getClock(){ return clock; };
    
};

#endif /* RENDERMANAGER_H */

