#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Estado.h"
#include "RenderManager.h"
#define MAX_NUMBER_OF_ITEMS 3

    class Pausa : public Estado {
    public:
    static Pausa* Instance();
    void update();
    void render();
    void inicializar();
    int GetPressedItem() { return selectedItemIndex; }
    void setWindow(sf::RenderWindow* w) { window = w;    };
protected:
    Pausa();
    Pausa(const Pausa &);
    Pausa &operator=(const Pausa &);
private:
    sf::RenderWindow* window=Game::Instance()->getWindow();  //Ventana del juego
    bool presionado;
    sf::Vector2i coord;
    static Pausa* pinstance;
    int texture;
    sf::Sprite sprite;
    float width=300;
    float height;
    int idspriteResume;
    int idspriteOpciones;
    int idspriteSalir;
    int selectedItemIndex=0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};   