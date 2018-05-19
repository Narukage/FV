#include <iostream>
#include <SFML/Graphics.hpp>
#include "Estado.h"
#include "RenderManager.h"
#define MAX_NUMBER_OF_ITEMS 3
    class Menu : public Estado {
    public:
    static Menu* Instance();
    void update();
    void render();
    void inicializar();
    int GetPressedItem() { return selectedItemIndex; }
    void setWindow(sf::RenderWindow* w) { window = w;    };

    ///////////////////////////////
    // GETTERS Y SETTERS
    ///////////////////////////////
protected:
    Menu();
    Menu(const Menu &);
    Menu &operator=(const Menu &);
private:
    static Menu* pinstance;
    sf::RenderWindow* window;  //Ventana del juego
    int texture;
    sf::Sprite sprite;
    float width=300;
    float height;
    bool presionado;
    sf::Vector2i coord;
    int idspriteEmpezar;
    int idspriteOpciones;
    int idspriteSalir;
    int selectedItemIndex=0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};   
    