#include <iostream>
#include "Estado.h"
#include "Game.h"
    class Partida : public Estado {
    public:
    static Partida* Instance();
    void update();
    void updateIA();
    void render();
    void finalizado();
    void cambiarApausa();
    void setWindow(sf::RenderWindow* w) { window = w;    };
    bool getSeleccionada()      { return cartaseleccionada; };

protected:
    Partida();
    Partida(const Partida &);
    Partida &operator=(const Partida &);
private:
    sf::RenderWindow* window=Game::Instance()->getWindow();  //Ventana del juego
    static Partida* pinstance;
    bool generalmuerto1=false;
    bool generalmuerto2=false;
    Invocacion* inv;
    bool empate=false;
    int id = -1;
    bool presionado;
    bool meToca = true;
    sf::Vector2i coord;
    sf::Vector2i campo;
    sf::Vector2i mano;
    bool cartaseleccionada = false;
    bool actuainvocacion =false;
    bool IaCartas=false;
    bool IaMover=false;
    bool IaMoverU=false;
    
    int posXinvocacion=-1;
    int posYinvocacion=-1;

    int ganador;
   
    bool tieneadyacentes=false;
       
};   