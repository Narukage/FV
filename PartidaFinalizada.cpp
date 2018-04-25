#include "PartidaFinalizada.h"


PartidaFinalizada* PartidaFinalizada::pinstance=0;                     
PartidaFinalizada* PartidaFinalizada::Instance(){
    if(pinstance==0){
        pinstance=new PartidaFinalizada;
    }
    return pinstance;
}
PartidaFinalizada::PartidaFinalizada(){
    
}
PartidaFinalizada *pf1=PartidaFinalizada::Instance();
PartidaFinalizada *pf2=pf1->Instance();
PartidaFinalizada &refpf=*PartidaFinalizada::Instance();
