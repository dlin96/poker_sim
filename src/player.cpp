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
/*
void Player::showHand(Card** board) {
    

} */

/*
 * method_name: bestHand()
 * 
 * purpose: method that returns the best possible hand given 
 * a player's hand and the board
 *
 * input: Card** cards - array of Card* comprised of the seven cards: 
 * the board + the player's hand
 * 
 * return: poker_hands 
 */
/*
poker_hands Player::bestHand (Card** cards) {
    poker_hands bestHand = poker_hands::HIGH;   // the best hand is high so far
    std::unordered_map<int, int> rankCounts;    // holding counts of each rank

    // count frequency of each rank, checking for pairs, three of a kind etc. 
    for(Card* c : cards) {
        auto iter = rankCounts.find(c->value);
        if (iter != rankCounts.end()) {
            iter->second++;
        } else {
            rankCounts.insert({c->value, 1});
        }
    }

    // check for PAIR, TWOPAIR, THREEOFAKIND, FULLHS, FOUROFAKIND
    int rank = -1;
    for(auto iter=rankCounts.begin(); iter != rankCounts.end(); iter++) {
        switch (iter->second) {
            case 2:
                switch (bestHand) {
                    case poker_hands::THREEOFAKIND:
                        bestHand = poker_hands::FULLHS;
                        break;
                    case poker_hands::PAIR:
                        bestHand = poker_hands::TWOPAIR;
                        break;
                    case poker_hands::HIGH:
                        bestHand = poker_hands::PAIR;
                        break;
                }

                rank = max(rank, iter->first);
                break;
            case 3:
                if (bestHand == poker_hands::PAIR) {
                    bestHand = poker_hands::FULLHS;         
                } else if(bestHand > poker_hands::THREEOFAKIND) {
                    bestHand = poker_hands::THREEOFAKIND;
                }

                rank = max(iter->first, rank);
                break;
            case 4:
                bestHand = poker_hands::FOUROFAKIND;
                rank = iter->first;
                break;
        }
    }

}
*/
void Player::sort(Card** cards) {
    std::cout<<"sort"<<std::endl;
    int n = 7;
    while (n >= 0) {
        for(int i=0; i<n; i++) {
            if (cards[i] > cards[i+1]) {
                Card* tmp = cards[i];
                cards[i] = cards[i+1];
                cards[i+1] = tmp;
                n = i+1;
            }
        }
    }
}

Player::~Player() {
    if (hand[0] != nullptr)
        delete hand[0];

    if (hand[1] != nullptr)
        delete hand[1];
}
