#include "Menu.h"
#include "Game.h"
#include "InputManager.h"

Menu* Menu::pinstance=0;                     
Menu* Menu::Instance(){
    if(pinstance==0){
        pinstance=new Menu;
    }
    return pinstance;
}
Menu::Menu(){
    
}

void Menu::update(){
        coordenada = InputManager::Instance(1)->getInput()->getCoord();
        if((coordenada.x>300 && coordenada.x<539)&&(coordenada.y>150 && coordenada.y<250)){
            std::cout<<"pos aqui estamos"<<std::endl;
            Game::Instance()->cambiarApartida();
        }
        if((coordenada.x>300 && coordenada.x<539)&&(coordenada.y>310 && coordenada.y<410)){
            std::cout<<"settings"<<std::endl;
        }
        if((coordenada.x>300 && coordenada.x<539)&&(coordenada.y>470 && coordenada.y<570)){
            InputManager::Instance(1)->apagar();
        }
    }
void Menu::render(){
    //window->clear(sf::Color::Black);
   
    window->display();
}
    void Menu::inicializar(){
    
         texture=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/fondoMenu.jpg");
    RenderManager::Instance(1)->getMotor()->dibujar(texture,0,0,1,*Game::Instance()->getWindow());
           idspriteEmpezar=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/BOTONSTART.png");
           idspriteOpciones=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/BOTONSETTINGS.png");
           idspriteSalir=RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/BOTONEXIT.png");
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 1);
           RenderManager::Instance(1)->getMotor()->dibujar(idspriteEmpezar,width,height,1,*Game::Instance()->getWindow());
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 2);
           RenderManager::Instance(1)->getMotor()->dibujar(idspriteOpciones,width,height,1,*Game::Instance()->getWindow());
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 3);
           RenderManager::Instance(1)->getMotor()->dibujar(idspriteSalir,width,height,1,*Game::Instance()->getWindow());
    }


Menu *m1=Menu::Instance();
Menu *m2=m1->Instance();
Menu &refm=*Menu::Instance();