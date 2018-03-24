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
    for(int i=0;i<20;i++){
        invo=new Invocacion[i];
    }
    
  ifstream fin;
  fin.open("baraja.txt"); 
 
  while(!fin.eof()){
  int id;
  
  
 
  fin >> id;
  cout << id << endl;
  //Mejor en el txt todos los paramaetros
  if(contador!=19){
  if(id==1){
       invo[contador]= Invocacion("Cthughax",1,1,1,commander,contador);
  }
  if(id==2){
       invo[contador]=Invocacion("Yigx",3,3,2,commander,contador);
  }
  if(id==3){
       invo[contador]=Invocacion("Zoogx",2,2,1,commander,contador);
  }
  if(id==4){
       invo[contador]=Invocacion("Gugox",5,4,4,commander,contador);
  }
  if(id==5){
       invo[contador]=Invocacion("Bokrugs",4,1,4,commander,contador);
  }
  if(id==6){
       invo[contador]=Invocacion("Orrys",7,7,2,commander,contador);
  }
  if(id==7){
       invo[contador]=Invocacion("Ahtuh",4,4,2,commander,contador);
  }
  if(id==8){
        invo[contador]=Invocacion("Blemiax",8,7,8,commander,contador);
  }
  if(id==9){
      invo[contador]=Invocacion("Shanx",6,3,6,commander,contador);
  }
  if(id==10){
       invo[contador]=Invocacion("Azathothx",10,12,12,commander,contador);
  }
  }
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
             mano[j]=invo[j];
            //carta.setTexture(textura3);
            //mano[j].setCarta(carta);
             
            mano[j].setJugar(j);;
        }
    }
   retrato.setTexture(textura);
   
}
bool Player::RellenarJugadas(Invocacion* jugada){
    Invocacion guardada = Invocacion();
    std::cout<< "La jugada es : "<< jugada->getNombre()<< std::endl;
    guardada=getMonstruo(jugada,1);
    for(int i=0;i<19;i++){
            std::cout<< "Entro en rellenar, soy: "<< guardada.getNombre()<< std::endl;
        if(jugadas[i].getExisto()==false){
            std::cout<< "VOy a ser metida, soy: "<< guardada.getNombre()<< std::endl; 
            jugadas[i]=guardada;
            jugadas[i].setExisto();
            std::cout<< "me metieron pendejo:  "<< jugadas[i].getNombre()<< std::endl;
            return true;
        }
    }
    return false;
}
Invocacion Player:: getMonstruo(Invocacion* monstruito, int donde){
    if(donde==0){//0 = a mazo
        for(int i=0;i<19;i++){
            if(invo[i].GetUnico()==monstruito->GetUnico()){
                return invo[i];
            }
        }
    }
    if(donde==1){// 1 = mano
        for(int i=0;i<5;i++){
            if(invo[i].GetUnico()==monstruito->GetUnico()){
                return mano[i];
            }
        }
    }
    if(donde==2){// 2 = jugadas
        for(int i=0;i<19;i++){
            if(invo[i].GetUnico()==monstruito->GetUnico()){
                return jugadas[i];
            }
        }
    }  
    Invocacion invo = Invocacion();
    return invo;
}
void Player:: eliminarMano(Invocacion* invo){
    
    for(int i=0;i<5;i++){
        if(mano[i].GetUnico()==invo->GetUnico()){
            if(i!=4){
                mano[i]=mano[i+1];
                for(int j=i+1;j<5;j++){
                    if(j!=4){
                        mano[j]=mano[j+1];
                    }
                }
            }
        }
    }
}
void Player:: eliminarJugadas(Invocacion* invo){// get unico creo que no sirve si miramos posiciones
    Invocacion* devolver;
    for(int i=0;i<20;i++){
        if(jugadas[i].GetUnico()==invo->GetUnico()){
            if(i!=20){
                devolver=&jugadas[i];
                devolver=NULL;
               /* if(jugadas[i]->NULL && i!=20){
                    jugadas[i]=jugadas[i+1];
                }*/
            }
        }
    }
}
 Invocacion* Player::  JugadaEn(int posx, int posy){
     Invocacion* retorno = new Invocacion();
     if((posx>100 && posx<700)&&(posy>80 && posy<475)){
        posx = (posx-100)/50;
        posy = (posy-80)/50;
    }
     for(int i=0;i<20;i++){
         if(jugadas[i].getX()==posx && jugadas[i].getY()==posy){
             retorno=&jugadas[i];
         }
     }
     return retorno;
 }
 bool Player:: estaJugadaEn(int posx, int posy){
     if((posx>100 && posx<700)&&(posy>80 && posy<475)){
        posx = (posx-100)/50;
        posy = (posy-80)/50;
    }
     for(int i=0;i<20;i++){
         if(jugadas[i].getX()==posx && jugadas[i].getY()==posy){
             std::cout<<"entro aqui porque no soy racista"<<std::endl;
             return true;
         }
     }
     return false;
 }

Player::~Player(){
}
