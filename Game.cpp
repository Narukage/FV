#include <valarray>

#include "Game.h"
#define kUpdateTimePS 1000/15

Game* Game::pinstance = 0;
    
Game* Game::Instance(){
    if(pinstance==0){
        pinstance = new Game;
    }
    return pinstance;
}

Game::Game()/*: window(sf::VideoMode(800,600),"Ventana de SFML")*/{
}

Game *p1 = Game::Instance();
Game *p2 = p1->Instance();
Game &ref = * Game::Instance();

void Game::inicializar(){
    
    RenderManager::Instance(1)->getMotor()->crearVentana(800,600,60,true);
    /*window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);*/
    Tablero::Instance();
    inv = new Invocacion();
    generalmuerto1=false;
    generalmuerto2=false;
    empate=false;
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
                        if(evento.key.code==sf::Keyboard::Space){
                          
                            nexTurn(turno);
                            cambioTurno(meToca);
                            Tablero::Instance()->setTurno(meToca);
                            cout<<"he entrado"<<meToca<<std::endl;
                             cout<<"he entrado"<<turno<<std::endl;
                             
                             if(meToca==true){
                                 Tablero::Instance()->getPlayer()->Robar();
                             }
                             /*if(meToca==false){
                                 srand(time(NULL));
                                 //preguntar naru tamaños
                                 int eX = rand()% 600 + 800;
                                 int eY = rand()% 100 + 500;
                                 //eX=1;
                                 eX = (eX-100)/50;
                                 eY = (eY-80)/50;
                                 
                                  
                                  if(tablero->addUnit(eX,eY,inv,2)){
                                  //cartaseleccionada=false;
                  vector<Invocacion*>::iterator it3;
                 //int i=0;
                     nexTurn(turno);
                            cambioTurno(meToca);
           
            }
                                  else {
                                     nexTurn(turno);
                            cambioTurno(meToca);
                                  }
                             }
                            }
                            else{
                            
                            }*/
                        
                        }

                    case sf::Event::MouseButtonPressed:
                        if(meToca==true){
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
}

void Game::update(){
    //while(!generalmuerto1 && !generalmuerto2 && !empate){
     // cout<<"entro update: "<<meToca<<endl;
    if(presionado /*&& meToca*/){
      
        if((coord.x>150 && coord.x<650)&&(coord.y>480 && coord.y<600)){
            std::cout<<"Entramos dentro del la mano"<<std::endl;
            inv=Tablero::Instance()->esCarta(manox,manoy);
            if(inv!=NULL){
                std::cout<<"esCarta es distinto de null"<<std::endl;
                cartaseleccionada=true;
            }
        }
        
        else if(cartaseleccionada ){ //queremos invocar en tablero
            if((coord.x>100 && coord.x<700)&&(coord.y>80 && coord.y<475)){
              
                    if(Tablero::Instance()->addUnit(campox,campoy,inv,1)){
                        
                        cartaseleccionada=false;
                        /* vector<Invocacion*>::iterator it3;
                        int i=0;*/

                    }
                
                else{
                    if(Tablero::Instance()->addUnit(campox,campoy,inv,2)){
                        cartaseleccionada=false;
                         /*vector<Invocacion*>::iterator it3;
                        int i=0;*/

                    }
                }
            }
        }else{ //queremos mover unidad en tablero
            if(!Tablero::Instance()->isFree(campox,campoy) && actuainvocacion==false){ //si la posicion que clickamos contiene una unidad
                actuainvocacion=true;
                Tablero::Instance()->Adyacentes(campox,campoy);
                tieneadyacentes=true;
                posXinvocacion=campox;
                posYinvocacion=campoy;
            } //unidad seleccionada, preparada para hacer alguna accion
            else if(actuainvocacion==true && Tablero::Instance()->isFree(campox,campoy) && Tablero::Instance()->getAlcanzable(campox,campoy)==1){
                Tablero::Instance()->moveToPos(posXinvocacion, posYinvocacion,campox,campoy,Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion));
                Tablero::Instance()->setFree(campox,campoy,false);
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                Tablero::Instance()->ReiniciarAdy();
            }//ataque
            else if(actuainvocacion==true && !Tablero::Instance()->isFree(campox,campoy)&&Tablero::Instance()->getAlcanzable(campox,campoy)==1){
                if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->esAliado(Tablero::Instance()->getPlayer()->JugadaEn(coord.x,coord.y)->getComandante())){
                    ganador=Tablero::Instance()->atackToPos(posXinvocacion,posYinvocacion,campox,campoy);
                       //tablero->setFree(campox,campoy,true);
                    if(ganador==-1){
                        generalmuerto1=true;
                    }
                    if(ganador==-2){
                        generalmuerto2=true;
                    }
                    if(ganador==-3){
                        empate=true;
                    }
                   
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                Tablero::Instance()->ReiniciarAdy();
                }
            }
            else{
               actuainvocacion=false;
               posXinvocacion=-1;
               posYinvocacion=-1;
               Tablero::Instance()->ReiniciarAdy();
               Tablero::Instance()->ReiniciarAdy();
            }
            
        }
        presionado=false;
    //}
    //finalizado();
    }
}
void Game:: updateIA(){
    if(meToca==false){
        inv=Tablero::Instance()->esCarta(0,0);
        if(inv!=NULL){
            
        }
    }
}

void Game::render(){
    
    window.clear(sf::Color::Black);
    Tablero::Instance()->drawMap(window);
    Tablero::Instance()->drawUnit(window);
    if(tieneadyacentes){
        Tablero::Instance()->drawAdyacentes(window);
    }
    Tablero::Instance()->drawLife(1,window);
    window.draw(Tablero::Instance()->drawLifeNumb(1));
    Tablero::Instance()->drawLife(2,window);
    window.draw(Tablero::Instance()->drawLifeNumb(2));
   // tablero->drawMana(1,window);
   // window.draw(tablero->drawManaNumb(1));
    //window.draw(tablero->drawManaRest(1));
    //window.draw(tablero->drawBarra(1));
    //tablero->drawMana(2,window);
    //window.draw(tablero->drawManaNumb(2));
   // window.draw(tablero->drawManaRest(2));
    //window.draw(tablero->drawBarra(2));
    Tablero::Instance()->drawRetrato(1,window); //esto solo deberia dibujarlo una vez
    Tablero::Instance()->drawRetrato(2,window); //same
    Tablero::Instance()->Mostrar_mano(window);
    window.display();
}

void Game::cleared(){
 
    window.close();
}

void Game::run(){
    
    inicializar();
    
      sf::Time timeStartUpdate = clock.getElapsedTime();
        while(isPlay){
           eventos();
           if(clock.getElapsedTime().asMilliseconds()-timeStartUpdate.asMilliseconds()>kUpdateTimePS){
            update();
            updateIA();
            render();
            timeStartUpdate = clock.getElapsedTime();
           }
        }
    
        cleared();
    }

void Game::nexTurn(int num){

    turno=num+1;
                        
}

void Game::finalizado(){
    if(generalmuerto1){
        std::cout << "Has perdido" << std::endl;
    }
    if(generalmuerto2){
        std::cout << "Has ganado" << std::endl;
    }
    if(empate){
        std::cout << "Empate" << std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        std::cout << "Nueva partida" << std::endl;
        //Reseteamos todo
        inicializar();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        isPlay=false;
    }
}