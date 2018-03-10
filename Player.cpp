#include "Player.h"

Player::Player(int commander){
    vida=100;
    mana=10;
    
    if(commander==1){
        if(!textura.loadFromFile("/home/naru/Escritorio/retrato1.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(0,0);
    }else{
        if(!textura.loadFromFile("/home/naru/Escritorio/retrato2.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(700,0);
    }
    
   retrato.setTexture(textura);
}

Player::~Player(){
}
