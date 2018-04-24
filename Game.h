#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.h"
#include "Player.h"
#include "Interface.h"



class Game{
    
private:
     sf::Clock clock;
    sf::RenderWindow window;
    sf::Event evento;      
    bool isPlay = true;
    Tablero* tablero;
    Tablero* tablero2;
    Invocacion* invocacion;
    Player* player;
    Player* player2;
    //Player* aux=tablero->getPlayer();
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
    int campox;
    int campoy;
    int manox;
    int manoy;
    int ganador;
    bool empate=false;
    bool generalmuerto1=false;
    bool generalmuerto2=false;
    bool tieneadyacentes=false;
   
    bool meToca = true;
       
private:
    void inicializar();
    void eventos();
    void update();
    void updateIA();
    void render();
    void cleared();
    void setTurno(int num){turno=num;}
    int getTurno(){return turno;}
    void nexTurn(int num);
    bool getMeToca(){return meToca;}
    void setMeToca(bool meTo){meToca = meTo;}
    void cambioTurno(bool meTo){if(meTo==true){meToca=false;}else{meToca=true;}};
    void finalizado();
    
   // void setTurno(int num){turno=num;}
    //int getTurno(){return turno;}
    //void nexTurn(int num);
public:
    Game();
    ~Game();
    void run();
};