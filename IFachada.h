#ifndef IFACHADA_H
#define IFACHADA_H

//La fachada es una clase abstracta
class IFachada {
public:
    IFachada(){};
    virtual ~IFachada(){};
    virtual void crearVentana(int width, int height, int frames, bool vsync) = 0;
    virtual int crearAnimacion() = 0;
    virtual bool borrarAnimacion() = 0;
    virtual int crearSprite() = 0;
    virtual bool borrarSprite(int id) = 0;
    virtual void dibujar() = 0;
    virtual int crearAudio() = 0;
    virtual bool borrarAudio() = 0;
    virtual void play() = 0;
    virtual int crearTexto() = 0;
    virtual bool borrarTexto() = 0;
    virtual void escribir() = 0;
private:

};

#endif /* IFACHADA_H */

