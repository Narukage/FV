#include <iostream>
#include "Estado.h"
    class Pausa : public Estado {
    public:
    static Pausa* Instance();
protected:
    Pausa();
    Pausa(const Pausa &);
    Pausa &operator=(const Pausa &);
private:
    static Pausa* pinstance;
};   