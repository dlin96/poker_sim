#include "player.h"
#include <iostream>
#include <unordered_map>

#define SUITS 4

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
 * input: vector<Card*> cards - array of Card* comprised of the seven cards: 
 * the board + the player's hand
 * 
 * return: poker_hands 
 */

poker_hands Player::bestHand (std::vector<Card*> cards) {
    poker_hands bestHand = poker_hands::HIGH;   // the best hand is high so far
    std::unordered_map<int, int> rankCounts;    // holding counts of each rank
    int suitCount[4] = {0};


    // count frequency of each rank, checking for pairs, three of a kind etc. 
    for(int i=0; i<cards.size(); i++) {
        auto iter = rankCounts.find(cards[i]->value);
        if (iter != rankCounts.end()) {
            iter->second++;
        } else {
            rankCounts.insert({cards[i]->value, 1});
        }

        switch (cards[i]->s) {
            case Card::Suit::CLUBS:
                suitCount[0]++;
                break;
            case Card::Suit::DIAMONDS:
                suitCount[1]++;
                break;
            case Card::Suit::HEARTS:
                suitCount[2]++;
                break;
            case Card::Suit::SPADES:
                suitCount[3]++;
                break;
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
                    default:
                        break;
                }

                rank = std::max(rank, iter->first);
                break;
            case 3:
                if (bestHand == poker_hands::PAIR) {
                    bestHand = poker_hands::FULLHS;         
                } else if(bestHand > poker_hands::THREEOFAKIND) {
                    bestHand = poker_hands::THREEOFAKIND;
                }

                rank = std::max(iter->first, rank);
                break;
            case 4:
                bestHand = poker_hands::FOUROFAKIND;
                rank = iter->first;
                break;
        }
    }

    // check for straight
    sort(cards);

    int highCard = checkStraight(cards, 0);
    highCard = std::max(highCard, checkStraight(cards, 1));
    highCard = std::max(highCard, checkStraight(cards, 2));

    bool flush = false;
    bool straight = false;

    for (int i=0; i<SUITS; i++) {
        if (suitCount[i] >= 5) {
            bestHand = poker_hands::FLSH;
            flush = true;
        }
    }

    if (highCard != -1) {
        bestHand = std::min(bestHand, poker_hands::STRT);
        straight = true;
    }

    if (straight && flush) {
        if (highCard == 14) bestHand = poker_hands::ROYAL;
        else bestHand = std::min(bestHand, poker_hands::STRTFLSH);
    }

    return bestHand;

}

/*
 * method_name: checkStraight
 * params: vector<Card*> card - sorted array of Card* representing board + player's hand
 * return: index value to start 
*/
int Player::checkStraight(std::vector<Card*> cards, int start) {

    int currVal = cards[start]->value;
    int count = 1;
    for (int i=start+1; i<cards.size(); i++) {
        if (cards[i]->value - currVal == 1) {
            currVal = cards[i]->value;
            count++;

            if (count == 5) return currVal;
        }
    }

    return -1;
}

void Player::sort(std::vector<Card*> &cards) {

    int n = 7;
    bool swapped = false;
    do {
        swapped = false;
        for(int i=0; i<n-1; i++) {
            if (cards[i+1]->value < cards[i]->value) {
                Card* tmp = cards[i];
                cards[i] = cards[i+1];
                cards[i+1] = tmp;
                if (!swapped)
                    swapped = true;
            }
        }
    } while (swapped);
}

std::vector<Card*> Player::showHand() {

    std::vector<Card*> ret;
    ret.push_back(hand[0]);
    ret.push_back(hand[1]);

    return ret;
}

Player::~Player() {
    if (hand[0] != nullptr)
        delete hand[0];

    if (hand[1] != nullptr)
        delete hand[1];
}
