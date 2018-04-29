#include "Tablero.h"
#include "RenderManager.h"
#include <string>
//SINGLETON

Tablero* Tablero::pinstance = 0;
    
Tablero* Tablero::Instance(){
    if(pinstance==0){
        pinstance = new Tablero;
    }
    return pinstance;
}

Tablero::Tablero(){
    
    //filling board matrix with free positions
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            board[i][j].free=true;
            board[i][j].coordX=i;
            board[i][j].coordY=j;
        }
    }
    
    //Variables del mapa
    offsetX = 100;
    offsetY = 80;
    sizeX   = 50;
    sizeY   = 50;
    
    //Instanciando jugadores
    player1 = new Player(1);
    player2 = new Player(2);
    
    //Variables de sprite
    spriteSize = 0.9;
    
   /*0*/ idrojo = RenderManager::Instance(1)->getMotor()->crearSprite("assets/Sprites/bloque2.png"); //bloque rojo
   /*1*/ idverde = RenderManager::Instance(1)->getMotor()->crearSprite("assets/Sprites/bloque3.png"); //bloque verde
   /*2*/idazul = RenderManager::Instance(1)->getMotor()->crearSprite("assets/Sprites/150px-SokobanWallDepictionDrawing.png"); //bloque azul
    idvidaco = RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/vida.png"); //vida corazon
    idvidacu = RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/life.png"); //vida cuadradito
    fuente = RenderManager::Instance(1)->getMotor()->crearTexto("assets/Fonts/FreeMono.ttf"); //fuente
    fuentemana = RenderManager::Instance(1)->getMotor()->crearTexto("assets/Fonts/FreeMono.ttf"); //fuente
    manarest = RenderManager::Instance(1)->getMotor()->crearTexto("assets/Fonts/FreeMono.ttf");
    barra = RenderManager::Instance(1)->getMotor()->crearTexto("assets/Fonts/FreeMono.ttf");
    mana = RenderManager::Instance(1)->getMotor()->crearTexto("assets/Fonts/FreeMono.ttf");

    retrato1 = RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/retrato1.png");
    retrato2 = RenderManager::Instance(1)->getMotor()->crearSprite("assets/HUD/retrato2.png");
    
    idle = RenderManager::Instance(1)->getMotor()->crearAnimacion("assets/Sprites/dolorArterial.png",14,1,0.001f,14,1);
 
    addUnit(player1->getUnit()->getX(),player1->getUnit()->getY(),player1->getUnit(),player1->getUnit()->getComandante());
    cout<<"X del 2: "<<player2->getUnit()->getX()<<"Y del 2: "<<player1->getUnit()->getY()<<endl;
    addUnit(player2->getUnit()->getX(),player2->getUnit()->getY(),player2->getUnit(),player2->getUnit()->getComandante());
    //addUnit(player2->getUnit()->getX(),player2->getUnit()->getY(),player2->getUnit(),player2->getUnit()->getComandante());
    
}

Tablero *p1 = Tablero::Instance();
Tablero *p2 = p1->Instance();
Tablero &ref = * Tablero::Instance();

void Tablero::ReiniciarAdy(){
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            if(board[i][j].alcanzable==1){
                board[i][j].alcanzable=0;
            }
        }
    }
}



void Tablero::Adyacentes(int posx, int posy){
bool entrado=false;

//esquina superior izq -- iluminar
if(posx==0 && posy==9 && !entrado){
    board[posx+1][posy].alcanzable=1;
    board[posx][posy+1].alcanzable=1;
    entrado=true;
}
//esquina superior dcha -- iluminar
if(posy==0 && posx==11 && !entrado){
    board[posx-1][posy].alcanzable=1;
    board[posx][posy+1].alcanzable=1;
    entrado=true;
}
//esquina inferior izq -- iluminar
if(posx==0 && posy==7 && !entrado){
    board[posx+1][posy].alcanzable=1;
    board[posx][posy-1].alcanzable=1;
    entrado=true;
}
//esquina inferior dcha -- iluminar
if(posx==11 && posy==7 && !entrado){
    board[posx-1][posy].alcanzable=1;
    board[posx][posy-1].alcanzable=1;
    entrado=true;
}
//arriba -- iluminar
if(posy==0 && (posx>=0 && posx<12) && !entrado){
    board[posx-1][posy].alcanzable=1;
    board[posx+1][posy].alcanzable=1;
    board[posx][posy+1].alcanzable=1;
    entrado=true;
}
//abajo -- iluminar
if((posx>=0 && posx<12) && posy==7 && !entrado){
    board[posx-1][posy].alcanzable=1;
    board[posx+1][posy].alcanzable=1;
    board[posx][posy-1].alcanzable=1;
    entrado=true;
}
//izq -- iluminar
if(posx==0 && (posy>=0 && posy<8) && !entrado){
    board[posx+1][posy].alcanzable=1;
    board[posx][posy+1].alcanzable=1;
    board[posx][posy-1].alcanzable=1;
    entrado=true;
}
//dcha -- iluminar
if(posx==11 && (posy>=0 && posy<8) && !entrado){
    board[posx-1][posy].alcanzable=1;
    board[posx][posy+1].alcanzable=1;
    board[posx][posy-1].alcanzable=1;
    entrado=true;
}
//centro -- iluminar
if((posx>0 && posx<11)&& (posy>0 && posy<7) && !entrado){
    board[posx-1][posy].alcanzable=1;
    board[posx+1][posy].alcanzable=1;
    board[posx][posy-1].alcanzable=1;
    board[posx][posy+1].alcanzable=1;
    entrado=true;
}
}

bool Tablero::addUnit(int posx, int posy, Invocacion* unit, int spawn){
   if(player1->getManaRest()>=unit->getCoste()){
         int mana1 = player1->getManaRest();
         int rest = mana1-unit->getCoste();
         player1->setManaRest(rest);
         cout<<"Me queda este mana:"<<player1->getManaRest()<<endl;
    
    if(spawn==1){
        //unidad2=player1->getMonstruo(unit,2);
        if(((posx>=0 && posx<3)&& (posy>=0 && posy<10))&& isFree(posx,posy)){
            board[posx][posy].free=false;
            board[posx][posy].coordX=posx;
            board[posx][posy].coordY=posy;
            unit->setPosicion(posx,posy);
            player1->RellenarJugadas(unit);
            player1->eliminarMano(unit);
           //  board[posx][posy].unit=unit;
           // player1->eliminarMano(unit); Comprobar bien cuando borramos

            //cambiar esto
            
            /*Arreglar la fila puto 1 de mierda que hay bug y me cago en la ostia
             y en la madre que lo pario me muero, controlar que no se meta mas uno, comprobarlo*/
            /*Arreglado hijo de puta*/
            return true; 
        }
    }
    if(spawn==2){
        //Ponerlo para la IA
        if(((posx>WIDTH-4 && posx<WIDTH-1)&& (posy>=0 && posy<HEIGHT-1))&& isFree(posx,posy)){
          board[posx][posy].free=false;
          //board[posx][posy].unit=unit;
          board[posx][posy].coordX=posx;
          board[posx][posy].coordY=posy;
          unit->setPosicion(posx,posy);
          player2->RellenarJugadas(unit);
            player2->eliminarMano(unit);
         // if(player1->RellenarJugadas(invoc)){
              /*Borrar unidad de la mano
               y setear antes su posicion*/
          }
          return true;  
        }
   }
    return false;
    }
    

                                                              
bool Tablero::moveToPos(int fromx,int fromy,int gox, int goy, Invocacion* unit){                                                              
   if(turno){
        if(((gox<12 && gox>=0) && (goy<8 && goy>=0)) && board[gox][goy].free==true && board[gox][goy].alcanzable==1){
          if(unit->getMovimiento()>0){
              cout<<"entro con mov: "<<unit->getMovimiento()<<endl;
            unit->setPosicion(gox,goy);
           // cout<<"calculico o no x : "<<gox<<endl;
           // cout<<"calculico o no y : "<<goy<<endl;
           // board[gox][goy].unit=unit;
            unit->setMovimiento(unit->getMovimiento()-1);
             cout<<"he restado mi mov: "<<unit->getMovimiento()<<endl;

            setFree(fromx,fromy,true);
            return true;
            }
        }else{
             return false;
            }  
    }
   else{
       vector<Invocacion*>::iterator it3;
       vector<Invocacion*>::iterator it2;
       int i=0;
       int j=0;
       for(it3=player2->getJugadas().begin();it3!=player2->getJugadas().end();++it3){
           for(it2=player1->getJugadas().begin();it3!=player1->getJugadas().end();++it3){
               
           
       }         
   }
}
}
bool Tablero::moveToPosIA(){
    vector<Invocacion*>::iterator it3;
    int i = 0;
    int hamuerto=0;
    bool atacado = false;
    bool retorno = false;
    int randomx=-1;
    int randomy=-1;
    int xcom=player1->getUnit()->getX();
    int ycom=player1->getUnit()->getY();
    int controlx;//Para saber la diferencia entre la x de la ia y la x del comandante
                 //si es negativo la diferencia sumaremos a la de la ia si es positivo restaremos DAAAAMN
    int controly;
    int xia;
    int yia;
    if(player2->getJugadas().size()>0){
        for(it3=player2->getJugadas().begin();it3!=player2->getJugadas().end();++it3){
            if(player2->getJugadas().at(i)!=NULL&&player2->getJugadas().at(i)->getCom()==true){
                while(player2->getJugadas().at(i)->getMovimientoF()>0){
                    srand (time(NULL));
                    randomx= rand() % 3 -1;
                    randomy= rand() % 3 -1;
                    if(player2->getJugadas().at(i)->getMovimientoF()>0&&!isFree(player2->getJugadas().at(i)->getX()+1,player2->getJugadas().at(i)->getY())){
                        //ataque
                       hamuerto= atackToPosIA(player2->getJugadas().at(i), player1->JugadaEn(player2->getJugadas().at(i)->getX()+1,player2->getJugadas().at(i)->getY()));
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        atacado=true;
                        retorno = true;
                    }
                    if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&!isFree(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY()+1)){
                        //ataque
                        hamuerto= atackToPosIA(player2->getJugadas().at(i), player1->JugadaEn(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY()+1));
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        atacado=true;
                        retorno = true;
                    }
                    if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&!isFree(player2->getJugadas().at(i)->getX()-1,player2->getJugadas().at(i)->getY())){
                        //ataque
                        hamuerto= atackToPosIA(player2->getJugadas().at(i), player1->JugadaEn(player2->getJugadas().at(i)->getX()-1,player2->getJugadas().at(i)->getY()));
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        atacado=true;
                        retorno = true;
                    }
                    if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&!isFree(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY()-1)){
                        //ataque
                        hamuerto= atackToPosIA(player2->getJugadas().at(i), player1->JugadaEn(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY()-1));
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        atacado=true;
                        retorno = true;
                    }
                    if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&atacado==false){
                        //movimiento
                        setFree(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY(),true);
                        player2->getJugadas().at(i)->setPosicion(player2->getJugadas().at(i)->getX()+randomx,player2->getJugadas().at(i)->getY()+randomy);
                        setFree(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY(),false);
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        retorno = true;
                    }
                    atacado=false;
                }
            }
            else if(hamuerto==0&&player2->getJugadas().at(i)!=NULL){
                
                while(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0){
                    int xia=player2->getJugadas().at(i)->getX();
                    int yia=player2->getJugadas().at(i)->getY();
                    //SI HAY ALGUN BICHO LE ATACO TO GUAY
                     if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&!isFree(player2->getJugadas().at(i)->getX()+1,player2->getJugadas().at(i)->getY())){
                        //ataque
                         hamuerto= atackToPosIA(player2->getJugadas().at(i), player1->JugadaEn(player2->getJugadas().at(i)->getX()+1,player2->getJugadas().at(i)->getY()));
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        atacado=true;
                        retorno = true;
                    }
                    if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&!isFree(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY()+1)){
                        //ataque
                        hamuerto= atackToPosIA(player2->getJugadas().at(i), player1->JugadaEn(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY()+1));
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        atacado=true;
                        retorno = true;
                    }
                    if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&!isFree(player2->getJugadas().at(i)->getX()-1,player2->getJugadas().at(i)->getY())){
                        //ataque
                        hamuerto= atackToPosIA(player2->getJugadas().at(i), player1->JugadaEn(player2->getJugadas().at(i)->getX()-1,player2->getJugadas().at(i)->getY()));
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        atacado=true;
                        retorno = true;
                    }
                    if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&!isFree(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY()-1)){
                        //ataque
                        hamuerto= atackToPosIA(player2->getJugadas().at(i), player1->JugadaEn(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY()-1));
                        player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                        atacado=true;
                        retorno = true;
                    }
                     //ME MUEVO TO CHUNGOTE
                      if(hamuerto==0&&player2->getJugadas().at(i)->getMovimientoF()>0&&atacado==false){
                          controlx=player2->getJugadas().at(i)->getX()-xcom;
                          controly=player2->getJugadas().at(i)->getY()-ycom;
                          if(controlx>0){
                              xia=xia-1;
                              controlx=controlx-1;
                          }
                          if(controlx<0){
                              xia=xia+1;
                              controlx=controlx+1;
                          }
                          if(controly>0){
                              yia=yia-1;
                              controly=controly-1;
                          }
                          if(controly<0){
                              yia=yia+1;
                              controly=controly+1;
                          }
                          
                          setFree(player2->getJugadas().at(i)->getX(),player2->getJugadas().at(i)->getY(),true);
                          player2->getJugadas().at(i)->setPosicion(xia,yia);
                          setFree(xia,yia,false);
                          player2->getJugadas().at(i)->setMovimiento(player2->getJugadas().at(i)->getMovimientoF()-1);
                          retorno = true;
                      }
                    atacado=false;
                     
                }//cierre while
                
            }
            hamuerto=0;
            i++;
        }//cierre for
    }
    return retorno;
}
bool Tablero::removeUnit(int posx, int posy, Invocacion* unit){
    //board[posx][posy].unit=NULL;
    setFree(posx,posy,true);
    return true;
}
void Tablero::resetMap(){
   for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            board[i][j].free=true;
            board[i][j].unit=NULL;
        }
    }         
}

void Tablero::drawAdyacentes(){
    for(int i=0;i<WIDTH;i++){//estos for habra que cambiarlo por unidad.movimiento y dos contadores x,y que sumados sean <= que su movimiento
        for(int j=0;j<HEIGHT;j++){
            if(board[i][j].alcanzable==1){;
                if(board[i][j].free){
                    RenderManager::Instance(1)->getMotor()->dibujar(idverde,(i*50)+100,(j*50)+80,0.3,*window);
                }
                else{
                    RenderManager::Instance(1)->getMotor()->dibujar(idrojo,(i*50)+100,(j*50)+80,0.3,*window);   
                }
              }
            }
        }
    }


void Tablero::drawMap(){
    
   for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            if(i<WIDTH/2){
                if(board[i][j].free){
                  /*2*/  RenderManager::Instance(1)->getMotor()->dibujar(idazul,(i*50)+100,(j*50)+80,0.3,*window);
                }else{
                    RenderManager::Instance(1)->getMotor()->dibujar(idazul,(i*50)+100,(j*50)+80,0.3,*window);  
                }
            }else{
                if(board[i][j].free){
                /*0*/ RenderManager::Instance(1)->getMotor()->dibujar(idrojo,(i*50)+100,(j*50)+80,0.3,*window);
                }else{
                 RenderManager::Instance(1)->getMotor()->dibujar(idrojo,(i*50)+100,(j*50)+80,0.3,*window);   
                }
            }
        }
    }
}

Invocacion* Tablero::esCarta(int posx, int posy){
  
    //Invocacion* mano2 = new Invocacion();
    vector<Invocacion*>::iterator it3;
                 int i=0;
                 srand(time(NULL));
                 int aleatoria =rand()%4;
    if(turno==true){
        for(it3=player1->getMano().begin();it3!=player1->getMano().end();++it3){
            if(i<player1->getMano().size()){
                if(player1->getMano().at(i)->getJugar()==posx){ //si estoy clickando una carta
            //std::cout << "EXISTO ¿? : " << mano2->getNombre()<< std::endl;
            
                return player1->getMano().at(i);
                }
            i++;
            }
        }
     }
    else{
        i=0;
        //for(it3=player2->getMano().begin();it3!=player2->getMano().end();++it3){
            if(aleatoria<player2->getMano().size()){
                return player2->getMano().at(aleatoria);
            }
           // i++;
        
    }
                 
    return NULL;
}

bool Tablero::isFree(int posx, int posy){
    return board[posx][posy].free;
}

void Tablero::Mostrar_mano(int id){
    std::vector<Invocacion*> array = player1->getMano();
    if(!array.empty()){
        for(unsigned int i = 0; i < array.size(); i++){
            if(array[i]->getIdCarta()!=id){
            
                //Se calcula su posición en el mapa
                float calculox =(i*100)+150;
                float calculoy = array[i]->getY()*480;

                //Se coloca y escala
                array[i]->setPosition(calculox,calculoy);
                array[i]->setScale(spriteSize,spriteSize);

                //Se pinta la carta correspondiente a cada id
                RenderManager::Instance(1)->getMotor()->dibujar(array[i]->getIdCarta(),calculox,480,spriteSize,*window);
            }
        }
    }
    /*
    vector<Invocacion*>::iterator it3;
    int i=0;
    for(it3=player1->getMano().begin();it3!=player1->getMano().end();++it3){
 
        
        
        
        if(i<player1->getMano().size() && player1->getMano().at(i)->getNombre()=="Zoogx"){
             if(!Zoogxredim.loadFromFile("assets/Sprites/Zoogxredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        } 
        carta.setTexture(Zoogxredim);
        //mano[i].setCarta(carta);
        carta.setPosition((i*100)+150,480);
        window.draw(carta);
        //mano[i].setJugar(i);
        }
        if(i<player1->getMano().size() && player1->getMano().at(i)->getNombre()=="Yigx"){
            if(!Yigxredim.loadFromFile("assets/Sprites/Yigxredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        } 
        carta.setTexture(Yigxredim);
        //mano[i].setCarta(carta);
        carta.setPosition((i*100)+150,480);
        window.draw(carta);
        //mano[i].setJugar(i);
        }
        if(i<player1->getMano().size() && player1->getMano().at(i)->getNombre()=="Cthughax"){
            if(!Cthughaxredim.loadFromFile("assets/Sprites/Cthughaxredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        } 
        carta.setTexture(Cthughaxredim);
        if(!Gugoxredim.loadFromFile("assets/Sprites/Gugoxredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        } 
        //mano[i].setCarta(carta);
        carta.setPosition((i*100)+150,480);
        window.draw(carta);
        //mano[i].setJugar(i);
        }
        if(i<player1->getMano().size() && player1->getMano().at(i)->getNombre()=="Gugox"){
        carta.setTexture(Gugoxredim);
        //mano[i].setCarta(carta);
        carta.setPosition((i*100)+150,480);
        window.draw(carta);
        //mano[i].setJugar(i);
        }
        if(i<player1->getMano().size() && player1->getMano().at(i)->getNombre()=="Bokrugs"){
            if(!Bokrugsredim.loadFromFile("assets/Sprites/Bokrugsredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        } 
        carta.setTexture(Bokrugsredim);
        //mano[i].setCarta(carta);
        carta.setPosition((i*100)+150,480);
        window.draw(carta);
        //mano[i].setJugar(i);
        }
        i++;
    }
    
        */
}

void Tablero::drawUnit(){
    //Variables a usar
    vector<Invocacion*> jugadas1 = player1->getJugadas();
    vector<Invocacion*> jugadas2 = player2->getJugadas();
     
    drawInvocaciones(jugadas1);
    drawInvocaciones(jugadas2);
}

void Tablero::drawInvocaciones(vector<Invocacion*> array)
{
    //Recorremos el array si no está vacío
    if(!array.empty()){
        for(unsigned int i = 0; i < array.size(); i++){
            if(array[i]->getNombre()!=""){
                
                //Se calcula su posición en el mapa
                float calculox = array[i]->getX()*sizeX+68;
                float calculoy = array[i]->getY()*sizeY+20;
                
                //Se coloca y escala
                array[i]->setPosition(calculox,calculoy);
                array[i]->setScale(spriteSize,spriteSize);
                
                //Se pinta la animación correspondiente a cada id
                RenderManager::Instance(1)->getMotor()->updateAnimacion(array[i]->getId(),0,0.002f/*RenderManager::Instance(1)->getMotor()->getClock().getElapsedTime().asSeconds()*/);
                RenderManager::Instance(1)->getMotor()->dibujarAnimacion(array[i]->getId(),calculox,calculoy,spriteSize,window); 
            }
        }
    }
}
     
    //TESTEO
    /*int pos=-1;
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            //liberar codigo
            if(player1->JugadaEn(i,j)->getNombre()!= ""){
                pos=player1->damePosicion(i,j);//no es un for, entonces e queda apuntando en el ultimo y no los reinicia para mirar los anteiores
                pos=pos-1;
                if(pos!=-1 && (pos < player1->getJugadas().size())){
                    float calculox =(i*50)+100;
                    float calculoy = (j*50)+80;
                    float vectrx= 0.3;
                    std::cout<<"GetUnico : "<<player1->getJugadas().at(pos)->GetUnico()<<std::endl;
                    std::cout<<"GetNombre : "<<player1->getJugadas().at(pos)->getNombre()<<std::endl;
                    //std::cout<<"POS: "<<pos<<" Quien soy : "<<player1->getJugadas().at(pos)->getNombre()<<std::endl;
                    player1->getJugadas().at(pos)->setPosition(calculox,calculoy);
                    player1->getJugadas().at(pos)->setScale(vectrx,vectrx);
                    window.draw(player1->getJugadas().at(pos)->getSprite());
                }
               // window.draw( player1->getMano().at(i)->getSpriteM());
            }
                if(player1->JugadaEn(i,j)->getNombre()=="Zoogx"){
                board[i][j].sprite.setTexture(Zoogx);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f));
                window.draw(board[i][j].sprite);
                }
                if(player1->JugadaEn(i,j)->getNombre()=="Cthughax"){
                board[i][j].sprite.setTexture(Cthughax);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f));
                window.draw(board[i][j].sprite);
                }
                
                if(player1->JugadaEn(i,j)->getNombre()=="Gugox"){
                board[i][j].sprite.setTexture(Gugox);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f));
                window.draw(board[i][j].sprite);
                }
                
                if(player1->JugadaEn(i,j)->getNombre()=="Yigx"){
                board[i][j].sprite.setTexture(Yigx);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f));
                window.draw(board[i][j].sprite);
                }
                
                if(player1->JugadaEn(i,j)->getNombre()=="Bokrugs"){
                board[i][j].sprite.setTexture(Bokrugs);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f));
                window.draw(board[i][j].sprite);
                }
        }
    }*/

void Tablero::drawLife(int commander){
    if(commander==1){
        RenderManager::Instance(1)->getMotor()->dibujar(idvidacu,100,5,0.5,*window);
                
        for(int i=0;i<player1->getLife();i++){
            RenderManager::Instance(1)->getMotor()->dibujar(idvidaco,(i*2)+135,10,2,*window);
        }
    }else{
        RenderManager::Instance(1)->getMotor()->dibujar(idvidacu,670,5,0.5,*window);
        
        for(int i=0;i<player2->getLife();i++){
            RenderManager::Instance(1)->getMotor()->dibujar(idvidaco,(i*2)+455,10,2,*window);
        }
    }
}

void Tablero::drawLifeNumb(int commander){
    if(commander==1){
        
        int life = player1->getLife();
            std::stringstream ss;
            ss << life;
            RenderManager::Instance(1)->getMotor()->escribir(ss.str().c_str(),fuente,350,1,0.7, *window);
    }else{

        int life = player2->getLife();
            std::stringstream ss;
            ss << life;
            RenderManager::Instance(1)->getMotor()->escribir(ss.str().c_str(),fuente,412,1,0.7, *window);
    }
}

void Tablero::drawManaNumb(int commander){
    if(commander==1){

        int mana = player1->getMana();
            std::stringstream ss;
            ss << mana;
            RenderManager::Instance(1)->getMotor()->escribir(ss.str().c_str(),fuentemana,193,37,0.8, *window);
    }else{

        int mana = player2->getMana();
            std::stringstream ss;
            ss << mana;
            RenderManager::Instance(1)->getMotor()->escribir(ss.str().c_str(),fuentemana,620,37,0.8, *window);
    }
}

void Tablero::drawManaRest(int commander){
    if(commander==1){
 
        int manarest = player1->getManaRest();
                std::stringstream ss;
                ss << manarest;
                RenderManager::Instance(1)->getMotor()->escribir(ss.str().c_str(),manarest,158,37,0.8,*window);
    }else{
  
        int manarest = player2->getManaRest();
                std::stringstream ss;
                ss << manarest;
                RenderManager::Instance(1)->getMotor()->escribir(ss.str().c_str(),manarest,585,37,0.8,*window);
    }
}

void Tablero::drawBarra(int commander){
    if(commander==1){
       RenderManager::Instance(1)->getMotor()->escribir("/",barra,182,37,0.8,*window);
    }else{
}
       RenderManager::Instance(1)->getMotor()->escribir("/",manarest,609,37,0.8,*window);
    }

void Tablero::drawMana(int commander){
    /*if(commander==1){
        int mana = player1->getMana();
        coco.setFillColor(sf::Color::Blue);
        coco.setRadius(mana*2);
        coco.setPosition(110,37);
       
        window.draw(coco);
    }else{
        int mana = player2->getMana();
        coco.setFillColor(sf::Color::Blue);
        coco.setRadius(mana*2);
        coco.setPosition(655,37);

        window.draw(coco);
    }*/
}

void Tablero::drawRetrato(int commander){
    if(commander==1){
        RenderManager::Instance(1)->getMotor()->dibujar(retrato1,0,0,1,*window);
    }else{
        RenderManager::Instance(1)->getMotor()->dibujar(retrato2,700,0,1,*window);
    }
}

int Tablero::getAlcanzable(int posx, int posy){
    return board[posx][posy].alcanzable;
}
void Tablero::setFree(int posx,int posy,bool set){
    board[posx][posy].free=set;
}
int Tablero::atackToPosIA(Invocacion* ia, Invocacion* humano){
    int retorno=0;
    bool hum=false;
    bool iaB=false;
    ia->setVida(ia->getVida()-humano->getAtaque());
    humano->setVida(humano->getVida()-ia->getAtaque());
    if(ia->getCom()==true){
        player2->setLife(ia->getVida());
        if(player2->getLife()<=0){
            iaB=true;
        }
    }
    else if(ia->getVida()<=0){
        setFree(ia->getX(),ia->getY(), true);
        player2->eliminarJugadas(ia);
        retorno=7;//muerte bicho
    }
    if(humano->getCom()==true){
        player1->setLife(ia->getVida());
        if(player1->getLife()<=0){
            hum=true;
        }
        
    }
    else if(humano->getVida()<=0){
        setFree(humano->getX(),humano->getY(), true);
        player1->eliminarJugadas(humano);       
    }
    if(iaB==true&&hum==true){
        retorno=-3;
    }
    if(iaB==true&&hum==false){
        retorno=-1;
    }
    if(iaB==false&&hum==true){
        retorno=-2;
    }
    return retorno;
}
int Tablero::atackToPos(int fromx, int fromy,int gox, int goy){
    int retorno=0;
    Invocacion* unidad = new Invocacion();
    Invocacion* unidad2 =new  Invocacion();
    unidad=player1->JugadaEn(fromx,fromy);//el que pega
    unidad2=player1->JugadaEn(gox,goy);
    unidad2->setVida(unidad2->getVida()-unidad->getAtaque());
    unidad->setVida(unidad->getVida()-unidad2->getAtaque());
    cout<<"Me llamo: "<<unidad2->getNombre()<<"vida al que atacan: "<<unidad2->getVida()<<endl;
     cout<<"Me llamo: "<<unidad->getNombre()<<"vida del que ataca : "<<unidad->getVida()<<endl;
    //hacia los dos lados
     if(unidad2->getCom()==true||unidad->getCom()==false){
         if(unidad2->getCom()==true){
             player1->setLife(unidad2->getVida());
         }
         if(unidad->getCom()==true){
             player1->setLife(unidad->getVida());
         }
     }
    if(unidad2->getCom()==false&&unidad2->getVida()<=0){
        // cout<<"me voy a morir: "<<unidad2->getVida()<<endl;
        setFree(gox,goy,true);
        player1->eliminarJugadas(unidad2);
        
       //removeUnit(gox,goy,unidad2);
       retorno=1;
    }
    if(unidad->getCom()==false&&unidad->getVida()<=0){ 
        // cout<<"me voy a morir 2: "<<unidad->getVida()<<endl;
        setFree(fromx,fromy,true);
        player1->eliminarJugadas(unidad);
       
        //removeUnit(fromx,fromy,unidad);
        retorno =1;
    }
   
         if(unidad2->getCom()==true && unidad2->getVida()<=0){
             retorno=-1; //GANADA
        }
         if(unidad->getCom()==true && unidad->getVida()<=0){
             retorno=-2; //PERDIDA
         }
         if((unidad2->getCom()==true&&unidad->getCom()==true) && (unidad2->getVida()<=0 && unidad->getVida()<=0)){
             retorno=-3; //EMPATE
        }
     player1->JugadaEn(fromx,fromy)->setMovimiento(player1->JugadaEn(fromx,fromy)->getMovimiento()-1);
     return retorno;
}
