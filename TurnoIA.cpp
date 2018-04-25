#include "TurnoIA.h"


TurnoIA* TurnoIA::pinstance=0;                     
TurnoIA* TurnoIA::Instance(){
    if(pinstance==0){
        pinstance=new TurnoIA;
    }
    return pinstance;
}
TurnoIA::TurnoIA(){
    
}
TurnoIA *tia1=TurnoIA::Instance();
TurnoIA *tia2=tia1->Instance();
TurnoIA &reftia=*TurnoIA::Instance();


