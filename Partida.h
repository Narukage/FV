#include <iostream>
#include "Estado.h"
#include "Game.h"
    class Partida : public Estado {
    public:
    static Partida* Instance();
    void update();
    void cambiarApausa();
    void inicializar();
    void setWindow(sf::RenderWindow* w) { window = w;    };
    bool getSeleccionada()      { return cartaseleccionada; };
protected:
    Partida();
    Partida(const Partida &);
    Partida &operator=(const Partida &);
private:
    bool IaCartas=false;
    bool IaMover=false;
    int ganador;
    int posXinvocacion=-1;
    int posYinvocacion=-1;
    bool tieneadyacentes=false;
    bool actuainvocacion =false;
    bool presionado;
    bool meToca = true;
    sf::Vector2i coord;
    sf::Vector2i campo;
    sf::Vector2i mano;
    Invocacion* inv;
    bool cartaseleccionada = false;   
    int id = -1;
    sf::RenderWindow* window=Game::Instance()->getWindow();  //Ventana del juego
    static Partida* pinstance;
    bool empate=false;
    bool generalmuerto1=false;
    bool generalmuerto2=false;
    void updateIA();
    void render();
    void finalizado();
};   