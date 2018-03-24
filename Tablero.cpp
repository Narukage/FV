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
    if(!Zoogx.loadFromFile("assets/Sprites/Zoogx.png")){
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
        }
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
posx = (posx-100)/50;
posy = (posy-80)/50;

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
    //cambiar posx y posy por matx y maty
  /*  Invocacion unidad2=Invocacion();
    Invocacion* retorno= new Invocacion();*/

    if((posx>100 && posx<700)&&(posy>80 && posy<475)){
        posx = (posx-100)/50;
        posy = (posy-80)/50;
    }

    
    if(spawn==1){
        //unidad2=player1->getMonstruo(unit,2);
        if(((posx>=0 && posx<3)&& (posy>=0 && posy<10))&& isFree(posx,posy)){
            board[posx][posy].free=false;
            board[posx][posy].coordX=posx;
            board[posx][posy].coordY=posy;
            unit->setPosicion(posx,posy);
            player1->RellenarJugadas(unit);
             board[posx][posy].unit=unit;
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
          board[posx][posy].unit=unit;
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
    Invocacion jugada = Invocacion();
    gox = (gox-100)/50; //REVISAR URGENTEMENTE//
    goy = (goy-80)/50;  //SOLO TRANSFORMAMOS LOS PARAMENTROS GO, SI TRANSFORMAMOS LOS DE FROM 
                        //FUNCIONA MAL, NO TIENE SENTIDO Y NO SABEMOS PORQUE
   if(((gox<12 && gox>=0) && (goy<8 && goy>=0)) && board[gox][goy].free==true && board[gox][goy].alcanzable==1){
  
   if(((gox<12 && gox>=0) && (goy<8 && goy>=0)) && board[gox][goy].free==true && board[gox][goy].alcanzable==1){
       std::cout <<" Ya noh emo movioh" << std::endl;
       unit->setPosicion(gox,goy);
       board[gox][goy].unit=unit;
       removeUnit(fromx,fromy,unit);
       return true;
   }else{
       std::cout <<"ALGUNA VEZ ENTRAS AQUI??"<<std::endl;
       return false;
   }        
}
}    
bool Tablero::removeUnit(int posx, int posy, Invocacion* unit){
    board[posx][posy].unit=NULL;
    setFree(posx,posy,true);
    return true;
}

Invocacion* Tablero::getUnit(int posx, int posy){//meter cual player es cada 1 eliminar UNIT de tablero
    if(!isFree(posx,posy)){
        //if player es 1 o 2
        Invocacion* recorrer= new Invocacion();
        Invocacion* devolver= new Invocacion();
        posx = (posx-100)/50;
        posy = (posy-80)/50;
        recorrer=player1->getJugadas();
        for(int i=0;i<19;i++){
            if((recorrer[i].getX()==posx)&&(recorrer[i].getY()==posy)){
                devolver=&recorrer[i];
                break;
            }
        }
        return devolver;
    }
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
                if(board[i][j].free){
                std::cout << "i: " << i << std::endl;
                std::cout << "j: " << i << std::endl;
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
                if(board[i][j].alcanzable==1){
                   //aqui nunca entra porque alcanzable solo se cambia en tablero, no board//
                        board[i][j].sprite.setTexture(Zoogx);
                    }
                }else{
                 board[i][j].sprite.setTexture(texturabloqueazul);   
                }
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
            }else{
                if(board[i][j].free){
                board[i][j].sprite.setTexture(texturabloquerojo);
                if(board[i][j].alcanzable==1){
                   //aqui nunca entra porque alcanzable solo se cambia en tablero, no board//
                    std::cout<<"entramos en el alcanzable 1"<<std::endl;
                        board[i][j].sprite.setTexture(Zoogx);
                    }
                }else{
                    std::cout<<"entramos en el else "<<std::endl;
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
    
    if((posx>150 && posx<650)&&(posy>480 && posy<600)){
        //Crear funcion para que no se repita este calculo
        posx = (posx-150)/100;
        posy = (posy-480)/146;
    }
    Invocacion* mano = new Invocacion[5]; 
            mano= player1->getMano();
    Invocacion* mano2 = new Invocacion();
    for(int i=0; i<5;i++){
        if(mano[i].getJugar()==posx){ //si estoy clickando una carta
            mano2=&mano[i];
            return mano2;
        }
    }
    return NULL;
}

bool Tablero::isFree(int posx, int posy){
    posx = (posx-100)/50;
    posy = (posy-80)/50;
    return board[posx][posy].free;
}

/*DIBUJADO DE PLAYER*/
void Tablero::Mostrar_mano(sf::RenderWindow& window){
    for(int i=0;i<5;i++){
        if(!texturacarta.loadFromFile("assets/Sprites/carta.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        } 
        carta.setTexture(texturacarta);
        //mano[i].setCarta(carta);
        carta.setPosition((i*100)+150,480);
        window.draw(carta);
        //mano[i].setJugar(i);
        
    }
    
        
}
void Tablero::drawUnit(sf::RenderWindow& window){
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            
                if(player1->JugadaEn(i,j)->getNombre()=="Zoogx"){
                std::cout<<"hay criaturas porque nacho es dios"<<std::endl;
                board[i][j].sprite.setTexture(Zoogx);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
                window.draw(board[i][j].sprite);
                }
                if(player1->JugadaEn(i,j)->getNombre()=="Cthughax"){
                std::cout<<"hay criaturas porque nacho es dios"<<std::endl;
                board[i][j].sprite.setTexture(Cthughax);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
                window.draw(board[i][j].sprite);
                }
                
                if(player1->JugadaEn(i,j)->getNombre()=="Gugox"){
                std::cout<<"hay criaturas porque nacho es dios"<<std::endl;
                board[i][j].sprite.setTexture(Gugox);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
                window.draw(board[i][j].sprite);
                }
                
                if(player1->JugadaEn(i,j)->getNombre()=="Yigx"){
                std::cout<<"hay criaturas porque nacho es dios"<<std::endl;
                board[i][j].sprite.setTexture(Yigx);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
                window.draw(board[i][j].sprite);
                }
                
                if(player1->JugadaEn(i,j)->getNombre()=="Bokrugs"){
                std::cout<<"hay criaturas porque nacho es dios"<<std::endl;
                board[i][j].sprite.setTexture(Bokrugs);
                board[i][j].sprite.setPosition((i*50)+100,(j*50)+80);
                board[i][j].sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
                window.draw(board[i][j].sprite);
                }
        }
    }
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
    posx = (posx-100)/50;
    posy = (posy-80)/50;
    return board[posx][posy].alcanzable;
}
void Tablero::setFree(int posx,int posy,bool set){
    posx = (posx-100)/50;
    posy = (posy-80)/50;
    board[posx][posy].free=set;
}
bool Tablero::atackToPos(int fromx, int fromy,int gox, int goy){
    Invocacion* unidad = new Invocacion();
    Invocacion* unidad2 =new  Invocacion();
    gox = (gox-100)/50;
    goy = (goy-80)/50;
    /*fromx = (fromx-100)/50;
    fromy = (fromy-80)/50;*/
    unidad=player1->JugadaEn(fromx,fromy);//el que pega
    unidad2=player1->JugadaEn(gox,goy);
    unidad2->setVida(unidad2->getVida()-unidad->getAtaque());
    //hacia los dos lados
    if(unidad2->getVida()<=0){
       removeUnit(gox,goy,unidad2);
       return true;
    }
    return false;
}