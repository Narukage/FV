#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;

class Interface{
    private:
        sf::Texture textura;
        sf::Texture textura2;
        sf::Sprite sprite;
        sf::Sprite sprite2;
        sf::CircleShape coco;
        sf::Text texto;
        sf::Font font;
        
    public:
        Interface();
        ~Interface();
       void drawLife(int life, int commander, sf::RenderWindow& window);
       void drawMana(float mana, int commander, sf::RenderWindow& window);
};