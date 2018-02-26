#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.h"


class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;      
    bool isPlay = true;
    Tablero* tablero;
       
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