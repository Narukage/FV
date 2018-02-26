#include "Tablero.h"

Tablero::Tablero(){
    
    //filling board matrix with free positions
    for(int i=0;i<10;i++){
        for(int j=0;j<20;i++){
            board[i][j].free=true;
            board[i][j].coordX=i;
            board[i][j].coordY=j;
        }
    }
}

bool Tablero::addUnit(int posx, int posy/*, Invocacion& unit*/){
    if(((posx<10 && posx>=0) && (posy<20 && posy>=0)) && board[posx][posy].free){ //if posx and posy are inside the board matrix and the position doesn't contain a unit already
        board[posx][posy].free=false;
        //boad[posx][posy].unit=unit;
        return true;
    }else{
        return false;
    }
}

bool Tablero::moveToPos(int posx, int posy){
            
}
        
bool Tablero::removeUnit(int posx, int posy){
    
}

void Tablero::resetMap(){
   for(int i=0;i<20;i++){
        for(int j=0;j<20;i++){
            board[i][j].free=true;
            //board[i][j].unit=null;
        }
    }         
}

void Tablero::drawMap(){
            
}