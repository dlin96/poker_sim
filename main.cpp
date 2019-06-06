#include "card.h"
#include <iostream>

int main() {
    Card* c = new Card(5, Card::HEARTS);
    std::cout<<c->value<<" "<<c->s<<std::endl;
    delete(c);
}
