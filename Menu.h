#include <iostream>
#include "Estado.h"
/*
 :public es heredera de Estado en metodos y tipo de clase
 */
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