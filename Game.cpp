#include "Game.h"

Game::Game(): window(sf::VideoMode(800,600),"Summoners"){
   
}

Game::~Game(){
    
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
   //invocacion = new Invocacion();
    tablero = new Tablero();
    player = new Player(1);
    player2 = new Player(2);
    interface = new Interface();
}

void Game::eventos(){
    
     while(window.pollEvent(evento)){
               if(evento.type==sf::Event::Closed){
                            isPlay = false;
                  }   
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
        tablero->addUnit(coord.x,coord.y,invocacion,1);
        presionado=false;
    }
}

void Game::render(){
    
    window.clear(sf::Color::Black);
    tablero->drawMap(window);
    window.draw(player->getRetrato());
    window.draw(player2->getRetrato());
    interface->drawLife(player->getLife(),1,window);
    interface->drawLife(player2->getLife(),2,window);
    window.draw(interface->drawLifeNumb(player->getLife(),1));
    window.draw(interface->drawLifeNumb(player2->getLife(),2));
    interface->drawMana(player->getMana(),1,window);
    interface->drawMana(player2->getMana(),2,window);
    window.draw(interface->drawManaRest(player->getManaRest(),1));
    window.draw(interface->drawManaRest(player2->getManaRest(),2));
    window.draw(interface->drawBarra(1));
    window.draw(interface->drawBarra(2));
    window.draw(interface->drawManaNumb(player->getMana(),1));
    window.draw(interface->drawManaNumb(player2->getMana(),2));
    player->Mostrar_mano(window);
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