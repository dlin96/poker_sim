#include "card.h"
#include <ostream>
#include <vector>
#include <algorithm>
#include <random>

#ifndef DECK_H_
#define DECK_H_
class Deck {
    private:
        std::vector<Card*> deck;
        std::vector<Card::Suit> suits = {Card::Suit::CLUBS, Card::Suit::DIAMONDS, Card::Suit::HEARTS, Card::Suit::SPADES};

    public:
        Deck();
        ~Deck();
        size_t remainingCards();
        void shuffle();
        void printSuits();
        Card* deal();
        void burn();

        friend std::ostream& operator<<(std::ostream& os, Deck& d) {
            for (Card* c : d.deck) {
                os << (*c) << std::endl;
            }
            
            os<<d.remainingCards()<<std::endl;
            
            return os;
        }      

};
#endif
