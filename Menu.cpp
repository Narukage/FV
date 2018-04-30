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

    if(InputManager::Instance(1)->PulsaTecla()==2){
        Menu::MoveUp();
    }
    if(InputManager::Instance(1)->PulsaTecla()==3){
        Menu::MoveDown();
    }
    std::cout<<selectedItemIndex<<std::endl;
    if(InputManager::Instance(1)->PulsaTecla()==1 && selectedItemIndex==0){
            Game::Instance()->cambiarApartida();
    }
}

  void Menu::inicializar(){
           idspriteEmpezar=RenderManager::Instance(1)->getMotor()->crearTexto("Fonts/FreeMono.ttf");
           idspriteOpciones=RenderManager::Instance(1)->getMotor()->crearTexto("Fonts/FreeMono.ttf");
           idspriteSalir=RenderManager::Instance(1)->getMotor()->crearTexto("Fonts/FreeMono.ttf");
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 1);
           RenderManager::Instance(1)->getMotor()->escribir("Empezar",idspriteEmpezar,width,height,1,*window);
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 2);
           RenderManager::Instance(1)->getMotor()->escribir("Opciones",idspriteOpciones,width,height,1,*window);
           height=(600/(MAX_NUMBER_OF_ITEMS + 1) * 3);
           RenderManager::Instance(1)->getMotor()->escribir("Salir",idspriteSalir,width,height,1,*window);
 }
    
 void Menu::render(){
    //window->clear(sf::Color::Black);
    if (!texture.loadFromFile("HUD/fondoMenu.jpg"))
    {
    }
        //window->draw(sprite);

    /*for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
        sprite.setTexture(texture);*/
    window->display();
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0){
        {
           /*if(selectedItemIndex==0){
               RenderManager::Instance(1)->getMotor()->updateTextoRojo(idspriteEmpezar);
               RenderManager::Instance(1)->getMotor()->updateTextoBlanco(idspriteOpciones);
           }
           if(selectedItemIndex==1){
               RenderManager::Instance(1)->getMotor()->updateTextoRojo(idspriteOpciones);
               RenderManager::Instance(1)->getMotor()->updateTextoBlanco(idspriteSalir);
           }
           if(selectedItemIndex==2){
               RenderManager::Instance(1)->getMotor()->updateTextoRojo(idspriteSalir);
           }*/
           selectedItemIndex--;
	}
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex < MAX_NUMBER_OF_ITEMS)
	{
           /*if(selectedItemIndex==0){
               RenderManager::Instance(1)->getMotor()->updateTextoRojo(idspriteEmpezar);
           }
           if(selectedItemIndex==1){
               RenderManager::Instance(1)->getMotor()->updateTextoBlanco(idspriteEmpezar);
               RenderManager::Instance(1)->getMotor()->updateTextoRojo(idspriteOpciones);
           }
           if(selectedItemIndex==2){
               RenderManager::Instance(1)->getMotor()->updateTextoBlanco(idspriteOpciones);
               RenderManager::Instance(1)->getMotor()->updateTextoRojo(idspriteSalir);
           }*/
           selectedItemIndex++;
	}
}
Menu *m1=Menu::Instance();
Menu *m2=m1->Instance();
Menu &refm=*Menu::Instance();

