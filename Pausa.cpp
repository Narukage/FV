#include "Pausa.h"


Pausa* Pausa::pinstance=0;                     
Pausa* Pausa::Instance(){
    if(pinstance==0){
        pinstance=new Pausa;
    }
    return pinstance;
}
Pausa::Pausa(){
    std::cout<<"hola"<<std::endl;
}
void Pausa::update(){
    std::cout<<"Guantata de Thanos"<<std::endl;
}

Pausa *ps1=Pausa::Instance();
Pausa *ps2=ps1->Instance();
Pausa &refps=*Pausa::Instance();
