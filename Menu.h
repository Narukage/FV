#include <iostream>
#include <SFML/Graphics.hpp>
#include "Estado.h"
#include "RenderManager.h"
#define MAX_NUMBER_OF_ITEMS 3
    class Menu : public Estado {
    
    private:
    static Menu* pinstance;
    sf::RenderWindow* window;  //Ventana del juego
    sf::Texture texture;
    sf::Sprite sprite;
    float width=400;
    float height;
    int idspriteEmpezar;
    int idspriteOpciones;
    int idspriteSalir;
    int selectedItemIndex=0;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];    
        
    protected:
        ///////////////////////////////
       // CONSTRUCTORES Y DESTRUCTORES
       ///////////////////////////////
       Menu();
       Menu(const Menu &);
       Menu &operator=(const Menu &);
    
    public:
        ///////////////////////////////
       // FUNCIONES PRINCIPALES
       ///////////////////////////////
        static Menu* Instance();
        void update();
        void render();
        void inicializar();
        void MoveUp();
        void MoveDown();
    
        ///////////////////////////////
       // GETTERS Y SETTERS
       ///////////////////////////////
        int GetPressedItem() { return selectedItemIndex; }
        void setWindow(sf::RenderWindow* w) { window = w;    };
};   
    