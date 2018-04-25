#include <iostream>
#include "Estado.h"
    class Menu : public Estado {
    public:
    static Menu* Instance();
protected:
    Menu();
    Menu(const Menu &);
    Menu &operator=(const Menu &);
private:
    static Menu* pinstance;
};   