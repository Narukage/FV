#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.h"
#include "Player.h"
#include "Interface.h"



class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;      
    bool isPlay = true;
    Tablero* tablero;
    Tablero* tablero2;
    Invocacion* invocacion;
    Player* player;
    Player* player2;
            
    Interface* interface;
    sf::Vector2i coord;
    bool presionado = false;
    bool cartaseleccionada = false;
    Invocacion* inv;
       
private:
    void inicializar();
    void eventos();
    void update();
    void render();
    void cleared();
    
public:
    Game();
    ~Game();
    void run();
};