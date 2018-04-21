
#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H
#include "IFachada.h"
#include "FachadaMotor2D.h"

//SINGLETON

class RenderManager {
private:
    IFachada* motor;
    static RenderManager* pinstance;
    
public:
    static RenderManager* Instance(int libreria);
    
protected:
    RenderManager(int libreria);

};

#endif /* RENDERMANAGER_H */

