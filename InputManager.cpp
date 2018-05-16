#include "InputManager.h"
#include "Tablero.h"
#include "Game.h"

////SINGLETON

InputManager* InputManager::pinstance = 0;
    
InputManager* InputManager::Instance(int libreria){
    if(pinstance==0){
        pinstance = new InputManager(libreria);
    }
    return pinstance;
}

InputManager::InputManager(int libreria) {
    if(libreria==1){
        input = new FachadaInput();
    }else{
        //Otra libreria como SDL, OpenGL...
    }
}


InputManager *i1 = InputManager::Instance(1);
InputManager *i2 = i1->Instance(1);
InputManager &refi = * InputManager::Instance(1);

//CLASE FACHADAINPUT

void FachadaInput::Eventos(bool isPlay, sf::RenderWindow& window){
    while(window.pollEvent(evento)){
               if(evento.type==sf::Event::Closed){
                            isPlay = false;
                  }   
                              
          switch(evento.type){
           
                    case sf::Event::KeyPressed:

                        if(evento.key.code==sf::Keyboard::Q){
                            isPlay = false;
                        }
                        if(evento.key.code==sf::Keyboard::Space && !Game::Instance()->getSeleccionada()){
                             int idCancion = RenderManager::Instance(1)->getMotor()->crearAudio("assets/Music/end.wav", 100);
    RenderManager::Instance(1)->getMotor()->play(idCancion);
                            nexTurn(turno);
                            cambioTurno(meToca);
                            Tablero::Instance()->setTurno(meToca);
                            cout<<"he entrado"<<meToca<<std::endl;
                             cout<<"he entrado"<<turno<<std::endl;
                             
                             if(meToca==true){
                                 int mana_aux = Tablero::Instance()->getPlayer2()->getMana();
                                 mana_aux++;
                                 Tablero::Instance()->getPlayer2()->ResetStats();
                                 Tablero::Instance()->getPlayer2()->setMana(mana_aux);
                                 Tablero::Instance()->getPlayer2()->setManaRest(mana_aux);
                                 cout<< "Mana total:"<<Tablero::Instance()->getPlayer2()->getMana()<<endl;
                                 cout<<"Mana restante:"<<Tablero::Instance()->getPlayer2()->getManaRest()<<endl;
                                 Tablero::Instance()->getPlayer2()->Robar();
                             }
                            
                             /*if(meToca==false){
                                 srand(time(NULL));
                                 //preguntar naru tamaños
                                 int eX = rand()% 600 + 800;
                                 int eY = rand()% 100 + 500;
                                 //eX=1;
                                 eX = (eX-100)/50;
                                 eY = (eY-80)/50;
                                 
                                  
                                  if(tablero->addUnit(eX,eY,inv,2)){
                                  //cartaseleccionada=false;
                  vector<Invocacion*>::iterator it3;
                 //int i=0;
                     nexTurn(turno);
                            cambioTurno(meToca);
           
            }
                                  else {
                                     nexTurn(turno);
                            cambioTurno(meToca);
                                  }
                             }
                            }
                            else{
                            
                            }*/
                        
                        }

                    case sf::Event::MouseButtonPressed:
                        if(meToca==true){
                        if(evento.mouseButton.button==sf::Mouse::Left){
                            coord = sf::Mouse::getPosition(window);
                            
                            presionado=true;
                            std::cout << "coordx: " << coord.x << std::endl;
                            std::cout << "coordy: " << coord.y << std::endl;
                                          
                            mano.x = (coord.x-150)/100;
                            mano.y = (coord.y-480)/146;
                            
                            campo.x = (coord.x-100)/50;
                            campo.y = (coord.y-80)/50;
                            
                        }
                       }
                }
    }
}
    int InputManager::PulsaTecla() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            std::cout<<"entra"<<std::endl;
            return 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            return 2;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            return 3;
        }
        return -1;
    }
    bool InputManager::PulsaEscape() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            return true;
        }
        return false;
    }
void FachadaInput::turnoIA(bool cambio){
                            
                             if(meToca==false){
                                 int mana_aux = Tablero::Instance()->getPlayer2()->getMana();
                                 mana_aux++;
                                 Tablero::Instance()->getPlayer2()->ResetStats();
                                 Tablero::Instance()->getPlayer2()->setMana(mana_aux);
                                 Tablero::Instance()->getPlayer2()->setManaRest(mana_aux);
                                 cout<< "Mana total:"<<Tablero::Instance()->getPlayer2()->getMana()<<endl;
                                 cout<<"Mana restante:"<<Tablero::Instance()->getPlayer2()->getManaRest()<<endl;
                                 Tablero::Instance()->getPlayer2()->Robar();
                             }
                             nexTurn(turno);
                            cambioTurno(meToca);
                            Tablero::Instance()->setTurno(meToca);
                            cout<<"he entrado"<<meToca<<std::endl;
                             cout<<"he entrado"<<turno<<std::endl;
                             
                            
}

