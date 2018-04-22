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

Game::Game(){
}

Game *g1 = Game::Instance();
Game *g2 = g1->Instance();
Game &refg = * Game::Instance();

void Game::inicializar(){
    RenderManager::Instance(1)->getMotor()->crearVentana(800,600,60,true);
    Tablero::Instance();
    inv = new Invocacion();
    generalmuerto1=false;
    generalmuerto2=false;
    empate=false;
    isPlay=true;
}

void Game::eventos(){  
    RenderManager::Instance(1)->getInput()->Eventos(isPlay);
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