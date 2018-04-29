#include "Partida.h"
#include "Pausa.h"
#include "Game.h"

Partida* Partida::pinstance=0;                     
Partida* Partida::Instance(){
    if(pinstance==0){
        pinstance=new Partida;
    }
    return pinstance;
}
Partida::Partida(){
    
}

void Partida::update(){
    std::cout<<"lololo"<<std::endl;
    if(InputManager::Instance(1)->PulsaEscape()){
            Game::Instance()->cambiarApausa();
    }
}
Partida *pt1=Partida::Instance();
Partida *pt2=pt1->Instance();
Partida &refpt=*Partida::Instance();
