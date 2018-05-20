#include "Pausa.h"
#include "Game.h"
#include "InputManager.h"
#include "Menu.h"

Pausa* Pausa::pinstance=0;                     
Pausa* Pausa::Instance(){
    if(pinstance==0){
        pinstance=new Pausa;
    }
    return pinstance;
}
Pausa::Pausa(){
   }
void Pausa::update(){
    presionado = InputManager::Instance(1)->getInput()->getPresionado();
    if(presionado){
        coord = InputManager::Instance(1)->getInput()->getCoord();
        if((coord.x>300 && coord.x<539)&&(coord.y>150 && coord.y<250)){
            presionado=InputManager::Instance(1)->getInput()->setPresionado();
            Game::Instance()->cambiarApartida();
        }
        if((coord.x>300 && coord.x<539)&&(coord.y>310 && coord.y<410)){
            std::cout<<"settings"<<std::endl;
        }
        if((coord.x>300 && coord.x<539)&&(coord.y>470 && coord.y<570)){
            window->clear(sf::Color::Black);
            Menu::Instance()->inicializar();
            Game::Instance()->cambiarAmenu();
        }
    }
}
void Pausa::render(){
    std::cout<<"entramos en pausa render"<<std::endl;
               window->display();

}
void Pausa::inicializar(){
          std::cout<<"entramos en pausa"<<std::endl;
            texture=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/fondoMenu.jpg");
            RenderManager::Instance(1)->getMotor()->dibujar(texture,0,0,1,*Game::Instance()->getWindow());
           idspriteResume=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/BOTONRESUME.png");
           idspriteOpciones=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/BOTONSETTINGS.png");
           idspriteSalir=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/BOTONEXIT.png");
            height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 1);
           RenderManager::Instance(1)->getMotor()->dibujar(idspriteResume,width,height,1,*Game::Instance()->getWindow());
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 2);
           RenderManager::Instance(1)->getMotor()->dibujar(idspriteOpciones,width,height,1,*Game::Instance()->getWindow());
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 3);
           RenderManager::Instance(1)->getMotor()->dibujar(idspriteSalir,width,height,1,*Game::Instance()->getWindow());

          }
Pausa *ps1=Pausa::Instance();
Pausa *ps2=ps1->Instance();
Pausa &refps=*Pausa::Instance();