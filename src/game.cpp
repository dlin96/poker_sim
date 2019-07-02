#include "game.h"

Game::Game(int maxPlayers) {
    this->maxPlayers = maxPlayers;
}

poker_hands Game::play() {
    d = new Deck();
    d->shuffle();
    for (Player* p : players) {
        p->addCard(d->deal());
    }

    for (Player* p : players) {
        p->addCard(d->deal());
    }

    d->burn();
    flop();

    d->burn();
    turn();

    d->burn();
    river();

    poker_hands bestHand;
    for (Player* p : players) {
        std::vector<Card*> c = board;
        std::vector<Card*> h = p->showHand();
        c.push_back(h[0]);
        c.push_back(h[1]);
        bestHand = std::min(bestHand, p->bestHand(c));

    }

    delete d;
    d = nullptr;

    return bestHand;
} 

void Game::createGame() {
    for(int i=0; i<maxPlayers; i++) {
       players.push_back(new Player());
    } 

}

void Game::flop() {
    for(int i=0; i<3; i++) {
        board.push_back(d->deal());
    }
}

void Game::turn() {
    board.push_back(d->deal());
}

void Game::river() {
    board.push_back(d->deal());
}

Game::~Game() {

    // delete players from game
    for (size_t i=0; i<players.size(); i++) {
        delete players[i];
    }

    // delete deck
    if (d != nullptr)
        delete d;

    // delete cards on board
    for (int i=0; i<board.size(); i++) {
        if (board[i] != nullptr)
            delete board[i];
    }
}

// Game::addPlayer() {}
