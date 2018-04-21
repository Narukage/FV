#include "RenderManager.h"

RenderManager* RenderManager::pinstance = 0;
    
RenderManager* RenderManager::Instance(int libreria){
    if(pinstance==0){
        pinstance = new RenderManager(libreria);
    }
    return pinstance;
}

RenderManager::RenderManager(int libreria) {
    if(libreria==1){
        motor = new FachadaMotor2D();
    }else{
        //otra libreria de graficos 2D como SDL, OpenGL...
    }
}

/*RenderManager *p1 = RenderManager::Instance(1);
RenderManager *p2 = p1->Instance(1);
RenderManager &ref = * RenderManager::Instance(1);*/



