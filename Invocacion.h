/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Invocacion.h
 * Author: dhl4
 *
 * Created on 6 de marzo de 2018, 9:56
 */

#ifndef INVOCACION_H
#define INVOCACION_H

class Invocacion {
public:
    Invocacion();
    Invocacion(const Invocacion& orig);
    virtual ~Invocacion();
    void setPosicion(int x, int y);
private:
    int pos_x;
    int pos_y;
};

#endif /* INVOCACION_H */

