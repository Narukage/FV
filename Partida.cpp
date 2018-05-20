#include "Partida.h"
#include "Pausa.h"
#include "Game.h"

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
            if((coord.x>100 && coord.x<700)&&(coord.y>80 && coord.y<475)){
              
                    if(Tablero::Instance()->addUnit(campo.x,campo.y,inv,1)){
                        
                        cartaseleccionada=false;
                        /* vector<Invocacion*>::iterator it3;
                        int i=0;*/

                    }
                
                /*else{
                    if(Tablero::Instance()->addUnit(campo.x,campo.y,inv,2)){
                        cartaseleccionada=false;
                         vector<Invocacion*>::iterator it3;
                        int i=0;

                    }
                }*/
            }
        }else{ //queremos mover unidad en tablero
            
            if(!Tablero::Instance()->isFree(campo.x,campo.y) && actuainvocacion==false){ //si la posicion que clickamos contiene una unidad
                
                actuainvocacion=true;
                Tablero::Instance()->Adyacentes(campo.x,campo.y);
                tieneadyacentes=true;
                posXinvocacion=campo.x;
                posYinvocacion=campo.y;
            } //unidad seleccionada, preparada para hacer alguna accion
            else if(actuainvocacion==true && Tablero::Instance()->isFree(campo.x,campo.y) && Tablero::Instance()->getAlcanzable(campo.x,campo.y)==1){
                 cout<< "ESTOY ATACANDO 3" << endl;
                if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->getMovimiento()>0){
                    cout<<"Posicion x : " <<posXinvocacion << "Posicion y :" <<posYinvocacion << endl;
                Tablero::Instance()->moveToPos(posXinvocacion, posYinvocacion,campo.x,campo.y,Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion));
                Tablero::Instance()->setFree(campo.x,campo.y,false);
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                cout << "me reinicio" << endl;
                
                Tablero::Instance()->ReiniciarAdy();
                }
                else{
                //Tablero::Instance()->setClick(0);
                }
            }//ataque
            else if(actuainvocacion==true && !Tablero::Instance()->isFree(campo.x,campo.y)&&Tablero::Instance()->getAlcanzable(campo.x,campo.y)==1){
                if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->getMovimiento()>0){
                cout<< "coordx :"<<coord.x << "coordy :"<< coord.y << endl;
                    if(Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)!=NULL&&!Tablero::Instance()->getPlayer()->JugadaEn(posXinvocacion,posYinvocacion)->esAliado(Tablero::Instance()->getPlayer()->JugadaEn(campo.x,campo.y)->getComandante())){
                    cout<< "ESTOY ATACANDO" << endl;
                    ganador=Tablero::Instance()->atackToPos(posXinvocacion,posYinvocacion,campo.x,campo.y);
                       //tablero->setFree(campox,campoy,true);
                    if(ganador==-1){
                        generalmuerto1=true;
                    }
                    if(ganador==-2){
                        generalmuerto2=true;
                    }
                    if(ganador==-3){
                        empate=true;
                    }
                   
                actuainvocacion=false;
                posXinvocacion=-1;
                posYinvocacion=-1;
                cout << "me reinicio2" << endl;
                 if(Tablero::Instance()->getClick()==0){
                    Tablero::Instance()->ReiniciarAdy();
                 }
                }
                else{
                        cout<< "ESTOY ATACANDO 10" << endl;
                        actuainvocacion =false;
                        
                    }
                }
            } 
            
            else{
                 
               actuainvocacion=false;
               posXinvocacion=-1;
               posYinvocacion=-1;
               //cout << "me reinicio3" << endl;
                if(Tablero::Instance()->getClick()==0)
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
                    Tablero::Instance()->attackIA(); // AQUI SE SABE SI SE ACABA PARTIDA, EL ENTERO QUE DEVUELVA
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
    if(generalmuerto1){
        std::cout << "Has perdido" << std::endl;
    }
    if(generalmuerto2){
        std::cout << "Has ganado" << std::endl;
    }
    if(empate){
        std::cout << "Empate" << std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        std::cout << "Nueva partida" << std::endl;
        //Reseteamos todo
        inicializar();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        Game::Instance()->isPlay=false;
    }
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
        
        cout << "animo carta" << endl;
        sf::Sprite carta = RenderManager::Instance(1)->getMotor()->buscar(id);
        sf::Vector2f pos = carta.getPosition();
        carta.setPosition(pos.x,480+10*std::sin(cont));
        window->draw(carta);
        cont++;
        /*RenderManager::Instance(1)->getMotor()->updateAnimacion(id,0,0.1f);
        RenderManager::Instance(1)->getMotor()->dibujarAnimacion(id,inv->getJugar()*100+110,450,1,window);*/
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