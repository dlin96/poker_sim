#include "game.h"

Game::Game() : maxPlayers(5) {
    d = new Deck();
}

void Game::play() {
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
} 
void Game::createGame() {
    for(int i=0; i<maxPlayers; i++) {
       players.push_back(new Player());
    } 

}

void Game::flop() {
    for(int i=0; i<3; i++) {
        board[i] = d->deal();
    }
}

void Game::turn() {
    board[3] = d->deal();
}

void Game::river() {
    board[4] = d->deal();
}

Game::~Game() {
    for (size_t i=0; i<players.size(); i++) {
        delete players[i];
    }

    delete d;

    for (int i=0; i<5; i++) {
        if (board[i] != nullptr)
            delete board[i];
    }
}

// Game::addPlayer() {}
