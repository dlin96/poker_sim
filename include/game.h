#include "deck.h"
#include "player.h"
#include <vector>
#include <ostream>

#ifndef GAME_H_
#define GAME_H_
class Game {

    Deck* d;
    public:
        int maxPlayers;
        std::vector<Card*> board;
        std::vector<Player*> players;
        Game(int maxPlayers);
        ~Game();
        void createGame();
        void addPlayer(Player*);
        poker_hands play();
        void flop();
        void turn();
        void river();
        friend std::ostream& operator<<(std::ostream& os, Game& g) {
            for(size_t i=0; i<g.players.size(); i++) {
                os<<"============================"<<std::endl;
                os<<*(g.players[i])<<std::endl;
                os<<"============================"<<std::endl;
            }

            os <<"============board==========="<<std::endl;
            for (int i=0; i<5; i++) {
                os <<*(g.board[i])<<std::endl;
            }

            os <<"============board==========="<<std::endl;
            return os;
        }

};
#endif
