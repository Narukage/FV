#include "Menu.h"


Menu* Menu::pinstance=0;                     
Menu* Menu::Instance(){
    if(pinstance==0){
        pinstance=new Menu;
    }
    return pinstance;
}
Menu::Menu(){
    
}
Menu *m1=Menu::Instance();
Menu *m2=m1->Instance();
Menu &refm=*Menu::Instance();
