#include "player.h"
#include <cassert>
#include <iostream>

void testPair() {
    Player* p = new Player();

    Card* board[7];
    board[0] = new Card(5, Card::Suit::SPADES);
    board[1] = new Card(7, Card::Suit::HEARTS);
    board[2] = new Card(8, Card::Suit::SPADES);
    board[3] = new Card(9, Card::Suit::DIAMONDS);
    board[4] = new Card(10, Card::Suit::SPADES);
    board[5] = new Card(5, Card::Suit::HEARTS);
    board[6] = new Card(6, Card::Suit::DIAMONDS);

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::PAIR); 
    std::cout<<"testPair: success"<<std::endl;

    return;

}

void testTwoPair() {
    Player* p = new Player();

    Card* board[7];
    board[0] = new Card(5, Card::Suit::SPADES);
    board[1] = new Card(6, Card::Suit::HEARTS);
    board[2] = new Card(8, Card::Suit::SPADES);
    board[3] = new Card(9, Card::Suit::DIAMONDS);
    board[4] = new Card(10, Card::Suit::SPADES);
    board[5] = new Card(5, Card::Suit::HEARTS);
    board[6] = new Card(6, Card::Suit::DIAMONDS);

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::TWOPAIR); 
    std::cout<<"testTwoPair: success"<<std::endl;

}

int main() {

    testPair();
    testTwoPair();
    return 0;
}
