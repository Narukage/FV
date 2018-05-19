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
    isPlay=true;
    state=Menu::Instance();
    //Pasamos la ventana
    Menu::Instance()->setWindow(&window);

}

void Game::cleared(){
 
    RenderManager::Instance(1)->getMotor()->cerrarVentana(window);
}

void Game::run(){
    inicializar();
    state->inicializar();
      sf::Time timeStartUpdate = RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime();
        while(isPlay){
            InputManager::Instance(1)->getInput()->Eventos(isPlay, window);
           if(RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime().asMilliseconds()-timeStartUpdate.asMilliseconds()>kUpdateTimePS){
            state->update();
            state->updateIA();
            state->render();
            
            timeStartUpdate = RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime();
          }

        }
    
        cleared();
    }


void Game::cambiarApartida(){
        state=Partida::Instance();
}

Estado* Game::getState(){
    return state;
}