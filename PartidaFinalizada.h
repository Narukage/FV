#include <iostream>
#include "Estado.h"
    class PartidaFinalizada : public Estado {
    public:
    static PartidaFinalizada* Instance();
protected:
    PartidaFinalizada();
    PartidaFinalizada(const PartidaFinalizada &);
    PartidaFinalizada &operator=(const PartidaFinalizada &);
private:
    static PartidaFinalizada* pinstance;
};   