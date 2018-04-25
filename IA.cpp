#include "IA.h"

IA::IA(){
    jugadorEnemigo=NULL;
}
IA::IA(Player* player){
    jugadorEnemigo = player;
    //Empieza el turno de la IA;
    
}