#include "deck.h"
#include <iostream>

int main() {
    //Card* c = new Card(5, Card::Suit::HEARTS);
    //std::cout<<(*c)<<std::endl;

    Deck* d = new Deck();
    d->shuffle();
    std::cout<<(*d)<<std::endl;
}
