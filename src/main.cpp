#include "deck.h"
#include "player.h"
#include "game.h"
#include "card.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
// #include <cassert>

std::string to_string(poker_hands& ph) {

	std::string hand;
	switch(static_cast<int>(ph)) {
		case 0:
			hand = "ROYAL STRAIGHT FLUSH";
			break;
		case 1:
			hand = "STRAIGHT FLUSH";
			break;
		case 2:
			hand = "FOUR OF A KIND";
			break;
		case 3:
			hand = "FULL HOUSE";
			break;
		case 4:
			hand = "FLUSH";
			break;
		case 5:
			hand = "STRAIGHT";
			break;
		case 6:
			hand = "THREE OF A KIND";
			break;
		case 7:
			hand = "TWO PAIR";
			break;
		case 8:
			hand = "PAIR";
			break;
		case 9:
			hand = "HIGH";
			break;
	}
	return hand;
}

int main() {

	std::ofstream results;
	results.open("results.txt", std::ios_base::app);
	std::unordered_map<std::string, int> count;

	for (int i=0; i<1000; i++) {
	    Game* g = new Game(2);
	    g->createGame();

    	poker_hands result = g->play();
	    // std::cout<<(*g)<<std::endl;
    	std::string res_str = to_string(result);

	    auto iter = count.find(res_str);
	    if (iter == count.end()) {
	    	count.insert({res_str, 1});
	    } else {
	    	iter->second++;
	    }

	    delete g;
    }

    for (auto iter = count.begin(); iter != count.end(); iter++) {
    	results << std::setw(20) << std::left << iter->first << std::setw(20) << std::left << iter->second << std::endl;
    }

    results.close();
}