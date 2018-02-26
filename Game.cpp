#include "Game.h"

Game::Game(): window(sf::VideoMode(800,600),"Summoners"){
   
}

Game::~Game(){
    
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
    tablero = new Tablero();

}

void Game::eventos(){
    
     while(window.pollEvent(evento)){
    
        switch(evento.type){

                    case sf::Event::KeyPressed:

                        if(evento.key.code==sf::Keyboard::Escape){
                            isPlay = false;
                        }
                }
    }
}

void Game::update(){
    
}

void Game::render(){
    
    window.clear(sf::Color::Black);
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