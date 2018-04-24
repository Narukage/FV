#include "Estado.h"

Estado* Estado::pinstance=0;                     
Estado* Estado::Instance(){
    if(pinstance==0){
        pinstance=new Estado;
    }
    return pinstance;
}
Estado::Estado(){
    
}
Estado *p1=Estado::Instance();
Estado *p2=p1->Instance();
Estado &ref=*Estado::Instance();
                                                            