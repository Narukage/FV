#include "Game.h"

Game::Game(): window(sf::VideoMode(800,600),"Summoners"){
   
}

Game::~Game(){
    
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
    invocacion = new Invocacion();
    tablero = new Tablero();
}

void Game::eventos(){
    
     while(window.pollEvent(evento)){
    
        switch(evento.type){

                    case sf::Event::KeyPressed:

                        if(evento.key.code==sf::Keyboard::Escape){
                            isPlay = false;
                        }
                        
                    case sf::Event::MouseButtonPressed:
                        if(evento.mouseButton.button==sf::Mouse::Left){
                            coord = sf::Mouse::getPosition(window);
                            presionado=true;
                            std::cout << coord.x << std::endl;
                            std::cout << coord.y << std::endl;
                        }
                }
    }
}

void Game::update(){
    if(presionado){
        tablero->addUnit(/*coord.x*/1,/*coord.y*/5,invocacion,1);
        presionado=false;
    }
}

void Game::render(){
    
    window.clear(sf::Color::Black);
    tablero->drawMap(window);
    window.display();
}

void Game::cleared(){
 
    window.close();
}

void Game::run(){
    
    inicializar();
    
        while(isPlay){
           eventos();
           update();
           render();
        }
    
        cleared();
    }