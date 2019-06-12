#include "deck.h"
#include "player.h"
#include "game.h"
#include <iostream>

int main() {
    Game* g = new Game();
    g->createGame();
    g->play();
    std::cout<<(*g)<<std::endl;
    
    delete g;
    g = nullptr;
}
