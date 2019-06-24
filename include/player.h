#include "card.h"
#include "pokerhands.h"
#include <ostream>

#ifndef PLAYER_H_
#define PLAYER_H_
class Player {

    private:
        Card* hand[2];
        int cardCount;

    public:
        Player();        
        ~Player();
        void addCard(Card*);
        void sort(Card**);
        // void showHand(Card**);
        poker_hands bestHand(Card**);
        
        friend std::ostream& operator<<(std::ostream& os, Player& p) {
            for (Card* c : p.hand) {
                if (c != nullptr)
                    os << (*c) <<std::endl;
            }
            return os;
        }
            
};
#endif
