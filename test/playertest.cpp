#include "player.h"
#include "card.h"
#include <cassert>
#include <iostream>
#include <vector>

void testPair() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(5, Card::Suit::SPADES));
    board.push_back(new Card(11, Card::Suit::HEARTS));
    board.push_back(new Card(8, Card::Suit::SPADES));
    board.push_back(new Card(9, Card::Suit::DIAMONDS));
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(5, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::DIAMONDS));

    poker_hands ph = p->bestHand(board);
    assert(ph == poker_hands::PAIR); 
    std::cout<<"testPair: success"<<std::endl;

    for (Card* c : board)
        delete c;

    delete p;
}

void testTwoPair() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(5, Card::Suit::SPADES));
    board.push_back(new Card(6, Card::Suit::HEARTS));
    board.push_back(new Card(8, Card::Suit::SPADES));
    board.push_back(new Card(9, Card::Suit::DIAMONDS));
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(5, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::DIAMONDS));

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::TWOPAIR); 
    std::cout<<"testTwoPair: success"<<std::endl;

}

void testThreeOfAKind() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(5, Card::Suit::SPADES));
    board.push_back(new Card(5, Card::Suit::CLUBS));
    board.push_back(new Card(8, Card::Suit::SPADES));
    board.push_back(new Card(9, Card::Suit::DIAMONDS));
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(5, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::DIAMONDS));

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::THREEOFAKIND); 
    std::cout<<"testThreeOfAKind: success"<<std::endl;
}

void testFourOfAKind() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(5, Card::Suit::SPADES));
    board.push_back(new Card(5, Card::Suit::CLUBS));
    board.push_back(new Card(8, Card::Suit::SPADES));
    board.push_back(new Card(9, Card::Suit::DIAMONDS));
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(5, Card::Suit::HEARTS));
    board.push_back(new Card(5, Card::Suit::DIAMONDS));

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::FOUROFAKIND); 
    std::cout<<"testFourOfAKind: success"<<std::endl;
}

void testFullHouse() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(5, Card::Suit::SPADES));
    board.push_back(new Card(5, Card::Suit::CLUBS));
    board.push_back(new Card(6, Card::Suit::SPADES));
    board.push_back(new Card(9, Card::Suit::DIAMONDS));
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(5, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::DIAMONDS));

    poker_hands ph = p->bestHand(board);
    for (Card* c : board)
        delete c;

    delete p;
    assert(ph == poker_hands::FULLHS); 
    std::cout<<"testFullHouse: success"<<std::endl;
}

void testStraight() {
    Player* p = new Player();

    std::vector<Card*> board;

    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(11, Card::Suit::CLUBS));
    board.push_back(new Card(12, Card::Suit::SPADES));
    board.push_back(new Card(13, Card::Suit::DIAMONDS));
    board.push_back(new Card(14, Card::Suit::SPADES));
    board.push_back(new Card(8, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::DIAMONDS));

    poker_hands ph = p->bestHand(board);

    assert(ph == poker_hands::STRT); 
    std::cout<<"testStraight: success"<<std::endl;

    for (Card* c : board)
        delete c;

    delete p;
}

void testFlush() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(11, Card::Suit::CLUBS));
    board.push_back(new Card(8, Card::Suit::SPADES));
    board.push_back(new Card(13, Card::Suit::SPADES));
    board.push_back(new Card(14, Card::Suit::SPADES));
    board.push_back(new Card(8, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::SPADES));

    p->sort(board);
    poker_hands ph = p->bestHand(board);

    assert(ph == poker_hands::FLSH); 
    std::cout<<"testFlush: success"<<std::endl;

    for (Card* c : board)
        delete c;

    delete p;
}

void testStraightFlush() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(9, Card::Suit::SPADES));
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(8, Card::Suit::SPADES));
    board.push_back(new Card(11, Card::Suit::SPADES));
    board.push_back(new Card(12, Card::Suit::SPADES));
    board.push_back(new Card(8, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::DIAMONDS));

    p->sort(board);
    poker_hands ph = p->bestHand(board);

    assert(ph == poker_hands::STRTFLSH); 
    std::cout<<"testStraightFlush: success"<<std::endl;

    for (Card* c : board)
        delete c;

    delete p;
}

void testRoyal() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(14, Card::Suit::SPADES));
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(13, Card::Suit::SPADES));
    board.push_back(new Card(11, Card::Suit::SPADES));
    board.push_back(new Card(12, Card::Suit::SPADES));
    board.push_back(new Card(8, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::DIAMONDS));

    p->sort(board);
    poker_hands ph = p->bestHand(board);

    assert(ph == poker_hands::ROYAL); 
    std::cout<<"testRoyal: success"<<std::endl;

    for (Card* c : board)
        delete c;

    delete p;
}

// TODO: figure out the assertion here
void testSort() {
    Player* p = new Player();

    std::vector<Card*> board;
    board.push_back(new Card(5, Card::Suit::SPADES));
    board.push_back(new Card(7, Card::Suit::CLUBS));
    board.push_back(new Card(6, Card::Suit::SPADES));
    board.push_back(new Card(9, Card::Suit::DIAMONDS));
    board.push_back(new Card(10, Card::Suit::SPADES));
    board.push_back(new Card(8, Card::Suit::HEARTS));
    board.push_back(new Card(6, Card::Suit::DIAMONDS));

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
    testFlush();
    testStraightFlush();
    testRoyal();
    return 0;
}
