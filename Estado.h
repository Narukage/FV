#include <iostream>
/*
 *Clase para el patron State de la que heredan Menu,Partida,Pausa,etc
 *Contiene metodos que heredan sus hijos, los metodos se declaran virtual para ello
 *y solo seran los 3 comunes necesarios para los otros metodos que modificaran la pantalla 
 */

class Estado{
public:
    static Estado* Instance();
    virtual void update();
    virtual void updateIA();
    virtual void render();
protected:
    Estado();
    Estado(const Estado &);
    Estado &operator=(const Estado &);
private:
    static Estado* pinstance;
};