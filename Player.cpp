#include "Player.h"

Player::Player(int commander){
    vida=100;
    mana=10;
    manarest=10;

    
    if(commander==1){
         vida=100;
        comandante=Invocacion("P",0,5,vida,1);
        if(!textura.loadFromFile("assets/HUD/retrato1.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(0,0);
    }else{
         vida=100;
       comandante=Invocacion("E",0,8,vida,2);
        if(!textura.loadFromFile("assets/HUD/retrato2.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(700,0);
    }
   // string s="s";
    for(int i=0;i<19;i++){
        invo[i]=Invocacion();
    }
    invo[0]=Invocacion("C",1,1,1,commander);
    invo[1]=Invocacion("y",3,3,2,commander);
    invo[2]=Invocacion("Z",2,2,1,commander);
    invo[3]=Invocacion("g",5,4,5,commander);
    invo[4]=Invocacion("C",1,1,1,commander);
    invo[5]=Invocacion("y",3,3,2,commander);
    invo[6]=Invocacion("Z",2,2,1,commander);
    invo[7]=Invocacion("g",5,4,5,commander);
    invo[8]=Invocacion("C",1,1,1,commander);
    invo[9]=Invocacion("y",3,3,2,commander);
    invo[10]=Invocacion("Z",2,2,1,commander);
    invo[11]=Invocacion("g",5,4,5,commander);
    invo[12]=Invocacion("C",1,1,1,commander);
    invo[13]=Invocacion("y",3,3,2,commander);
    invo[14]=Invocacion("Z",2,2,1,commander);
    invo[15]=Invocacion("g",5,4,5,commander);
    invo[16]=Invocacion("C",1,1,1,commander);
    invo[17]=Invocacion("y",3,3,2,commander);
    invo[18]=Invocacion("Z",2,2,1,commander);
    invo[19]=Invocacion("g",5,4,5,commander);
    for(int j=0;j<5;j++){
         mano[j]=invo[j];
    }
   retrato.setTexture(textura);
   
}
void Player::Mostrar_mano(sf::RenderWindow& window){
    for(int i=0;i<5;i++){
        if(!textura3.loadFromFile("assets/Sprites/carta.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        } 
        carta.setTexture(textura3);
        mano[i].setCarta(carta);
        carta.setPosition((i*100)+150,480);
        window.draw(carta);
        mano[i].setJugar(i);
        
    }
    
        
}

Player::~Player(){
}
