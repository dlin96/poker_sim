#include "deck.h"
#include "player.h"
#include <vector>

class Game {
    private: 
    
    public:
        int maxPlayers;
        std::vector<Player*> players;
        void createGame();
        void addPlayer(Player*);
        

};
