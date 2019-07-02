#include "card.h"
#include "pokerhands.h"
#include <ostream>
#include <vector>

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
        void sort(std::vector<Card*>&);
        int checkStraight(std::vector<Card*>, int);
        std::vector<Card*> showHand();
        // void clearHand();
        poker_hands bestHand(std::vector<Card*>);
        
        friend std::ostream& operator<<(std::ostream& os, Player& p) {
            for (Card* c : p.hand) {
                if (c != nullptr)
                    os << (*c) <<std::endl;
            }
            return os;
        }
            
};
#endif
