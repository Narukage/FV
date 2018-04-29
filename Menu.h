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
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    ///////////////////////////////
    // GETTERS Y SETTERS
    ///////////////////////////////
    void setWindow(sf::RenderWindow* w) { window = w;    };
    //sf::RenderWindow* getWindow()       { return window; };
protected:
    Menu();
    Menu(const Menu &);
    Menu &operator=(const Menu &);
private:
    static Menu* pinstance;
    sf::RenderWindow* window;  //Ventana del juego
    sf::Texture texture;
    sf::Sprite sprite;
    int selectedItemIndex=0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};   
    