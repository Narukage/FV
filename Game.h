#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.h"
#include "Player.h"
#include "RenderManager.h"



class Game{
    
private:
    bool isPlay;
    RenderManager* motor;
    Tablero* tablero;
    Tablero* tablero2;
    Invocacion* invocacion;
    Player* player;
    Player* player2;
    Player* current = player;
            
    sf::Vector2i coord;
    bool presionado;
    bool cartaseleccionada = false;
    bool actuainvocacion =false;
    Invocacion* inv;
    int posXinvocacion=-1;
    int posYinvocacion=-1;
    sf::Vector2i campo;
    sf::Vector2i mano;
    int ganador;
    bool empate=false;
    bool generalmuerto1=false;
    bool generalmuerto2=false;
    bool tieneadyacentes=false;
    bool meToca = true;
   
       
    static Game* pinstance;
private:
    void inicializar();
    void eventos();
    void update();
    void updateIA();
    void render();
    void cleared();
    void finalizado();
protected:
    Game();
public:
    static Game* Instance();
    ~Game();
    void run();
};