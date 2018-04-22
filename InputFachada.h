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
    virtual void Eventos(bool isPlay) = 0;
    virtual void nexTurn(int num) = 0;
    virtual void cambioTurno(bool meTo) = 0;
};

#endif /* IFACHADA_H */

