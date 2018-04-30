#include <iostream>
#include "Estado.h"
#include "Game.h"
    class Partida : public Estado {
    public:
    static Partida* Instance();
    void update();
    void cambiarApausa();
protected:
    Partida();
    Partida(const Partida &);
    Partida &operator=(const Partida &);
private:
    static Partida* pinstance;
};   