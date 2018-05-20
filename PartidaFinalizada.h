#include <iostream>
#include "Estado.h"
#include <SFML/Graphics.hpp>
#include "RenderManager.h"

#define MAX_NUMBER_OF_ITEMS 3

    class PartidaFinalizada : public Estado {
    public:
    static PartidaFinalizada* Instance();
    void update();
    void render();
    void inicializar();
protected:
    PartidaFinalizada();
    PartidaFinalizada(const PartidaFinalizada &);
    PartidaFinalizada &operator=(const PartidaFinalizada &);
private:
    int idspriteSalir;
    int texture;    
    sf::RenderWindow* window;  //Ventana del juego
    static PartidaFinalizada* pinstance;
    bool press;
    sf::Vector2i coordenada;
    float width=300;
    float height;
};   