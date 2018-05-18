#include <valarray>
#include "Game.h"
#include "Menu.h"
#include "Partida.h"
#include "Pausa.h"
#define kUpdateTimePS 1000/15


Game* Game::pinstance = 0;
    
Game* Game::Instance(){
    if(pinstance==0){
        pinstance = new Game;
    }
    return pinstance;
}

Game::Game(): window(sf::VideoMode(800,600),"Summoners"){
}

Game *g1 = Game::Instance();
Game *g2 = g1->Instance();
Game &refg = * Game::Instance();

void Game::inicializar(){
    
    //No se si usar InputManager pasandole la ventana y creandola aqui o todo en RenderManager
    RenderManager::Instance(1)->getMotor()->crearVentana(60,false, window);
    inv = new Invocacion();
    generalmuerto1=false;
    generalmuerto2=false;
    empate=false;
    isPlay=true;
    Tablero::Instance()->cargarMapa();
    //state=Game::Instance();
    //Pasamos la ventana
    Tablero::Instance()->setWindow(&window);
    Menu::Instance()->setWindow(&window);

}

void Game::update(){
    //Una vez este el StateManager hay que mover el update
    id = -1;
    RenderManager::Instance(1)->getMotor()->crearClock();
    presionado = InputManager::Instance(1)->getInput()->getPresionado();
    if(presionado && meToca){
        coord = InputManager::Instance(1)->getInput()->getCoord();
        campo = InputManager::Instance(1)->getInput()->getCampo();
        mano = InputManager::Instance(1)->getInput()->getMano();
        if((coord.x>150 && coord.x<650)&&(coord.y>480 && coord.y<600)){
            //aqu� controlar mano
           
            std::cout<<"Entramos dentro del la mano"<<std::endl;
            inv=Tablero::Instance()->esCarta(mano.x,mano.y);
            
            if(inv!=NULL){
                std::cout<<"esCarta es distinto de null"<<std::endl;
                id = inv->getIdCartaSel();
                cartaseleccionada=true;
                 
            }
        }
        
        else if(cartaseleccionada ){ //queremos invocar en tablero
            cartaseleccionada=false;
            if((coord.x>100 && coord.x<700)&&(coord.y>80 && coord.y<475)){
              
                    if(Tablero::Instance()->addUnit(campo.x,campo.y,inv,1)){
                        
                        cartaseleccionada=false;
                        /* vector<Invocacion*>::iterator it3;
                        int i=0;*/

                    }
                
                /*else{
                    if(Tablero::Instance()->addUnit(campo.x,campo.y,inv,2)){
                        cartaseleccionada=false;
                         vector<Invocacion*>::iterator it3;
                        int i=0;

                    }
                }*/
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
                if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->getMovimiento()>0){
                Tablero::Instance()->moveToPos(posXinvocacion, posYinvocacion,campo.x,campo.y,Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion));
                Tablero::Instance()->setFree(campo.x,campo.y,false);
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                cout << "me reinicio" << endl;
                
                Tablero::Instance()->ReiniciarAdy();
                }
                else{
                //Tablero::Instance()->setClick(0);
                }
            }//ataque
            else if(actuainvocacion==true && !Tablero::Instance()->isFree(campo.x,campo.y)&&Tablero::Instance()->getAlcanzable(campo.x,campo.y)==1){
                if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->getMovimiento()>0){
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
                cout << "me reinicio2" << endl;
                 if(Tablero::Instance()->getClick()==0)
                Tablero::Instance()->ReiniciarAdy();
                }
                }
            }
            else{
               actuainvocacion=false;
               posXinvocacion=-1;
               posYinvocacion=-1;
               //cout << "me reinicio3" << endl;
                if(Tablero::Instance()->getClick()==0)
               Tablero::Instance()->ReiniciarAdy();
            }
            
        }
        presionado=false;
    //}
    //finalizado();
    }
    if(!meToca){
        
        IaCartas=Tablero::Instance()->addUnitIA();
        IaMover=Tablero::Instance()->moveToPosIA();
        cout<<"salgo bien "<<endl;
        if(IaCartas==true && IaMover==true){
            cout<<"fallo en el cambio de turno "<<endl;
            InputManager::Instance(1)->getInput()->turnoIA(true);
            cout<<"fallo en el cambio de turno pero soy: "<<meToca<<endl;
            
        }
        /*int randomx;
       srand (time(NULL));
                    randomx= rand() % 3 +9;
                    cout<<"random "<<randomx<<endl;*/
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
    
    Tablero::Instance()->drawMap();
    Tablero::Instance()->drawUnit();
    Tablero::Instance()->drawLife(1);
    Tablero::Instance()->drawLifeNumb(1);
    Tablero::Instance()->drawLife(2);
    Tablero::Instance()->drawLifeNumb(2);
    Tablero::Instance()->drawMana(1);
    Tablero::Instance()->drawManaNumb(1);
    Tablero::Instance()->drawManaRest(1);
    Tablero::Instance()->drawBarra(1);
    Tablero::Instance()->drawMana(2);
    Tablero::Instance()->drawManaNumb(2);
    Tablero::Instance()->drawManaRest(2);
    Tablero::Instance()->drawRetrato(1);
    Tablero::Instance()->drawRetrato(2); //same
    Tablero::Instance()->Mostrar_mano(id);

    if(cartaseleccionada){
        cout << "animo carta" << endl;
        RenderManager::Instance(1)->getMotor()->updateAnimacion(id,0,0.1f);
        RenderManager::Instance(1)->getMotor()->dibujarAnimacion(id,inv->getJugar()*100+110,450,1,&window);
    }
           
    window.display();
}

void Game::cleared(){
 
    RenderManager::Instance(1)->getMotor()->cerrarVentana(window);
}

void Game::run(){
    inicializar();
    //state->inicializar();
      sf::Time timeStartUpdate = RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime();
        while(isPlay){
            InputManager::Instance(1)->getInput()->Eventos(isPlay, window);
           if(RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime().asMilliseconds()-timeStartUpdate.asMilliseconds()>kUpdateTimePS){
            /*state->*/update();
            /*state->*/updateIA();
            /*state->*/render();
            
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
void Game::cambiarApartida(){
    
        //state=Partida::Instance();
}
void Game::cambiarApausa(){
        //state=Pausa::Instance();
}
