#include "Player.h"



Player::Player(int commander){
    vida=100;
    mana=10;
    manarest=10;

    
    if(commander==1){
         vida=100;
        comandante=Invocacion("P",0,5,vida,1,-1);
        if(!textura.loadFromFile("assets/HUD/retrato1.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(0,0);
    }else{
         vida=100;
       comandante=Invocacion("E",0,8,vida,2,-2);
        if(!textura.loadFromFile("assets/HUD/retrato2.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(700,0);
    }
   // string s="s";
    /*for(int i=0;i<20;i++){
        invo=new Invocacion[i];
    }*/
    
  ifstream fin;
  fin.open("baraja.txt"); 
 
  while(!fin.eof()){
  int id;
  
 
  fin >> id;
  cout << id << endl;
  //Mejor en el txt todos los paramaetros
  if(contador!=19){
  if(id==1){
       insertar[contador]= Invocacion("Cthughax",1,1,1,commander,contador);
       invo.push_back(&insertar[contador]);
  }
  if(id==2){
      insertar[contador]=Invocacion("Yigx",3,3,2,commander,contador);
       invo.push_back(&insertar[contador]);
  }
  if(id==3){
       insertar[contador]=Invocacion("Zoogx",2,2,1,commander,contador);

       invo.push_back(&insertar[contador]);
  }
  if(id==4){
       insertar[contador]=Invocacion("Gugox",5,4,4,commander,contador);

       invo.push_back(&insertar[contador]);
  }
  if(id==5){
       insertar[contador]=Invocacion("Bokrugs",4,1,4,commander,contador);

       invo.push_back(&insertar[contador]);
  }
  if(id==6){
       insertar[contador]=Invocacion("Orrys",7,7,2,commander,contador);

       invo.push_back(&insertar[contador]);
  }
  if(id==7){
       insertar[contador]=Invocacion("Ahtuh",4,4,2,commander,contador);
       invo.push_back(&insertar[contador]);
  }
  if(id==8){
        insertar[contador]=Invocacion("Blemiax",8,7,8,commander,contador);

        invo.push_back(&insertar[contador]);
  }
  if(id==9){
      insertar[contador]=Invocacion("Shanx",6,3,6,commander,contador);

      invo.push_back(&insertar[contador]);
  }
  if(id==10){
       insertar[contador]=Invocacion("Azathothx",10,12,12,commander,contador);

       invo.push_back(&insertar[contador]);
  }
  }
//std::cout<<"Posicion: "<<contador<<"Como me llamo: "<<invo.at(contador)->getNombre()<<std::endl;
 contador++;

  }
  fin.close();
  /*for(int x=0;x<19;x++){
       std::cout << "Soy el monstruo de: " << x<< ", con nombre: "<< invo[x].getNombre() << std::endl;
  }*/
    /*invo[0]=Invocacion("C",1,1,1,commander);
    invo[1]=Invocacion("y",3,3,2,commander);
    invo[2]=Invocacion("Z",2,2,1,commander);
    invo[3]=Invocacion("g",5,4,5,commander);
    invo[4]=Invocacion("C",1,1,1,commander);
    invo[5]=Invocacion("y",3,3,2,commander);
    invo[6]=Invocacion("Z",2,2,1,commander);
    invo[7]=Invocacion("g",5,4,5,commander);
    invo[8]=Invocacion("C",1,1,1,commander);
    invo[9]=Invocacion("y",3,3,2,commander);
    invo[10]=Invocacion("Z",2,2,1,commander);
    invo[11]=Invocacion("g",5,4,5,commander);
    invo[12]=Invocacion("C",1,1,1,commander);
    invo[13]=Invocacion("y",3,3,2,commander);
    invo[14]=Invocacion("Z",2,2,1,commander);
    invo[15]=Invocacion("g",5,4,5,commander);
    invo[16]=Invocacion("C",1,1,1,commander);
    invo[17]=Invocacion("y",3,3,2,commander);
    invo[18]=Invocacion("Z",2,2,1,commander);
    invo[19]=Invocacion("g",5,4,5,commander);
    */
    
    
    /*if(!textura3.loadFromFile("assets/Sprites/carta.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        } */
    if(commander==1){
        for(int j=0;j<5;j++){
            std::cout<<"Posicion: "<<j<<"Como me llamo: "<<invo.at(j)->getNombre()<<std::endl;
             mano.push_back(invo.at(j));
            //carta.setTexture(textura3);
            //mano[j].setCarta(carta);
             
            mano.at(j)->setJugar(j);
            std::cout<<"JUGARLA VALE : "<<mano.at(j)->getJugar()<<std::endl;
            std::cout<<"Carta en mano nombre : "<<mano.at(j)->getNombre()<<std::endl;
        }
    }
   retrato.setTexture(textura);
   
}
bool Player::RellenarJugadas(Invocacion* jugada){
    std::cout<< "La jugada es : "<< jugada->getNombre()<< std::endl;
    int i=0;
      vector<Invocacion*>::iterator it3;
    if(jugada->getExisto()==false){
        jugada->setExisto();
         std::cout<< "Existo es : "<< jugada->getExisto()<< std::endl;
        jugadas.push_back(jugada);
         for(it3=jugadas.begin();it3!=jugadas.end();++it3){
            std::cout<< "SOY  : "<< jugadas.at(i)->getNombre()<< std::endl;
            i++;
         }
         //std::cout<< "Existo es : "<< jugadas.a<< std::endl;
        
        return true;
    }
    return false;
}
Invocacion* Player:: getMonstruo(Invocacion* monstruito, int donde){
    Invocacion* retorno = new Invocacion();
     vector<Invocacion*>::iterator it3;
     int i = 0;
    if(donde==0){//0 = a mazo
        for(it3=invo.begin();it3!=invo.end();++it3){
            if(invo.at(i)->GetUnico()==monstruito->GetUnico()){
                retorno = invo.at(i);
            }
            i++;
        }
    }
     i=0;
    if(donde==1){// 1 = mano
        for(it3=mano.begin();it3!=mano.end();++it3){
            if(mano.at(i)->GetUnico()==monstruito->GetUnico()){
                retorno = mano.at(i);
            }
            i++;
        }
    }
     i=0;
    if(donde==2){// 2 = jugadas
        for(it3=jugadas.begin();it3!=jugadas.end();++it3){
            if(jugadas.at(i)->GetUnico()==monstruito->GetUnico()){
                retorno = jugadas.at(i);
            }
            i++;
        }
    }  
    return retorno;
}
void Player:: eliminarMano(Invocacion* invo){   
    vector<Invocacion*>::iterator it3;
    int i=0;
    for(it3=mano.begin();it3!=mano.end();++it3){
        if(i<mano.size()&&mano.at(i)->GetUnico()==invo->GetUnico()){
         
            std::cout<< "I vale : "<< i<< std::endl;
            if(i==4){
                mano.pop_back();
                 
            }
            else{
                    mano.erase(it3);    
                    std::cout<< "SOY un nigga  : "<< mano.at(i)->getNombre()<< std::endl;
            }
                 
        }
        i++;
    }
    /*i=0;
    for(it3=mano.begin();it3!=mano.end();++it3){
        if(i<mano.size()){
            mano.at(i)->setJugar(i);
            i++;
        }
    }*/
}
void Player:: eliminarJugadas(Invocacion* invo){// get unico creo que no sirve si miramos posiciones
   vector<Invocacion*>::iterator it3;
    int i=0;
    for(it3=jugadas.begin();it3!=jugadas.end();++it3){
        if(jugadas.at(i)->GetUnico()==invo->GetUnico()){
                    jugadas.erase(it3);        
                    
        }
        i++;
    }
}
 Invocacion* Player::  JugadaEn(int posx, int posy){
     Invocacion* retorno = new Invocacion();
     if((posx>100 && posx<700)&&(posy>80 && posy<475)){
        posx = (posx-100)/50;
        posy = (posy-80)/50;
    }
    vector<Invocacion*>::iterator it3;
                 int i=0;
     for(it3=jugadas.begin();it3!=jugadas.end();++it3){
         if(i<jugadas.size()&&jugadas.at(i)->getX()==posx && jugadas.at(i)->getY()==posy){
             retorno=jugadas.at(i);
         }
         i++;
     }
     return retorno;
 }

Player::~Player(){
}
