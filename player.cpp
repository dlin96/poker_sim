#include "player.h"
#include <iostream>

Player::Player() : hand {nullptr, nullptr}, cardCount(0) {}

void Player::addCard(Card* c) {
    if (cardCount >= 2) {
        std::cerr<<"This player already has 2 cards"<<std::endl;
        return;
    }

    hand[cardCount] = c;
    cardCount++;
}
