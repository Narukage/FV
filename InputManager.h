#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "InputFachada.h"
#include <string>
#include <vector>

////SINGLETON

class InputManager {
private:
    InputFachada* input;
    static InputManager* pinstance;
    
public:
    void apagar();
    static InputManager* Instance(int libreria);
    ~InputManager();
    InputFachada* getInput(){ return input; }
    int PulsaTecla();
    bool PulsaEscape();
protected:
    InputManager(int libreria);
    
};

class FachadaInput : public InputFachada {
    private:
        sf::Vector2i coord;
        sf::Vector2i campo;
        sf::Vector2i mano;
        int turno = 1;
        bool presionado = false;
        bool meToca = true;
        sf::Event evento;
    
    public:
        ///////////////////////////////
        // CONSTRUCTO / DESTRUCTOR
        ///////////////////////////////
        FachadaInput() : InputFachada(){};
        virtual ~FachadaInput(){};
        
        ///////////////////////////////
        // FUNCIONES PRINCIPALES
        ///////////////////////////////
        void turnoIA(bool cambio);
        void Eventos(bool isPlay, sf::RenderWindow& window);
        void nexTurn(int num){ turno=num+1; };
        void cambioTurno(bool meTo){if(meTo==true){meToca=false;}else{meToca=true;}};

        ///////////////////////////////
        // GETTERS Y SETTERS
        ///////////////////////////////
        sf::Vector2i getCoord()         { return coord;      };
        sf::Vector2i getCampo()         { return campo;      };
        sf::Vector2i getMano()          { return mano;       };
        int getTurno()                  { return turno;      };
        bool getMeToca()                { return meToca;     };
        bool getPresionado()            { return presionado; };
        void setMeToca(bool meTo)       { meToca = meTo;     };
        void setTurno(int num)          { turno=num;         };
};    
#endif
