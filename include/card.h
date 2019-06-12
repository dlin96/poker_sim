#include <ostream>
#include <string>

#ifndef CARD_H
#define CARD_H
class Card {

    public:
        int value;
        enum class Suit {CLUBS, DIAMONDS, HEARTS, SPADES};
        Suit s;
        Card (int, Suit);
        friend std::ostream& operator<<(std::ostream& os, const Card& c) {
            std::string suit;
            switch (c.s) {
                case Suit::CLUBS:
                    suit = "Clubs";
                    break;
                case Suit::DIAMONDS:
                    suit = "Diamonds";
                    break;
                case Suit::HEARTS:
                    suit = "Hearts";
                    break;
                case Suit::SPADES:
                    suit = "Spades";
                    break;
            }

            os<<"val: "<<c.value<<" "<<"suit: "<<suit;
            return os;
        }
};
#endif
