#include "deck.h"
#include "player.h"
#include <iostream>

int main() {
    //Card* c = new Card(5, Card::Suit::HEARTS);
    //std::cout<<(*c)<<std::endl;

    Deck* d = new Deck();
    d->shuffle();
    std::cout<<(*d)<<std::endl;

    Player* p = new Player();
    p->addCard(d->deal());
    p->addCard(d->deal());

    std::cout<<(*d)<<std::endl;
    std::cout<<"============================================"<<std::endl;
    std::cout<<(*p)<<std::endl;
}
