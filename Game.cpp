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

Game::Game(): window(sf::VideoMode(800,600),"Ventana de SFML"){
}

Game *g1 = Game::Instance();
Game *g2 = g1->Instance();
Game &refg = * Game::Instance();

void Game::inicializar(){
    
    //No se si usar InputManager pasandole la ventana y creandola aqui o todo en RenderManager
    RenderManager::Instance(1)->getMotor()->crearVentana(60,false, window);
    Tablero::Instance();
    inv = new Invocacion();
    generalmuerto1=false;
    generalmuerto2=false;
    empate=false;
    isPlay=true;
}

void Game::update(){
    //Una vez este el StateManager hay que mover el update
    RenderManager::Instance(1)->getMotor()->crearClock();
    presionado = InputManager::Instance(1)->getInput()->getPresionado();
    if(presionado){
        coord = InputManager::Instance(1)->getInput()->getCoord();
        campo = InputManager::Instance(1)->getInput()->getCampo();
        mano = InputManager::Instance(1)->getInput()->getMano();
        if((coord.x>150 && coord.x<650)&&(coord.y>480 && coord.y<600)){
            std::cout<<"Entramos dentro del la mano"<<std::endl;
            inv=Tablero::Instance()->esCarta(mano.x,mano.y);
            if(inv!=NULL){
                std::cout<<"esCarta es distinto de null"<<std::endl;
                cartaseleccionada=true;
            }
        }
        
        else if(cartaseleccionada ){ //queremos invocar en tablero
            if((coord.x>100 && coord.x<700)&&(coord.y>80 && coord.y<475)){
              
                    if(Tablero::Instance()->addUnit(campo.x,campo.y,inv,1)){
                        
                        cartaseleccionada=false;
                        /* vector<Invocacion*>::iterator it3;
                        int i=0;*/

                    }
                
                else{
                    if(Tablero::Instance()->addUnit(campo.x,campo.y,inv,2)){
                        cartaseleccionada=false;
                         /*vector<Invocacion*>::iterator it3;
                        int i=0;*/

                    }
                }
            }
        }else{ //queremos mover unidad en tablero
            if(!Tablero::Instance()->isFree(campo.x,campo.y) && actuainvocacion==false){ //si la posicion que clickamos contiene una unidad
                actuainvocacion=true;
                Tablero::Instance()->Adyacentes(campo.x,campo.y);
                tieneadyacentes=true;
                posXinvocacion=campo.x;
                posYinvocacion=campo.y;
            } //unidad seleccionada, preparada para hacer alguna accion
            else if(actuainvocacion==true && Tablero::Instance()->isFree(campo.x,campo.y) && Tablero::Instance()->getAlcanzable(campo.x,campo.y)==1){
                Tablero::Instance()->moveToPos(posXinvocacion, posYinvocacion,campo.x,campo.y,Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion));
                Tablero::Instance()->setFree(campo.x,campo.y,false);
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                Tablero::Instance()->ReiniciarAdy();
            }//ataque
            else if(actuainvocacion==true && !Tablero::Instance()->isFree(campo.x,campo.y)&&Tablero::Instance()->getAlcanzable(campo.x,campo.y)==1){
                if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->esAliado(Tablero::Instance()->getPlayer()->JugadaEn(coord.x,coord.y)->getComandante())){
                    ganador=Tablero::Instance()->atackToPos(posXinvocacion,posYinvocacion,campo.x,campo.y);
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
    meToca = InputManager::Instance(1)->getInput()->getMeToca();
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
    Tablero::Instance()->drawLifeNumb(1,window);
    Tablero::Instance()->drawLife(2,window);
    Tablero::Instance()->drawLifeNumb(2,window);
    Tablero::Instance()->drawMana(1,window);
    Tablero::Instance()->drawManaNumb(1,window);
    Tablero::Instance()->drawManaRest(1,window);
    Tablero::Instance()->drawBarra(1,window);
    Tablero::Instance()->drawMana(2,window);
    Tablero::Instance()->drawManaNumb(2,window);
    Tablero::Instance()->drawManaRest(2,window);
    Tablero::Instance()->drawRetrato(1,window);
    Tablero::Instance()->drawRetrato(2,window); //same
    Tablero::Instance()->Mostrar_mano(window);
    window.display();
}

void Game::cleared(){
 
    RenderManager::Instance(1)->getMotor()->cerrarVentana(window);
}

void Game::run(){
    inicializar();
    
      sf::Time timeStartUpdate = RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime();
        while(isPlay){
            InputManager::Instance(1)->getInput()->Eventos(isPlay, window);
           if(RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime().asMilliseconds()-timeStartUpdate.asMilliseconds()>kUpdateTimePS){
            update();
            updateIA();
            render();
             /*state->update(); actualizan y renderizan dependiendo del estado en el que nos encontremos
            state->updateIA();  descomentar cuando menu esta acabado
            state->render();*/
            timeStartUpdate = RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime();
          }

        }
    
        cleared();
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