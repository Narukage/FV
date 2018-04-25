#include "Partida.h"


Partida* Partida::pinstance=0;                     
Partida* Partida::Instance(){
    if(pinstance==0){
        pinstance=new Partida;
    }
    return pinstance;
}
Partida::Partida(){
    
}
Partida *pt1=Partida::Instance();
Partida *pt2=pt1->Instance();
Partida &refpt=*Partida::Instance();
