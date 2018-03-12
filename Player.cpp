#include "Player.h"

Player::Player(int commander){
    vida=100;
    mana=10;
    manarest=10;
    actual=Baraja();
    if(commander==1){
         vida=180;
        comandante=Invocacion("P",0,5,vida,true);
        if(!textura.loadFromFile("/home/delegacioneps/Summoners/assets/HUD/retrato1.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(0,0);
    }else{
         vida=100;
        comandante=Invocacion("E",0,8,vida,true);
        if(!textura.loadFromFile("/home/delegacioneps/Summoners/assets/HUD/retrato2.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(700,0);
    }
    
   retrato.setTexture(textura);
}
Invocacion Player::Mostrar_mano(){
    //Llamar al array mano y pasarle invocacion por invocacion a tablero, posicion fija
}
Player::~Player(){
}
