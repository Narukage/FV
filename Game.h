#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.h"
#include "Player.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Estado.h"




class Game{
    
private:
    sf::RenderWindow window;
    RenderManager* motor;
    Tablero* tablero;
    Tablero* tablero2;
    Invocacion* invocacion;
    Player* player;
    Player* player2;
    Player* current = player;  

       
    static Game* pinstance;
private:
    void inicializar();
    void eventos();
    void update();
    void cleared();
protected:
    Game();
public:
    bool isPlay;
    Estado* state;  // <- descomentar esta linea cuando el menu este terminado
    static Game* Instance();
    ~Game();
    void run();
    void cambiarApartida();
    Estado* getState();
    sf::RenderWindow* getWindow(){ return &window; };
};