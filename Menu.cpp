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

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        Menu::MoveUp();
    }
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        Menu::MoveDown();
    }
    if(InputManager::Instance(1)->PulsaPartida() && selectedItemIndex==0){
            Game::Instance()->cambiarApartida();
    }
}
void Menu::render(){
    //window->clear(sf::Color::Black);
    if (!texture.loadFromFile("HUD/fondoMenu.jpg"))
    {
    }
        //window->draw(sprite);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
        sprite.setTexture(texture);
    window->display();
}
    void Menu::inicializar(){
           if (!font.loadFromFile("Fonts/FreeMono.ttf"))
	{
		        std::cout<<"ENTRAMOS EN EL BUCLE"<<std::endl;

	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(800 / 2, 600 / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(800 / 2, 600 / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(800 / 2, 600 / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    }

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
	{
            std::cout<<"entro up"<<std::endl;

		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
                std::cout<<"entro down"<<std::endl;

		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}
Menu *m1=Menu::Instance();
Menu *m2=m1->Instance();
Menu &refm=*Menu::Instance();

