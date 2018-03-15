#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    Game *p = new Game();

    p->run();
    
    delete p;
    return 0;
}
