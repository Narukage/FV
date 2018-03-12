#include "Tablero.h"

Tablero::Tablero(){
    
    //filling board matrix with free positions
    
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            board[i][j].free=true;
            board[i][j].coordX=i;
            board[i][j].coordY=j;
        }
    }
    
    if(!textura2.loadFromFile("/home/delegacioneps/Summoners/assets/Sprites/bloque2.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    if(!textura3.loadFromFile("/home/delegacioneps/Summoners/assets/Sprites/bloque3.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    board[0][3].free=false; //commander 1
    board[11][3].free=false; //commander 2
}

bool Tablero::addUnit(int posx, int posy, Invocacion* unit, int spawn){
    
//Conversion from pixel to matrix values
    posx=(posx-100)/50;
    posy=(posy-80)/50;
    
    if(spawn==1){
        if(((posx>=0 && posx<3)&& (posy>=0 && posy<10))&& isFree(posx,posy)){
            board[posx][posy].free=false;
            board[posx][posy].unit=unit;
            return true; 
        }
    }
    if(spawn==2){
        if(((posx>WIDTH-4 && posx<WIDTH-1)&& (posy>=0 && posy<HEIGHT-1))&& isFree(posx,posy)){
          board[posx][posy].free=false;
            board[posx][posy].unit=unit;
            return true;  
        }
    }
    return false;
}

bool Tablero::moveToPos(int posx, int posy, Invocacion* unit){
   if(((posx<10 && posx>=0) && (posy<20 && posy>=0)) && board[posx][posy].free){
       board[posx][posy].free=false;
       board[posx][posy].unit=unit;
       removeUnit(unit->getX(),unit->getY(),unit);
       return true;
   }else{
       return false;
   }        
}
        
bool Tablero::removeUnit(int posx, int posy, Invocacion* unit){
    board[posx][posy].free=true;
    board[posx][posy].unit=NULL;
}

void Tablero::resetMap(){
   for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            board[i][j].free=true;
            board[i][j].unit=NULL;
        }
    }         
}

void Tablero::drawMap(sf::RenderWindow& window){
        
    if(!textura.loadFromFile("/home/delegacioneps/Summoners/assets/Sprites/150px-SokobanWallDepictionDrawing.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
   for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            if(i<WIDTH/2){
                if(board[i][j].free){
                    board[i][j].sprite.setTexture(textura);
                }else{
                 board[i][j].sprite.setTexture(textura3);   
                }
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
            }else{
                if(board[i][j].free){
                board[i][j].sprite.setTexture(textura2);
                }else{
                 board[i][j].sprite.setTexture(textura3);   
                }
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
            }
          window.draw(board[i][j].sprite);
        }
    }         
}