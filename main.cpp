#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    Game::Instance()->run();

    return 0;
}
