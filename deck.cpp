#include "deck.h"

#define DECK_SIZE 52
#define VALS 14

Deck::Deck() {
    for(int i=0; i<suits.size(); i++) {
        Card::Suit s = suits[i];
        for (int j=2; j <= VALS; j++) {
            Card* c = new Card(j, s);
            deck.push_back(c);
        }
    }
}

size_t Deck::remainingCards() {
    return deck.size();
}

void Deck::shuffle() {
    auto rng = std::default_random_engine{};
    std::shuffle(deck.begin(), deck.end(), rng);
}
