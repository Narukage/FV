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
    
    if(!textura2.loadFromFile("/home/naru/Escritorio/Pac-Man_sprite.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
}

bool Tablero::addUnit(int posx, int posy, Invocacion* unit, int spawn){
    
    /*posx=posx/HEIGHT;
    posy=posy/WIDTH;*/
    
    //Convert posx and posy from pixel values to matrix values
    
    std::cout << "posx: " << posx << std::endl;
    std::cout << "posy: " << posy << std::endl;
    
    if(spawn==1){
        if(((posx>=0 && posx<3)&& (posy>=0 && posy<10))&& isFree(posx,posy)){
            board[posx][posy].free=false;
            board[posx][posy].unit=unit;
            board[posx][posy].sprite.setTexture(textura2);
            return true; 
        }
    }
    if(spawn==2){
        if(((posx>WIDTH-4 && posx<WIDTH-1)&& (posy>=0 && posy<HEIGHT-1))&& isFree(posx,posy)){
          board[posx][posy].free=false;
            board[posx][posy].unit=unit;
            board[posx][posy].sprite.setTexture(textura2);
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
       board[posx][posy].sprite.setTexture(textura2);
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
        
    if(!textura.loadFromFile("/home/naru/Escritorio/150px-SokobanWallDepictionDrawing.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
   for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
          board[i][j].sprite.setTexture(textura);
          board[i][j].sprite.setPosition((i*50),(j*50));
          board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
          if(board[i][j].free){
            window.draw(board[i][j].sprite);
          }
        }
    }         
}