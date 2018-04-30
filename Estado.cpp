#include "Estado.h"
#include "RenderManager.h"

Estado* Estado::pinstance=0;                     
Estado* Estado::Instance(){
    if(pinstance==0){
        pinstance=new Estado;
    }
    return pinstance;
}
Estado::Estado(){
    
}
Estado *t1=Estado::Instance();
Estado *t2=t1->Instance();
Estado &reft=*Estado::Instance();
void Estado::update(){
    std::cout<<"Albaricoque"<<std::endl;
}   
void Estado::updateIA(){
    
}
void Estado::render(){
}
void Estado::inicializar(){
    
}