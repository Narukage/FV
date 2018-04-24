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
Menu *p1=Menu::Instance();
Menu *p2=p1->Instance();
Menu &ref=*Menu::Instance();
                                 