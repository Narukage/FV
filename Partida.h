#include <iostream>
#include "Estado.h"
    class Partida : public Estado {
    public:
    static Partida* Instance();
protected:
    Partida();
    Partida(const Partida &);
    Partida &operator=(const Partida &);
private:
    static Partida* pinstance;
};   