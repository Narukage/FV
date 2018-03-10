#include "Interface.h"

Interface::Interface(){
    
}

Interface::~Interface(){
    
}

void Interface::drawLife(int life, int commander, sf::RenderWindow& window){
    if(commander==1){
        if(!textura.loadFromFile("/home/naru/Escritorio/vida.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        if(!textura2.loadFromFile("/home/naru/Escritorio/life.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        sprite.setTexture(textura);
        sprite2.setTexture(textura2);
        sprite2.setPosition(100,5);
        sprite2.setScale(0.5,0.5);
        window.draw(sprite2);
        
        for(int i=0;i<life;i++){
            sprite.setPosition((i*2)+135,10);
            sprite.setScale(2,2);
            window.draw(sprite);
        }
    }else{
        if(!textura.loadFromFile("/home/naru/Escritorio/vida.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        sprite.setTexture(textura);
        sprite2.setTexture(textura2);
        sprite2.setPosition(670,5);
        sprite2.setScale(0.5,0.5);
        window.draw(sprite2);
        
        for(int i=0;i<life;i++){
            sprite.setPosition((i*2)+455,10);
            window.draw(sprite);
        }
    }
}

void Interface::drawMana(float mana, int commander, sf::RenderWindow& window){
    if(commander==1){
        coco.setFillColor(sf::Color::Blue);
        coco.setRadius(mana*2);
        coco.setPosition(110,37);
        
    if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
        std::cout << "Fuente no aplicada" <<std::endl;
    }
   
        std::stringstream ss;
        ss << mana;
        texto.setString(ss.str().c_str());
        texto.setColor(sf::Color::White);
        texto.setFont(font);
        texto.setPosition(110,37);
        
        window.draw(coco);
        window.draw(texto);
    }else{
        coco.setFillColor(sf::Color::Blue);
        coco.setRadius(mana*2);
        coco.setPosition(655,37);
        
        std::stringstream ss;
        ss << mana;
        texto.setString(ss.str().c_str());
        texto.setColor(sf::Color::White);
        texto.setFont(font);
        texto.setPosition(655,37);
        
        window.draw(coco);
        window.draw(texto);
    }
}
