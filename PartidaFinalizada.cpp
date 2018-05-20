#include "PartidaFinalizada.h"
#include "InputManager.h"
#include "Game.h"
#include "Partida.h"


PartidaFinalizada* PartidaFinalizada::pinstance=0;                     
PartidaFinalizada* PartidaFinalizada::Instance(){
    if(pinstance==0){
        pinstance=new PartidaFinalizada;
    }
    return pinstance;
}
PartidaFinalizada::PartidaFinalizada(){
    
}
void PartidaFinalizada::update(){
    press=InputManager::Instance(1)->getInput()->getPresionado();
        coordenada = InputManager::Instance(1)->getInput()->getCoord();
        
        if(press==true && ((coordenada.x>300 && coordenada.x<539)&&(coordenada.y>470 && coordenada.y<570))){
            press=false;
            Game::Instance()->cambiarAmenu();
        }
    }
void PartidaFinalizada::render(){
    //window->clear(sf::Color::Black);
       RenderManager::Instance(1)->getMotor()->dibujar(texture,0,0,1,*Game::Instance()->getWindow());
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 3);
           RenderManager::Instance(1)->getMotor()->dibujar(idspriteSalir,width,height,1,*Game::Instance()->getWindow());
   
    window->display();
}
    void PartidaFinalizada::inicializar(){
        if(Partida::Instance()->getAcab()==-1){ 
        texture=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/fondoDerrota.jpg");
        }
        if(Partida::Instance()->getAcab()==-2){ 
        texture=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/fondoVictoria.jpg");
        }
        idspriteSalir=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/BOTONEXIT.png");
 }
PartidaFinalizada *pf1=PartidaFinalizada::Instance();
PartidaFinalizada *pf2=pf1->Instance();
PartidaFinalizada &refpf=*PartidaFinalizada::Instance();