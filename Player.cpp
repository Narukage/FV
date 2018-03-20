#include "Player.h"

Player::Player(int commander){
    vida=100;
    mana=10;
    manarest=10;

    
    if(commander==1){
         vida=180;
        comandante=Invocacion("P",0,5,vida,true);
        if(!textura.loadFromFile("assets/HUD/retrato1.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(0,0);
    }else{
         vida=100;
        comandante=Invocacion("E",0,8,vida,true);
        if(!textura.loadFromFile("assets/HUD/retrato2.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(700,0);
    }
   // string s="s";
    for(int i=0;i<19;i++){
        invo[i]=Invocacion();
    }
    invo[0]=Invocacion("C",1,1,1,false);
    invo[1]=Invocacion("y",3,3,2,false);
    invo[2]=Invocacion("Z",2,2,1,false);
    invo[3]=Invocacion("g",5,4,5,false);
    invo[4]=Invocacion("C",1,1,1,false);
    invo[5]=Invocacion("y",3,3,2,false);
    invo[6]=Invocacion("Z",2,2,1,false);
    invo[7]=Invocacion("g",5,4,5,false);
    invo[8]=Invocacion("C",1,1,1,false);
    invo[9]=Invocacion("y",3,3,2,false);
    invo[10]=Invocacion("Z",2,2,1,false);
    invo[11]=Invocacion("g",5,4,5,false);
    invo[12]=Invocacion("C",1,1,1,false);
    invo[13]=Invocacion("y",3,3,2,false);
    invo[14]=Invocacion("Z",2,2,1,false);
    invo[15]=Invocacion("g",5,4,5,false);
    invo[16]=Invocacion("C",1,1,1,false);
    invo[17]=Invocacion("y",3,3,2,false);
    invo[18]=Invocacion("Z",2,2,1,false);
    invo[19]=Invocacion("g",5,4,5,false);
    for(int j=0;j<5;j++){
         mano[j]=invo[j];
    }
    
   retrato.setTexture(textura);
}
void Player::Mostrar_mano(sf::RenderWindow& window){
    //Llamar al array mano y pasarle invocacion por invocacion a tablero, posicion fija
    /*for(int i=0;i<5;i++){
        mano[i].getSprite().setPosition((50*i)+200,500);
        window.draw(mano[i].getSprite());
        //no me deja acceder a invocacion de cada posicion del array
    }*/
    
        
}

Player::~Player(){
}
