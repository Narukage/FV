#ifndef INPUTFACHADA_H
#define INPUTFACHADA_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

using namespace std;

//FACHADA DEL INPUT DE TECLADO Y RATON

//La fachada es una clase abstracta
class InputFachada {
public:
    InputFachada(){};
    virtual ~InputFachada(){};
    virtual void Eventos(bool isPlay, sf::RenderWindow& window) = 0;
    virtual void nexTurn(int num) = 0;
    virtual void cambioTurno(bool meTo) = 0;
    virtual bool getPresionado() = 0;
    virtual sf::Vector2i getCoord() = 0;
    virtual sf::Vector2i getCampo() = 0;
    virtual sf::Vector2i getMano() = 0;
    virtual bool getMeToca() = 0;
    virtual void setMeToca(bool meTo) = 0;
    virtual int getTurno() = 0;
    virtual void setTurno(int num) = 0;
};

#endif /* IFACHADA_H */

