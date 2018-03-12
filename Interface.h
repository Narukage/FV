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
        sf::Text vida;
        sf::Text mananumb;
        sf::Text manar;
        sf::Text barra;
        sf::Font font;
        
    public:
        Interface();
        ~Interface();
       void drawLife(int life, int commander, sf::RenderWindow& window);
       void drawMana(float mana, int commander, sf::RenderWindow& window);
       sf::Text drawManaNumb(float mana, int commander);
       sf::Text drawLifeNumb(int life, int commander);
       sf::Text drawManaRest(float manarest, int commander);
       sf::Text drawBarra(int commander);
};