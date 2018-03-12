#include "Baraja.h"

Baraja::Baraja() {
    comandante =false;
    string s="s";
    for(int i=0;i<19;i++){
        invo[i]=Invocacion();
    }
    invo[0]=Invocacion("C",1,1,1,false);
    invo[1]=Invocacion("y",3,3,2,false);
    invo[2]=Invocacion("Z",2,2,1,false);
    invo[3]=Invocacion("g",5,4,5,false);
    for(int j=0;j<2;j++){
         mano[j]=invo[j];
    }
}

/* Baraja::Baraja(string mazo) {
   string leido;
    string aux, auxn, auxc, auxa, auxv;
    ifstream ficheroE;
    int control=0;
    
    ficheroE.open(mazo.c_str(), ios::in);
    if(ficheroE.is_open()){
        while(! ficheroE.eof()){
            getline(ficheroE, leido);
            for(int i=0;i<leido.size();i++){
                if(i==0){
                    aux=leido[i];
                }
               if(leido[i]!='/'){
                   aux=aux+leido[i];
               } 
                if(leido[i]=='/'){
                    if(control==0){
                        auxn=aux;
                        control++;
                        aux="";
                    }
                    if(control==1){
                        auxc=aux;
                        control++;
                        aux="";
                    }
                    if(control==2){
                        auxa=aux;
                        control++;
                        aux="";
                    }
                    if(control==3){
                        auxv=aux;
                        control=0;
                        aux="";
                    }
                }
            }
            invo
            
        }
    }
}*/

Baraja::~Baraja() {
}
/*void Baraja::Mano(bool com,Invocacion carta){
    if(com == false){
        
    }
    else{
        
    }
}*/

