
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "InputFachada.h"
#include <string>
#include <vector>

//SINGLETON

class InputManager {
private:
    InputFachada* input;
    static InputManager* pinstance;
    
public:
    static InputManager* Instance(int libreria);
    ~InputManager();
    
protected:
    InputManager(int libreria);
    
};

class FachadaInput : public InputFachada {
    private:
        sf::Vector2i coord;
        int campox;
        int campoy;
        int manox;
        int manoy;
        int turno = 0;
        bool presionado = false;
        bool meToca = true;
        sf::Event evento;
    
    public:
     FachadaInput() : InputFachada(){};
     virtual ~FachadaInput(){};
     void Eventos(bool isPlay);
     void nexTurn(int num);
     void cambioTurno(bool meTo){if(meTo==true){meToca=false;}else{meToca=true;}};
};    


#endif

