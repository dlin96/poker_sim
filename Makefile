CPPFLAGS = -Wall -Werror -std=c++14 -g -Og -I ./include

all: texas_holdem

texas_holdem: 
			g++ -o $@ src/card.cpp src/deck.cpp src/game.cpp src/main.cpp src/player.cpp $(CPPFLAGS)
