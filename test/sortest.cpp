#include "player.h"
#include "card.h"
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

void testThreeOfAKind() {
    Player* p = new Player();

    Card* board[7];
    board[0] = new Card(5, Card::Suit::SPADES);
    board[1] = new Card(5, Card::Suit::CLUBS);
    board[2] = new Card(8, Card::Suit::SPADES);
    board[3] = new Card(9, Card::Suit::DIAMONDS);
    board[4] = new Card(10, Card::Suit::SPADES);
    board[5] = new Card(5, Card::Suit::HEARTS);
    board[6] = new Card(6, Card::Suit::DIAMONDS);

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::THREEOFAKIND); 
    std::cout<<"testThreeOfAKind: success"<<std::endl;
}

void testFourOfAKind() {
    Player* p = new Player();

    Card* board[7];
    board[0] = new Card(5, Card::Suit::SPADES);
    board[1] = new Card(5, Card::Suit::CLUBS);
    board[2] = new Card(8, Card::Suit::SPADES);
    board[3] = new Card(9, Card::Suit::DIAMONDS);
    board[4] = new Card(10, Card::Suit::SPADES);
    board[5] = new Card(5, Card::Suit::HEARTS);
    board[6] = new Card(5, Card::Suit::DIAMONDS);

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::FOUROFAKIND); 
    std::cout<<"testFourOfAKind: success"<<std::endl;
}

void testFullHouse() {
    Player* p = new Player();

    Card* board[7];
    board[0] = new Card(5, Card::Suit::SPADES);
    board[1] = new Card(5, Card::Suit::CLUBS);
    board[2] = new Card(6, Card::Suit::SPADES);
    board[3] = new Card(9, Card::Suit::DIAMONDS);
    board[4] = new Card(10, Card::Suit::SPADES);
    board[5] = new Card(5, Card::Suit::HEARTS);
    board[6] = new Card(6, Card::Suit::DIAMONDS);

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::FULLHS); 
    std::cout<<"testFullHouse: success"<<std::endl;
}

void testStraight() {
    Player* p = new Player();

    Card* board[7];
    board[0] = new Card(5, Card::Suit::SPADES);
    board[1] = new Card(7, Card::Suit::CLUBS);
    board[2] = new Card(6, Card::Suit::SPADES);
    board[3] = new Card(9, Card::Suit::DIAMONDS);
    board[4] = new Card(10, Card::Suit::SPADES);
    board[5] = new Card(8, Card::Suit::HEARTS);
    board[6] = new Card(6, Card::Suit::DIAMONDS);

    int index = p->checkStraight(board);
    for (Card* c : board)
        delete c;

    delete p;

    std::cout<<"index: "<<index<<std::endl;
    assert(index == 2); 
    std::cout<<"testStraight: success"<<std::endl;
}

// TODO: figure out the assertion here
void testSort() {
    Player* p = new Player();

    Card* board[7];
    board[0] = new Card(5, Card::Suit::SPADES);
    board[1] = new Card(7, Card::Suit::CLUBS);
    board[2] = new Card(6, Card::Suit::SPADES);
    board[3] = new Card(9, Card::Suit::DIAMONDS);
    board[4] = new Card(10, Card::Suit::SPADES);
    board[5] = new Card(8, Card::Suit::HEARTS);
    board[6] = new Card(6, Card::Suit::DIAMONDS);

    p->sort(board);
    for (Card* c : board)
        delete c;

    delete p;
}

int main() {

    testPair();
    testTwoPair();
    testThreeOfAKind();
    testFourOfAKind();
    testFullHouse();
    testStraight();
    return 0;
}
