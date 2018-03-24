#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.h"
#include "Player.h"
#include "Interface.h"



class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;      
    bool isPlay = true;
    Tablero* tablero;
    Tablero* tablero2;
    Invocacion* invocacion;
    Player* player;
    Player* player2;
    Player* current = player;
    int turno = 1;
            
    Interface* interface;
    sf::Vector2i coord;
    bool presionado = false;
    bool cartaseleccionada = false;
    bool actuainvocacion =false;
    Invocacion* inv;
    int posXinvocacion=-1;
    int posYinvocacion=-1;
       
private:
    void inicializar();
    void eventos();
    void update();
    void render();
    void cleared();
    void setTurno(int num){turno=num;}
    int getTurno(){return turno;}
    void nexTurn(int num);
public:
    Game();
    ~Game();
    void run();
};