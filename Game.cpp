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
                            std::cout << coord.x << std::endl;
                            std::cout << coord.y << std::endl;
                            int posx = (coord.x-100)/50;
                            int posy = (coord.y-80)/50;
                            std::cout << "posx: " << posx << std::endl;
                            std::cout << "posy: " << posy << std::endl;
                        }
                }
    }
}

void Game::update(){
    
    if(presionado){
        if(tablero->esCarta(coord.x,coord.y)!=NULL){
            inv=tablero->esCarta(coord.x,coord.y);
            std::cout << "SOY UN MONSTRUO CON VIDA : " << inv->getVida()<< std::endl;
         
            std::cout << "SOY UN MONSTRUO CON VIDA : " << inv->getVida()<< std::endl;
            std::cout << "AY QUE ES UNA CARTA" << std::endl;
            cartaseleccionada=true;
        }
        
        else if(cartaseleccionada ){ //queremos invocar en tablero
            if(tablero->addUnit(coord.x,coord.y,inv,1)){
                cartaseleccionada=false;
                for(int i=0;i<20;i++){
                    //*if(tablero->getPlayer()->getJugadas()[i].getX()>=0){
                    std::cout << "Soy el monstruo de jugadas: " << tablero->getPlayer()->getJugadas()[i].getNombre()<<"en la posicion de array: "<< i<<std::endl;
                    std::cout << "En tablero X =  " << tablero->getPlayer()->getJugadas()[i].getX()<<"en tablero Y = "<<tablero->getPlayer()->getJugadas()[i].getY()<< std::endl;
                    //}
                }  
            }
        }else{ //queremos mover unidad en tablero
            if(!tablero->isFree(coord.x,coord.y) && actuainvocacion==false){ //si la posicion que clickamos contiene una unidad
                std::cout << "Invocacionnnn" << std::endl;
                actuainvocacion=true;
                tablero->Adyacentes(coord.x,coord.y);
                posXinvocacion=coord.x;
                posYinvocacion=coord.y;
                std::cout << "posXinvocacion: " << posXinvocacion << std::endl;
                std::cout << "posYinvocacion: " << posYinvocacion << std::endl;
                std::cout << "pero que " << std::endl;
            } //unidad seleccionada, preparada para hacer alguna accion
            else if(actuainvocacion==true && tablero->isFree(coord.x,coord.y) && tablero->getAlcanzable(coord.x,coord.y)==1){
                /*for(int i=0;i<20;i++){
                    std::cout << "Soy el mosntruo de jugadas: " << tablero->getPlayer()->getJugadas()[i].getNombre()<<"en la posicion de array: "<< std::endl;
                    std::cout << "En tablero X =  " << tablero->getPlayer()->getJugadas()[i].getX()<<"en tablero Y = "<<tablero->getPlayer()->getJugadas()[i].getY()<< std::endl;
                }   */
             std::cout << "SOY UN MONSTRUO que se va a mover soy: ... : " << tablero->getUnit(posXinvocacion,posYinvocacion)->getNombre()<<"y estoy ya en : "<<tablero->getUnit(posXinvocacion,posYinvocacion)->getX()<< std::endl;
                tablero->moveToPos(posXinvocacion, posYinvocacion,coord.x,coord.y,tablero->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion));
                tablero->setFree(coord.x,coord.y,false); 
                
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                tablero->ReiniciarAdy();
            }//ataque
            else if(actuainvocacion==true && !tablero->isFree(coord.x,coord.y)&&tablero->getAlcanzable(coord.x,coord.y)==1){
                if(tablero->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->esAliado(tablero->getUnit(coord.x,coord.y)->getComandante())){
                    
                    std::cout<<"AL ATAKERRRRR CANDEMOR"<<std::endl;
                   if( tablero->atackToPos(posXinvocacion,posYinvocacion,coord.x,coord.y)){
                       tablero->setFree(coord.x,coord.y,true);
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
    tablero->drawRetrato(1,window); //esto solo deberia dibujarlo una vez
    tablero->drawRetrato(2,window); //same
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