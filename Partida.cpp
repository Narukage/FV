#include "Partida.h"
#include "Pausa.h"
#include "Game.h"
#include "PartidaFinalizada.h"

Partida* Partida::pinstance=0;                     
Partida* Partida::Instance(){
    if(pinstance==0){
        pinstance=new Partida;
    }
    return pinstance;
}
Partida::Partida(){
    inv = new Invocacion();
    generalmuerto1=false;
    generalmuerto2=false;
    empate=false;
    Tablero::Instance()->cargarMapa();
    //state=Game::Instance();
    //Pasamos la ventana
    Tablero::Instance()->setWindow(window);
}

void Partida::update(){
    //Una vez este el StateManager hay que mover el update
    id = -1;
    primero = false;
    RenderManager::Instance(1)->getMotor()->crearClock();
    presionado = InputManager::Instance(1)->getInput()->getPresionado();
    meToca = Tablero::Instance()->getTurno();
        if(InputManager::Instance(1)->PulsaEscape()){
            Partida::Instance()->cambiarApausa();
    }
    if(presionado && meToca){
        coord = InputManager::Instance(1)->getInput()->getCoord();
        campo = InputManager::Instance(1)->getInput()->getCampo();
        mano = InputManager::Instance(1)->getInput()->getMano();
        if((coord.x>150 && coord.x<650)&&(coord.y>480 && coord.y<600)){
            //aqu� controlar mano
            std::cout<<"Entramos dentro del la mano"<<std::endl;
            inv=Tablero::Instance()->esCarta(mano.x,mano.y);
            
            if(inv!=NULL){
                std::cout<<"esCarta es distinto de null"<<std::endl;
                id = inv->getIdCarta();
                cartaseleccionada=true;
                 
            }
        }
        
        else if(cartaseleccionada ){ //queremos invocar en tablero
            cartaseleccionada=false;
            Tablero::Instance()->addUnit(campo.x,campo.y,inv,1);
        }
        if(cartaseleccionada == false){ //queremos mover unidad en tablero
            if(actuainvocacion && esperando && (posXinvocacion!=campo.x || posYinvocacion != campo.y) ){
                esperando = false;
            }
            if(esperando==false&&actuainvocacion==false&&!Tablero::Instance()->isFree(campo.x,campo.y) && Tablero::Instance()->getPlayer()->estaJugadaEn(campo.x,campo.y) && actuainvocacion==false){ //si la posicion que clickamos contiene una unidad
                
                actuainvocacion=true;
                Tablero::Instance()->Adyacentes(campo.x,campo.y);
                tieneadyacentes=true;
                posXinvocacion=campo.x;
                posYinvocacion=campo.y;
                primero = true;
                esperando = true;
            } //unidad seleccionada, preparada para hacer alguna accion
            else if(esperando==false&&primero == false &&actuainvocacion==true && Tablero::Instance()->isFree(campo.x,campo.y) && Tablero::Instance()->getAlcanzable(campo.x,campo.y)==1){
                 cout<< "ESTOY ATACANDO 3" << endl;
                if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->getMovimiento()>0){
                    cout<<"Posicion x : " <<posXinvocacion << "Posicion y :" <<posYinvocacion << endl;
                Tablero::Instance()->moveToPos(posXinvocacion, posYinvocacion,campo.x,campo.y,Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion));
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                cout << "me reinicio" << endl;
                
                Tablero::Instance()->ReiniciarAdy();
                }
                else{
                    //no se puede mover
                    posXinvocacion=-1;
                    posYinvocacion=-1;
                    Tablero::Instance()->ReiniciarAdy();
                }
            }//ataque
            else if(esperando==false&&primero == false&&actuainvocacion==true && !Tablero::Instance()->isFree(campo.x,campo.y)&&Tablero::Instance()->getAlcanzable(campo.x,campo.y)==1){
                cout<<"POR QUE AQUI: "<<endl;
                if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->getMovimiento()>0){
                cout<< "coordx :"<<coord.x << "coordy :"<< coord.y << endl;
                if(Tablero::Instance()->getPlayer()->estaJugadaEn(campo.x,campo.y)==false){
                    if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)!=NULL&&!Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->esAliado(Tablero::Instance()->getPlayer2()->JugadaEn(campo.x,campo.y)->getComandante())){
                        cout<< "ESTOY ATACANDO" << endl;
                    ganador=Tablero::Instance()->atackToPos(posXinvocacion,posYinvocacion,campo.x,campo.y);
                       //tablero->setFree(campox,campoy,true);
                    if(ganador<0 && ganador>=-3){
                    if(ganador==-1){
                        generalmuerto1=true;
                    }
                    if(ganador==-2){
                        generalmuerto2=true;
                    }
                    if(ganador==-3){
                        empate=true;
                    }
                    finalizado();
                    }
                   
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                cout << "me reinicio2" << endl;
                        Tablero::Instance()->ReiniciarAdy();
                     
                    }
                }
                else if(esperando==false){
                        cout<< "ESTOY ATACANDO 10" << endl;
                        posXinvocacion=-1;
                        posYinvocacion=-1;
                        Tablero::Instance()->ReiniciarAdy();
                        actuainvocacion =false;
                        
                    }
                }
            } 
            
            else if(esperando==false&&actuainvocacion==true){
                 
               actuainvocacion=false;
               posXinvocacion=-1;
               posYinvocacion=-1;
               //cout << "me reinicio3" << endl;
                
               Tablero::Instance()->ReiniciarAdy();
            }
            
            
        }
        
        presionado=false;
    //}
    //finalizado();
    }
    if(!meToca){ //IA
       /* int randomx= rand() % 3 -1;
        cout<<"Random : "<< randomx << endl;*/
        cout <<"MANA RESTANTE ES : "<< Tablero::Instance()->getPlayer2()->getManaRest()<< endl;
        if(Tablero::Instance()->addUnitIAB()>Tablero::Instance()->getPlayer2()->getManaRest()){
            cout << "Va bien muyayo: "<< endl; //AQUI PONES RELOJ PARA QUE HAYA TRANSICCIÓN
            if(control!=2){
                control = Tablero::Instance()->moveToPosIA();
                if(control == -1){
                    ganador=Tablero::Instance()->attackIA(); // AQUI SE SABE SI SE ACABA PARTIDA, EL ENTERO QUE DEVUELVA
                    if(ganador<0 && ganador>=-3){
                    if(ganador==-1){
                        generalmuerto1=true;
                    }
                    if(ganador==-2){
                        generalmuerto2=true;
                    }
                    if(ganador==-3){
                        empate=true;
                    }
                    finalizado();
                    }
                }
                if(control == 1){
                    cout<<"Movido comandante: "<<Tablero::Instance()->getPlayer2()->getJugadas().at(0)->getMovimiento()<<endl;
                }
                if(control == 2){
                    cout<<"No le quedan movimientos al comandante: "<<Tablero::Instance()->getPlayer2()->getJugadas().at(0)->getMovimiento()<<endl;
                }
             /*if(controlAtaque==false){
                
                }*/
            }
            if(control == 2){
                cout<<"ENTRO PARA MOVER UNIDADES primero : "<<endl;
                if(controlU !=2){
                    cout<<"ENTRO PARA MOVER UNIDADES : "<<endl;
                    controlU = Tablero::Instance()->moveToPosIAU();
                    if(controlU == -1){
                        Tablero::Instance()->attackIAU();
                    }
                    if(controlU == 1){
                         cout<<"Movido UNIDAD: "<<endl;
                    }
                    if(controlU == 2){
                         cout<<"UNIDAD NO VA A MOVERSE: "<<endl;
                    }
                }
                if(control == 2 && controlU == 2){
                    cout<<"Cambio turno"<< endl;
                    InputManager::Instance(1)->getInput()->cambioTurno( InputManager::Instance(1)->getInput()->getMeToca());
                    control=0;
                    controlU=0;
                    
                     InputManager::Instance(1)->getInput()->turnoIA(true);
                }
            }
        }
        //IaCartas=Tablero::Instance()->addUnitIA();
        //IaMover=Tablero::Instance()->moveToPosIA();
        //IaMoverU=Tablero::Instance()->moveToPosIAU();
        /*cout<<"salgo bien "<<endl;
        if(IaCartas==true && IaMover==true && IaMoverU==true){
            cout<<"fallo en el cambio de turno "<<endl;
            InputManager::Instance(1)->getInput()->turnoIA(true);
            cout<<"fallo en el cambio de turno pero soy: "<<meToca<<endl;
            
        }*/
        /*int randomx;
       srand (time(NULL));
                    randomx= rand() % 3 +9;
                    cout<<"random "<<randomx<<endl;*/
    }
}
void Partida:: updateIA(){
    meToca = InputManager::Instance(1)->getInput()->getMeToca();
    if(meToca==false){
        inv=Tablero::Instance()->esCarta(0,0);
        if(inv!=NULL){
            
        }
    }
}

void Partida::finalizado(){
    PartidaFinalizada::Instance()->inicializar();
    Game::Instance()->cambiarAfinalizado();
}
void Partida::render(){
    window->clear(sf::Color::Black);
    
    Tablero::Instance()->drawMap();
    Tablero::Instance()->drawUnit();
    Tablero::Instance()->drawLife(1);
    Tablero::Instance()->drawLifeNumb(1);
    Tablero::Instance()->drawLife(2);
    Tablero::Instance()->drawLifeNumb(2);
    Tablero::Instance()->drawMana(1);
    Tablero::Instance()->drawManaNumb(1);
    Tablero::Instance()->drawManaRest(1);
    Tablero::Instance()->drawBarra(1);
    Tablero::Instance()->drawMana(2);
    Tablero::Instance()->drawManaNumb(2);
    Tablero::Instance()->drawManaRest(2);
    Tablero::Instance()->drawRetrato(1);
    Tablero::Instance()->drawRetrato(2); //same
    Tablero::Instance()->Mostrar_mano(id);

    if(cartaseleccionada){
       sf::Sprite carta = RenderManager::Instance(1)->getMotor()->buscar(id);
       sf::Vector2f pos = carta.getPosition();
       carta.setPosition(pos.x,480+10*std::sin(cont));
       window->draw(carta);
       cont++;
    }
           
    window->display();
}
void Partida::cambiarApausa(){
    window->clear(sf::Color::Black);
    Pausa::Instance()->inicializar();
   Game::Instance()->cambiarApausa();
    //Game::Instance();
}
Partida *pt1=Partida::Instance();
Partida *pt2=pt1->Instance();
Partida &refpt=*Partida::Instance();