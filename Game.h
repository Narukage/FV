#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;      
    bool isPlay = true;
       
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