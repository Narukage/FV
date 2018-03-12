#include "Interface.h"

Interface::Interface(){
    
}

Interface::~Interface(){
    
}

void Interface::drawLife(int life, int commander, sf::RenderWindow& window){
    if(commander==1){
        if(!textura.loadFromFile("/home/delegacioneps/Summoners/assets/HUD/vida.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        if(!textura2.loadFromFile("/home/delegacioneps/Summoners/assets/HUD/life.png")){
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
        if(!textura.loadFromFile("/home/delegacioneps/Summoners/assets/HUD/vida.png")){
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

sf::Text Interface::drawLifeNumb(int life, int commander){
    if(commander==1){
        if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
                std::cout << "Fuente no aplicada" <<std::endl;
            }

            std::stringstream ss;
            ss << life;
            vida.setString(ss.str().c_str());
            vida.setColor(sf::Color::White);
            vida.setFont(font);
            vida.setScale(0.7,0.7);
            vida.setPosition(350,1);
            return vida;
    }else{
        if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
                std::cout << "Fuente no aplicada" <<std::endl;
            }

            std::stringstream ss;
            ss << life;
            vida.setString(ss.str().c_str());
            vida.setColor(sf::Color::White);
            vida.setFont(font);
            vida.setScale(0.7,0.7);
            vida.setPosition(412,1);
            return vida;
    }
}

sf::Text Interface::drawManaNumb(float mana, int commander){
    if(commander==1){
        if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
                std::cout << "Fuente no aplicada" <<std::endl;
            }

            std::stringstream ss;
            ss << mana;
            mananumb.setString(ss.str().c_str());
            mananumb.setColor(sf::Color::White);
            mananumb.setFont(font);
            mananumb.setScale(0.8,0.8);
            mananumb.setPosition(193,37);
            return mananumb;
    }else{
        if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
                std::cout << "Fuente no aplicada" <<std::endl;
            }

            std::stringstream ss;
            ss << mana;
            mananumb.setString(ss.str().c_str());
            mananumb.setColor(sf::Color::White);
            mananumb.setFont(font);
            mananumb.setPosition(620,37);
            return mananumb;
    }
}

sf::Text Interface::drawManaRest(float manarest, int commander){
    if(commander==1){
        if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
                    std::cout << "Fuente no aplicada" <<std::endl;
                }

                std::stringstream ss;
                ss << manarest;
                manar.setString(ss.str().c_str());
                manar.setColor(sf::Color::White);
                manar.setFont(font);
                manar.setScale(0.8,0.8);
                manar.setPosition(158,37);
                return manar;
    }else{
        if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
                    std::cout << "Fuente no aplicada" <<std::endl;
                }

                std::stringstream ss;
                ss << manarest;
                manar.setString(ss.str().c_str());
                manar.setColor(sf::Color::White);
                manar.setFont(font);
                manar.setPosition(585,37);
                return manar;
    }
}

sf::Text Interface::drawBarra(int commander){
    if(commander==1){
        if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
                        std::cout << "Fuente no aplicada" <<std::endl;
                    }
       barra.setFont(font);
       barra.setPosition(182,37);
       barra.setScale(0.8,0.8);
       barra.setString("/");
       return barra;
    }else{
        if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
                        std::cout << "Fuente no aplicada" <<std::endl;
                    }
       barra.setFont(font);
       barra.setPosition(609,37);
       barra.setString("/");
       return barra;
    }
}

void Interface::drawMana(float mana, int commander, sf::RenderWindow& window){
    if(commander==1){
        coco.setFillColor(sf::Color::Blue);
        coco.setRadius(mana*2);
        coco.setPosition(110,37);
       
        window.draw(coco);
    }else{
        coco.setFillColor(sf::Color::Blue);
        coco.setRadius(mana*2);
        coco.setPosition(655,37);

        window.draw(coco);
    }
}
