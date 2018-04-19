#ifndef IFACHADA_H
#define IFACHADA_H

//La fachada es una clase abstracta
class IFachada {
public:
    IFachada(){};
    virtual ~IFachada(){};
    virtual void crearVentana(int width, int height, int frames, bool vsync) = 0;
    virtual void crearAnimacion() = 0;
    virtual int crearSprite() = 0;
    virtual bool borrarSprite(int id) = 0;
    virtual void dibujar() = 0;
    virtual void set_Position() = 0;
    virtual void set_Scale() = 0;
    virtual void set_Rotation() = 0;
    virtual void comprobarColision() = 0;
private:

};

#endif /* IFACHADA_H */

