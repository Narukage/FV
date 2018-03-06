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

bool Tablero::addUnit(int posx, int posy/*, Invocacion& unit, Player& player*/){
    /*if (player.spawn1==true){ //spawn 1 case - commander 1
       if(((posx>=0 && posx<3)&& (posy>=0 && posy<10))&& isFree(posx,posy){
     * board[posx][posy].free=false;
     * board[posx][posy].unit=unit;
     * return true;
     *          
      }else{ //spawn 2 case //commander 2
     *  if(((posx>WIDTH-4 && posx<WIDTH-1)&& (posy>=0 && posy<HEIGTH-1))&& isFree(posx,posy){
        * board[posx][posy].free=false;
        * board[posx][posy].unit=unit;
        * return true;
     * }
     * return false;
     */
}

bool Tablero::moveToPos(int posx, int posy/*, Invocacion& unit*/){
   if(((posx<10 && posx>=0) && (posy<20 && posy>=0)) && board[posx][posy].free){
       board[posx][posy].free=false;
       //board[posx][posy].unit=unit;
       //board[unit.getX][unit.getY].removeUnit();
       
       return true;
   }else{
       return false;
   }        
}
        
bool Tablero::removeUnit(int posx, int posy){
    board[posx][posy].free=true;
    //board[posx][posy].unit=null;
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