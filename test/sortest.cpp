#include "player.h"
#include "card.h"
#include "./googletest/googletest/gtest/gtest.h"
#include <cassert>
#include <iostream>

int main() {

    Card* c = new Card(5, Card::Suit::HEARTS);
    Card* c1 = new Card(6, Card::Suit::HEARTS);

    std::cout<<"assert started"<<std::endl;
    assert(c < c1);
    std::cout<<"assert finished"<<std::endl;

    delete c;
    delete c1;

    Card* testBoard[7];  
    for (int i=0; i<7; i++) {
        testBoard[i] = new Card((i+5) % 7, Card::Suit::HEARTS);
    }

    for (int j=0; j<7; j++) {
        std::cout<<*(testBoard[j])<<std::endl;
    }

    Player::sort(testBoard);
 
    for (int j=0; j<7; j++) {
        std::cout<<*(testBoard[j])<<std::endl;
        delete testBoard[j];
    }

    return 0;
}
