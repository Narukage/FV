#include "Game.h"

Game::Game(): window(sf::VideoMode(800,600),"Summoners"){
   
}

Game::~Game(){
    
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
   //invocacion = new Invocacion();
    tablero = Tablero::Instance();
    tablero2 = tablero->Instance();
    Tablero& tableroref = * Tablero::Instance();
    /*player = new Player(1);
    player2 = new Player(2);*/
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
         /*Pseudocodiguito, segun llegueis con vuestra parte vais rellenando, paz y buen rollito
    //if(cartaseleccionada){ //si hemos seleccionado antes una carta //invocacion
        if(presionado && board[posx][posy].free){ //la posicion de inv. esta vacia
            board[posx][posy].addUnit; //añadir unidad
     *      presionado=false;
        }else //posicion ocupada
          presionado=false;  //no hace nada
        }
     }
     * if(!cartaseleccionada){ //si no he seleccionado una carta antes //movimiento
       if(presionado && tablero->isFree(coord.x,coord.y)){
           
       }
      }
    if(presionado && ){
        tablero->addUnit(coord.x,coord.y,invocacion,1);
        presionado=false;
    }*/
        presionado=false;
    }
}

void Game::render(){
    
    window.clear(sf::Color::Black);
    tablero->drawMap(window);
    tablero->drawLife(1,window);
    window.draw(tablero->drawLifeNumb(1));
    tablero->drawLife(2,window);
    window.draw(tablero->drawLifeNumb(2));
    tablero->drawMana(1,window);
    window.draw(tablero->drawManaNumb(1));
    window.draw(tablero->drawManaRest(1));
    window.draw(tablero->drawBarra(1));
    tablero->drawMana(2,window);
    window.draw(tablero->drawManaNumb(2));
    window.draw(tablero->drawManaRest(2));
    window.draw(tablero->drawBarra(2));
    tablero->drawRetrato(1,window);
    tablero->drawRetrato(2,window);
    tablero->Mostrar_mano(window);
 
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