#include "Tablero.h"

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
    
    player1 = new Player(1);
    player2 = new Player(2);
    
    
    if(!texturabloquerojo.loadFromFile("assets/Sprites/bloque2.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!texturabloqueverde.loadFromFile("assets/Sprites/bloque3.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    drawRetrato();
    
    /*if(!Zoogx.loadFromFile("assets/Sprites/Zoogx.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!Cthughax.loadFromFile("assets/Sprites/Cthughax.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!Gugox.loadFromFile("assets/Sprites/Gugox.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!Yigx.loadFromFile("assets/Sprites/Yigx.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!Bokrugs.loadFromFile("assets/Sprites/Bokrugs.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }*/
    /*if(!Zoogxredim.loadFromFile("assets/Sprites/Zoogxredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!Cthughaxredim.loadFromFile("assets/Sprites/Cthughaxredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!Gugoxredim.loadFromFile("assets/Sprites/Gugoxredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!Yigxredim.loadFromFile("assets/Sprites/Yigxredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    if(!Bokrugsredim.loadFromFile("assets/Sprites/Bokrugsredim.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
    }*/
    board[0][3].free=false; //commander 1
    board[0][3].coordX=0;
    board[0][3].coordY=3;
    board[0][3].spawn1=true;
    board[0][3].spawn2=false;
    board[0][3].unit=player1->getUnit();
            
    board[11][0].free=false; //commander 2
    board[11][0].coordX=11;
    board[11][0].coordY=3;
    board[11][0].spawn1=false;
    board[11][0].spawn2=true;
    board[11][0].unit=player2->getUnit();
}

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
    //Mover este calculo a una funcion para que no se repita
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
          Invocacion invoc =  Invocacion();
          invoc=unit[0];
         // if(player1->RellenarJugadas(invoc)){
              /*Borrar unidad de la mano
               y setear antes su posicion*/
          }
          return true;  
        }
    return false;
    }
    

                                                              
bool Tablero::moveToPos(int fromx,int fromy,int gox, int goy, Invocacion* unit){                                                              

   if(((gox<12 && gox>=0) && (goy<8 && goy>=0)) && board[gox][goy].free==true && board[gox][goy].alcanzable==1){
       unit->setPosicion(gox,goy);
       //board[gox][goy].unit=unit;
       setFree(fromx,fromy,true);
       return true;
   }else{
       return false;
   }        
}    
bool Tablero::removeUnit(int posx, int posy, Invocacion* unit){
    board[posx][posy].unit=NULL;
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

void Tablero::drawAdyacentes(sf::RenderWindow& window){
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            if(board[i][j].alcanzable==1){
               std::cout << "i: " << i << std::endl;
                std::cout << "j: " << i << std::endl;
                if(board[i][j].free){
                board[i][j].sprite.setTexture(texturabloqueverde);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
                window.draw(board[i][j].sprite);
                }
                else{
                board[i][j].sprite.setTexture(texturabloquerojo);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
                window.draw(board[i][j].sprite);   
                }
                }
            }
        }
    }


void Tablero::drawMap(sf::RenderWindow& window){
        
    if(!texturabloqueazul.loadFromFile("assets/Sprites/150px-SokobanWallDepictionDrawing.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
   for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            if(i<WIDTH/2){
                if(board[i][j].free){
                    board[i][j].sprite.setTexture(texturabloqueazul);
                }else{
                 board[i][j].sprite.setTexture(texturabloqueazul);   
                }
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
            }else{
                if(board[i][j].free){
                board[i][j].sprite.setTexture(texturabloquerojo);
                }else{
                 board[i][j].sprite.setTexture(texturabloquerojo);   
                }
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
            }
    
          window.draw(board[i][j].sprite);
        }
    }
}

Invocacion* Tablero::esCarta(int posx, int posy){
  
    //Invocacion* mano2 = new Invocacion();
    vector<Invocacion*>::iterator it3;
                 int i=0;
    for(it3=player1->getMano().begin();it3!=player1->getMano().end();++it3){
        if(i<player1->getMano().size()){
        if(player1->getMano().at(i)->getJugar()==posx){ //si estoy clickando una carta
           // std::cout << "EXISTO ¿? : " << mano2->getNombre()<< std::endl;
            
            return player1->getMano().at(i);
        }
        i++;
    }
    }
    return NULL;
}

bool Tablero::isFree(int posx, int posy){
    return board[posx][posy].free;
}

/*DIBUJADO DE PLAYER*/
void Tablero::Mostrar_mano(sf::RenderWindow& window){
    int i=0;
    vector<Invocacion*>::iterator it3;
    for(it3=player1->getMano().begin();it3!=player1->getMano().end();++it3){
        //std::cout<< "entro posicion: "<<((i*100)+150)<<std::endl;
        if(i<player1->getMano().size()){
        //player1->getMano().at(i)->getSpriteM().setPosition((i*100)+150,480);
        window.draw( player1->getMano().at(i)->getSpriteM());
        }
        i++;
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
void Tablero::drawUnit(sf::RenderWindow& window){
     vector<Invocacion*>::iterator it3;
     int i=0;
     float vectrx= 0.3;
     for(it3=player1->getJugadas().begin();it3!=player1->getJugadas().end();++it3){
         if(i<player1->getJugadas().size() && player1->getJugadas().at(i)->getNombre()!=""){
             float calculox =(player1->getJugadas().at(i)->getX()*50)+100;
             float calculoy = (player1->getJugadas().at(i)->getY()*50)+80;
             /*std::cout<<"entrox : "<<player1->getJugadas().at(i)->getX()<<std::endl;
             std::cout<<"entroy : "<<player1->getJugadas().at(i)->getY()<<std::endl;*/
             player1->getJugadas().at(i)->setPosition(calculox,calculoy);
             player1->getJugadas().at(i)->setScale(vectrx,vectrx);
             window.draw(player1->getJugadas().at(i)->getSprite());
         }
         i++;
     }
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
}
void Tablero::drawLife(int commander, sf::RenderWindow& window){
    if(commander==1){
        if(!texturavida.loadFromFile("assets/HUD/vida.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        if(!texturalife.loadFromFile("assets/HUD/life.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        sprite.setTexture(texturavida);
        sprite2.setTexture(texturalife);
        sprite2.setPosition(100,5);
        sprite2.setScale(0.5,0.5);
        window.draw(sprite2);
                
        for(int i=0;i<player1->getLife();i++){
            sprite.setPosition((i*2)+135,10);
            sprite.setScale(2,2);
            window.draw(sprite);
        }
    }else{
        if(!texturavida.loadFromFile("assets/HUD/vida.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        sprite.setTexture(texturavida);
        sprite2.setTexture(texturalife);
        sprite2.setPosition(670,5);
        sprite2.setScale(0.5,0.5);
        window.draw(sprite2);
        
        for(int i=0;i<player2->getLife();i++){
            sprite.setPosition((i*2)+455,10);
            window.draw(sprite);
        }
    }
}

sf::Text Tablero::drawLifeNumb(int commander){
    if(commander==1){
        if(!font.loadFromFile("assets/Fonts/FreeMono.ttf")){
                std::cout << "Fuente no aplicada" <<std::endl;
            }
        int life = player1->getLife();
            std::stringstream ss;
            ss << life;
            vida.setString(ss.str().c_str());
            vida.setColor(sf::Color::White);
            vida.setFont(font);
            vida.setScale(0.7,0.7);
            vida.setPosition(350,1);
            return vida;
    }else{
        if(!font.loadFromFile("assets/Fonts/FreeMono.ttf")){
                std::cout << "Fuente no aplicada" <<std::endl;
            }
        int life = player2->getLife();
            std::stringstream ss;
            ss << life;
            vida.setString(ss.str().c_str());
            vida.setColor(sf::Color::White);
            vida.setFont(font);
            vida.setScale(0.7,0.7);
            vida.setPosition(412,1);
            return vida;
    }
}

sf::Text Tablero::drawManaNumb(int commander){
    if(commander==1){
        if(!font.loadFromFile("assets/Fonts/FreeMono.ttf")){
                std::cout << "Fuente no aplicada" <<std::endl;
            }
        int mana = player1->getMana();
            std::stringstream ss;
            ss << mana;
            mananumb.setString(ss.str().c_str());
            mananumb.setColor(sf::Color::White);
            mananumb.setFont(font);
            mananumb.setScale(0.8,0.8);
            mananumb.setPosition(193,37);
            return mananumb;
    }else{
        if(!font.loadFromFile("assets/Fonts/FreeMono.ttf")){
                std::cout << "Fuente no aplicada" <<std::endl;
            }
        int mana = player2->getMana();
            std::stringstream ss;
            ss << mana;
            mananumb.setString(ss.str().c_str());
            mananumb.setColor(sf::Color::White);
            mananumb.setFont(font);
            mananumb.setPosition(620,37);
            return mananumb;
    }
}

sf::Text Tablero::drawManaRest(int commander){
    if(commander==1){
        if(!font.loadFromFile("assets/Fonts/FreeMono.ttf")){
                    std::cout << "Fuente no aplicada" <<std::endl;
                }
        int manarest = player1->getManaRest();
                std::stringstream ss;
                ss << manarest;
                manar.setString(ss.str().c_str());
                manar.setColor(sf::Color::White);
                manar.setFont(font);
                manar.setScale(0.8,0.8);
                manar.setPosition(158,37);
                return manar;
    }else{
        if(!font.loadFromFile("assets/Fonts/FreeMono.ttf")){
                    std::cout << "Fuente no aplicada" <<std::endl;
                }
        int manarest = player2->getManaRest();
                std::stringstream ss;
                ss << manarest;
                manar.setString(ss.str().c_str());
                manar.setColor(sf::Color::White);
                manar.setFont(font);
                manar.setPosition(585,37);
                return manar;
    }
}

sf::Text Tablero::drawBarra(int commander){
    if(commander==1){
        if(!font.loadFromFile("assets/Fonts/FreeMono.ttf")){
                        std::cout << "Fuente no aplicada" <<std::endl;
                    }
       barra.setFont(font);
       barra.setPosition(182,37);
       barra.setScale(0.8,0.8);
       barra.setString("/");
       return barra;
    }else{
        if(!font.loadFromFile("assets/Fonts/FreeMono.ttf")){
                        std::cout << "Fuente no aplicada" <<std::endl;
                    }
       barra.setFont(font);
       barra.setPosition(609,37);
       barra.setString("/");
       return barra;
    }
}

void Tablero::drawMana(int commander, sf::RenderWindow& window){
    if(commander==1){
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
    }
}

void Tablero::drawRetrato(int commander, sf::RenderWindow& window){
    if(commander==1){
        window.draw(player1->getRetrato());
    }else{
        window.draw(player2->getRetrato());
    }
}

int Tablero::getAlcanzable(int posx, int posy){
    return board[posx][posy].alcanzable;
}
void Tablero::setFree(int posx,int posy,bool set){
    board[posx][posy].free=set;
}
bool Tablero::atackToPos(int fromx, int fromy,int gox, int goy){
    bool retorno=false;
    Invocacion* unidad = new Invocacion();
    Invocacion* unidad2 =new  Invocacion();
    unidad=player1->JugadaEn(fromx,fromy);//el que pega
    unidad2=player1->JugadaEn(gox,goy);
    unidad2->setVida(unidad2->getVida()-unidad->getAtaque());
    unidad->setVida(unidad->getVida()-unidad2->getAtaque());
    //hacia los dos lados
    if(unidad2->getVida()<=0){

        player1->eliminarJugadas(unidad2);
       removeUnit(gox,goy,unidad2);
       retorno=true;
    }
    if(unidad->getVida()<=0){
        player1->eliminarJugadas(unidad);
        removeUnit(fromx,fromy,unidad);
        retorno =true;
    }
    return retorno;
}