#include "Player.h"



Player::Player(int commander){
    vida=100;
    mana=10;
    manarest=10;

    
    if(commander==1){
         vida=100;
        comandante=Invocacion("P",0,5,vida,1);
        if(!textura.loadFromFile("assets/HUD/retrato1.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(0,0);
    }else{
         vida=100;
       comandante=Invocacion("E",0,8,vida,2);
        if(!textura.loadFromFile("assets/HUD/retrato2.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        retrato.setPosition(700,0);
    }
   // string s="s";
    for(int i=0;i<19;i++){
        invo[i]=Invocacion();
    }
    
     ifstream fin;
  fin.open("baraja.txt");
  while(!fin.eof()){
  int id;
  int contador=0;
  
 
  fin >> id;
  cout << id << endl;
  switch(id){
    case(1):
      invo[contador]=Invocacion("C",1,1,1,commander);
      contador++;
    break;
    case(2):
      invo[contador]=Invocacion("Y",3,3,2,commander);
      contador++;
    break;
    case(3):
      invo[contador]=Invocacion("Z",2,2,1,commander);
      contador++;
    break;
    case(4):
      invo[contador]=Invocacion("G",5,4,4,commander);
      contador++;
    break;
    case(5):
      invo[contador]=Invocacion("C",1,1,1,commander);
      contador++;
    break;
    case(6):
      invo[contador]=Invocacion("C",1,1,1,commander);
      contador++;
    break;
    case(7):
      invo[contador]=Invocacion("C",1,1,1,commander);
      contador++;
    break;
    
  }
  
  }
  fin.close();
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
            mano[j].setJugar(j);
            std::cout << "mano[j].setJugar: " << mano[j].getJugar() << std::endl;
        }
    }
   retrato.setTexture(textura);
   
}

Player::~Player(){
}
