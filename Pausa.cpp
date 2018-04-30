#include "Pausa.h"


Pausa* Pausa::pinstance=0;                     
Pausa* Pausa::Instance(){
    if(pinstance==0){
        pinstance=new Pausa;
    }
    return pinstance;
}
Pausa::Pausa(){
    
}
Pausa *ps1=Pausa::Instance();
Pausa *ps2=ps1->Instance();
Pausa &refps=*Pausa::Instance();
