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
        inline bool operator <(const Card& c) {
            return value < c.value;
        }
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

            std::string rank;
            switch(c.value) {
                case 11:
                    rank = "Jack";
                    break;
                case 12:
                    rank = "Queen";
                    break;
                case 13: 
                    rank = "King";
                    break;
                case 14:
                    rank = "Ace";
                    break;
                default:
                    rank = std::to_string(c.value);
                    break;
            }

            os<<"val: "<<rank<<" "<<"suit: "<<suit;
            return os;
        }
};
#endif
