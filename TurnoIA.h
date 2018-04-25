#include <iostream>
#include "Estado.h"
    class TurnoIA : public Estado {
    public:
    static TurnoIA* Instance();
protected:
    TurnoIA();
    TurnoIA(const TurnoIA &);
    TurnoIA &operator=(const TurnoIA &);
private:
    static TurnoIA* pinstance;
};   