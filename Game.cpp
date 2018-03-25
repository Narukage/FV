#include <valarray>

#include "Game.h"

Game::Game(): window(sf::VideoMode(800,600),"Summoners"){
   
}

Game::~Game(){
    
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
   //invocacion = new Invocacion();
  /*  tablero = Tablero();
    tablero2 = Tablero();*/
    tablero = Tablero::Instance();
    tablero2 = tablero->Instance();
    Tablero& tableroref = * Tablero::Instance();
    /*player = new Player(1);
    player2 = new Player(2);*/
    interface = new Interface();
    inv = new Invocacion();
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
                            
                            std::cout << "coordx: " << coord.x << std::endl;
                            std::cout << "coordy: " << coord.y << std::endl;
                                          
                            manox = (coord.x-150)/100;
                            manoy = (coord.y-480)/146;
                            
                            campox = (coord.x-100)/50;
                            campoy = (coord.y-80)/50;
                        
                        }
                }
    }
}

void Game::update(){
    
    if(presionado){
        if((coord.x>150 && coord.x<650)&&(coord.y>480 && coord.y<600)){
            std::cout<<"Entramos dentro del la mano"<<std::endl;
            inv=tablero->esCarta(manox,manoy);
            if(inv!=NULL){
                std::cout<<"esCarta es distinto de null"<<std::endl;
                cartaseleccionada=true;
            }
        }
        
        else if(cartaseleccionada ){ //queremos invocar en tablero
            if((coord.x>100 && coord.x<700)&&(coord.y>80 && coord.y<475)){
                if(tablero->addUnit(campox,campoy,inv,1)){
                    cartaseleccionada=false;
                      vector<Invocacion*>::iterator it3;
                     int i=0;

                }
            }
        }else{ //queremos mover unidad en tablero
            if(!tablero->isFree(campox,campoy) && actuainvocacion==false){ //si la posicion que clickamos contiene una unidad
                actuainvocacion=true;
                tablero->Adyacentes(campox,campoy);
                posXinvocacion=campox;
                posYinvocacion=campoy;
            } //unidad seleccionada, preparada para hacer alguna accion
            else if(actuainvocacion==true && tablero->isFree(campox,campoy) && tablero->getAlcanzable(campox,campoy)==1){
              
                tablero->moveToPos(posXinvocacion, posYinvocacion,campox,campoy,tablero->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion));
                tablero->setFree(campox,campoy,false);             
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                tablero->ReiniciarAdy();
            }//ataque
            else if(actuainvocacion==true && !tablero->isFree(campox,campoy)&&tablero->getAlcanzable(campox,campoy)==1){
                if(tablero->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->esAliado(tablero->getPlayer()->JugadaEn(coord.x,coord.y)->getComandante())){
                    
                   if( tablero->atackToPos(posXinvocacion,posYinvocacion,campox,campoy)){
                       tablero->setFree(campox,campoy,true);
                   }
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                tablero->ReiniciarAdy();
                }
            }
            else{
               actuainvocacion=false;
               posXinvocacion=-1;
               posYinvocacion=-1;
               tablero->ReiniciarAdy();
               tablero->ReiniciarAdy();
            }
            
        }
        presionado=false;
    }
}

void Game::render(){
    
    window.clear(sf::Color::Black);
    tablero->drawMap(window);
    tablero->drawUnit(window);
    tablero->drawAdyacentes(window);
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

/*void Game::nexTurn(int num){

    turno=num+1;
                        
}*/